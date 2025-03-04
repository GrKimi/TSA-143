#include <iostream>
#include <cmath>
using namespace std;

/**
 *@brief - Функция для вычисления A по заданному уравнению 
 *@param x - значение переменной x
 *@param y - значение переменной y
 *@param z - значение переменной z 
 *@return - возвращает рассчитанное значение
 */
double getA(const double x, const double y, const double z );

/**
 *@brief - Функция для вычисления B по заданному уравнению 
 *@param x - значение переменной x
 *@param y - значение переменной y 
 *@param z - значение переменной z
 *@return - возвращает рассчитанное значение
 */
 
 double getB(const double x, const double y, const double z);
/**
 *@brief - Точка входа в программу 
 *@return - возвращает 0, если программа выполнена корректно
 */
int main()

{
    const double x = 0.29;
    const double y = 3.7;
    const double z = -1;
    cout<<"a = "<<getA(x,y,z)<<endl;
    cout<<"b = "<<getB(x,y,z);
    return 0;
}

double getA(const double x, const double y, const double z )
{
    return 3 * pow(x,y) * log(y) + exp(z*x);
}

double getB(const double x, const double y, const double z)
{
    return (fabs(2*y*z))/(pow(sin(x), 2)) - (pow(x,2)/3);
}
