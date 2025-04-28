#include <iostream>
#include <limits>
#include <cmath> 

using namespace std;

/**
 * @brief Считывает значение с клавиатуры и проверяет на корректность ввода.
 * @return Значение типа double, введенное пользователем.
 */
double getValue();

/**
 * @brief Проверяет, является ли шаг для итерации положительным.
 * @param step - шаг для итерации.
 */
void checkStep(const double step);

/**
 * @brief Вычисляет значение функции y для заданного x.
 * @param x - значение, для которого вычисляется функция y.
 * @return Значение функции y или -1 в случае ошибки.
 */
double getY(const double x);

/**
 * @brief Проверяет, находится ли значение x в допустимой области для вычисления функции y.
 * @param x - значение, которое проверяется на допустимость.
 * @return true, если x находится в допустимой области; false в противном случае.
 */
bool isDomain(const double x);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1 
 */
int main()
{
    cout << "Enter xn: ";
    double xstart = getValue();
    cout << "Enter xk: ";
    double xend = getValue();
    cout << "Enter step: ";
    double step = getValue();
    checkStep(step);

    
    for (double x = xstart; x < xend + step; x += step)
    {
        cout << "x = " << x;
        if (isDomain(x))
        {
            cout << " y = " << getY(x) << endl;
        }
        else
        {
            cout << " not in domain" << endl;
        }
    }
    
    return 0;
}

double getValue()
{
    double value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Incorrect value" << endl;
        abort();
    }
    return value;
}

void checkStep(const double step)
{
    if (step <= 0)
    {
        cout << "Error value" << endl;
        abort();
    }
}

double getY(const double x)
{
    double denominator = 2 * x + x * x; 
    return log(1 / denominator); 
}

bool isDomain(const double x)
{
    return !(abs(2 * x + x * x) <= std::numeric_limits<double>::epsilon());
}
