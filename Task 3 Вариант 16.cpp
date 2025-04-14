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

int main()
{
    cout << "Enter xn (-2): ";
    double xstart = -2; 
    cout << "Enter xk (0): ";
    double xend = 0; 
    cout << "Enter step (0.2): ";
    double step = 0.2; 
    checkStep(step); 

    for (double x = xstart; x <= xend; x += step)
    {
        cout << "x = " << x; 
        if (isDomain(x)) 
        {
            double y = getY(x); 
            if (y != -1) 
            {
                cout << " y = " << y << endl;
            }
            else
            {
                cout << " not in domain" << endl; 
            }
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
    double value;
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
    if (denominator <= 0) 
    {
        return -1; 
    }
    
    double result = log(1 / denominator); 
    return result; 
}

bool isDomain(const double x)
{
    return !(abs(2 * x + x * x) <= std::numeric_limits<double>::epsilon()); // Проверяем допустимость значения x
}