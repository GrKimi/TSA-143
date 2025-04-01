#include <iostream>
#include <cmath> 
using namespace std;

/**
 * @brief считывает значение радианов с клавиатуры с проверкой ввода
 * @return введенное значение в радианах
 */
double getRadians();

/**
 * @brief преобразует радианы в градусы
 * @param radians - угол в радианах
 * @return угол в градусах
 */
double toDegrees(const double radians);

/**
 * @brief извлекает целую часть градусов
 * @param total_degrees - общее количество градусов
 * @return целая часть градусов
 */
int getDegrees(double total_degrees);

/**
 * @brief извлекает минуты из градусов
 * @param total_degrees - общее количество градусов
 * @return минуты
 */
int getMinutes(double total_degrees);

/**
 * @brief извлекает секунды из градусов
 * @param total_degrees - общее количество градусов
 * @return секунды
 */
double getSeconds(double total_degrees);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1 
 */
int main()
{
    cout << "Введите угол в радианах: ";
    double radians = getRadians();

    double total_degrees = toDegrees(radians);
    int degrees = getDegrees(total_degrees);
    int minutes = getMinutes(total_degrees);
    double seconds = getSeconds(total_degrees);

    cout << "Угол в градусах, минутах и секундах : "
         << degrees << "° " << minutes << "' " << seconds << "''" << endl;

    return 0;
}

double getRadians()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout << "Неверное значение. Пожалуйста, введите число." << endl;
        abort();
    }
    return value;
}

double toDegrees(const double radians)
{
    return radians * (180.0 / M_PI);
}

int getDegrees(double total_degrees)
{
    return static_cast<int>(total_degrees);
}

int getMinutes(double total_degrees)
{
    double fractional_degrees = total_degrees - getDegrees(total_degrees);
    return static_cast<int>(fractional_degrees * 60);
}

double getSeconds(double total_degrees)
{
    double fractional_degrees = total_degrees - getDegrees(total_degrees);
    double fractional_minutes = fractional_degrees * 60 - getMinutes(total_degrees);
    return fractional_minutes * 60;
}
