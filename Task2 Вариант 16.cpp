#include <iostream>
#include <cmath> 
using namespace std;

/**
 * @brief считывает значение радианов с клавиатуры с проверкой ввода
 * @return введенное значение в радианах
 */
double getRadians();

/**
 * @brief преобразует радианы в градусы, минуты и секунды
 * @param radians - угол в радианах
 * @param degrees - указатель на переменную для хранения градусов
 * @param minutes - указатель на переменную для хранения минут
 * @param seconds - указатель на переменную для хранения секунд
 */
void convertRadiansToDMS(double radians, int &degrees, int &minutes, double &seconds);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1 
 */
int main()
{
    cout << "Введите угол в радианах: ";
    double radians = getRadians();

    int degrees;
    int minutes;
    double seconds;

    convertRadiansToDMS(radians, degrees, minutes, seconds);

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
        cout << "Неверное значение. Пожалуйста введите число." << endl;
        abort();
    }
    return value;
}

void convertRadiansToDMS(double radians, int &degrees, int &minutes, double &seconds)
{
    double total_degrees = radians * (180.0 / M_PI);
    degrees = static_cast<int>(total_degrees);
    
    double fractional_degrees = total_degrees - degrees;
    minutes = static_cast<int>(fractional_degrees * 60);
    
    double fractional_minutes = fractional_degrees * 60 - minutes;
    seconds = fractional_minutes * 60;
    seconds = static_cast<int>(seconds);
}