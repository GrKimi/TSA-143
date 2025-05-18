#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

/**
 * @brief Считывает целое значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 * @exception Завершает программу при ошибке ввода
 */
int getValue();

/**
 * @brief Получает и проверяет размер массива
 * @return Размер массива
 */
size_t getSize();

/**
 * @brief Проверяет корректность размера массива
 * @param n Проверяемое значение размера
 */
void checkN(const int n);

/**
 * @brief Создает новый двумерный массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @return Указатель на созданный массив
 */
int** getNewArray(const size_t m, const size_t n);

/**
 * @brief Выводит двумерный массив на экран
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 */
void printArray(int** array, const size_t m, const size_t n);

/**
 * @brief Заполняет массив значениями вручную
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 */
void fillArray(int** array, const size_t m, const size_t n);

/**
 * @brief Заполняет массив случайными числами в заданном диапазоне
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @param start Начало диапазона случайных чисел
 * @param end Конец диапазона случайных чисел
 */
void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end);

/**
 * @brief Освобождает память, занятую двумерным массивом
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 */
void deleteArray(int** array, const size_t m, const size_t n);

/**
 * @brief Заменяет четные элементы массива нулями
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 */
void replaceEvenWithZero(int** array, const size_t m, const size_t n);

/**
 * @brief Находит минимальное значение в строке массива
 * @param row Указатель на строку массива
 * @param n Количество элементов в строке
 * @return Минимальное значение в строке
 */
int findMinInRow(int* row, const size_t n);

/**
 * @brief Вставляет строки (1,2,3...) после строк, содержащих минимальное значение
 * @param array Указатель на исходный массив
 * @param m Ссылка на количество строк (изменяется при вставке)
 * @param n Количество столбцов
 * @return Указатель на новый массив
 */
int** insertRowsAfterMin(int** array, size_t& m, const size_t n);

/**
 * @brief Перечисление для выбора способа заполнения массива
 * @param RANDOM Заполнение случайными числами (значение 5)
 * @param MANUAL Ручное заполнение (значение 6)
 */
enum {RANDOM = 5, MANUAL = 6};

/**
 * @brief Точка входа в программу
 * @return 0 при успешном выполнении
 */
int main()
{
    cout << "Enter m: ";
    size_t m = getSize();
    cout << "Enter n: ";
    size_t n = getSize();
    
    int** array = getNewArray(m, n);
    
    cout << "Enter the way to fill array: " << (int)MANUAL <<
        " to fill manually, " << (int)RANDOM << " to fill randomly: ";
    int choice = getValue();
    
    int start = 0, end = 0;
    switch (choice)
    {    
        case RANDOM:
            cout << "Enter start: ";
            start = getValue();
            cout << "Enter end: ";
            end = getValue();
            fillRandom(array, m, n, start, end);
            break;
        case MANUAL:
            fillArray(array, m, n);
            break;
        default:
            cout << "Error" << endl;
            deleteArray(array, m, n);
            return 1;
    }
    
    cout << "\nOriginal array:" << endl;
    printArray(array, m, n);
    
    // 1. Заменить четные элементы каждой строки нулем
    replaceEvenWithZero(array, m, n);
    cout << "\nArray after replacing even elements with zero:" << endl;
    printArray(array, m, n);
    
    // 2. Вставить строки после строк с минимальным значением
    array = insertRowsAfterMin(array, m, n);
    cout << "\nArray after inserting rows:" << endl;
    printArray(array, m, n);
    
    deleteArray(array, m, n);
    return 0;
}

// Реализации функций

void replaceEvenWithZero(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (array[i][j] % 2 == 0) // Если элемент четный
            {
                array[i][j] = 0;
            }
        }
    }
}

int findMinInRow(int* row, const size_t n)
{
    int minVal = row[0];
    for (size_t j = 1; j < n; j++)
    {
        if (row[j] < minVal)
        {
            minVal = row[j];
        }
    }
    return minVal;
}

int** insertRowsAfterMin(int** array, size_t& m, const size_t n)
{
    // Сначала подсчитаем, сколько строк нужно вставить
    size_t insertCount = 0;
    for (size_t i = 0; i < m; i++)
    {
        int minInRow = findMinInRow(array[i], n);
        // Проверяем, содержит ли строка минимальное значение
        bool containsMin = false;
        for (size_t j = 0; j < n; j++)
        {
            if (array[i][j] == minInRow)
            {
                containsMin = true;
                break;
            }
        }
        if (containsMin) insertCount++;
    }
    
    if (insertCount == 0) return array; // Нет строк для вставки
    
    // Создаем новый массив с дополнительными строками
    size_t newM = m + insertCount;
    int** newArray = getNewArray(newM, n);
    
    size_t newRow = 0;
    for (size_t i = 0; i < m; i++)
    {
        // Копируем текущую строку
        for (size_t j = 0; j < n; j++)
        {
            newArray[newRow][j] = array[i][j];
        }
        newRow++;
        
        int minInRow = findMinInRow(array[i], n);
        // Проверяем, содержит ли строка минимальное значение
        bool containsMin = false;
        for (size_t j = 0; j < n; j++)
        {
            if (array[i][j] == minInRow)
            {
                containsMin = true;
                break;
            }
        }
        
        // Если содержит, вставляем новую строку
        if (containsMin)
        {
            for (size_t j = 0; j < n; j++)
            {
                newArray[newRow][j] = j + 1; // Заполняем значениями 1, 2, 3, ..., n
            }
            newRow++;
        }
    }
    
    // Удаляем старый массив
    deleteArray(array, m, n);
    
    // Обновляем количество строк
    m = newM;
    
    return newArray;
}

// Остальные функции остаются такими же, как в вашем примере

int getValue()
{
    int value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Error" << endl;
        abort();
    }
    return value;
}

size_t getSize()
{
    int n = getValue();
    checkN(n);
    return (size_t)n;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Error" << endl;
        abort();
    }
}

int** getNewArray(const size_t m, const size_t n)
{
    int** array = new int*[m];
    for (size_t i = 0; i < m; i++)
    {
        array[i] = new int[n];
    }
    return array;
}

void printArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << setw(6) << array[i][j];
        }
        cout << endl;
    }
}

void fillArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << "Enter array[" << i << "," << j << "] = ";
            array[i][j] = getValue();
        }
    }
}

void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end)
{
    srand(time(0));
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            array[i][j] = rand() % (end - start + 1) + start;
        }
    }
}

void deleteArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}
