#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    const double a = 0.9;
    const double b = 12.5;
    double x = 0.0;
    cout << "Вычисление значения выражения Y" << endl;
    cout << "Параметры: a = " << a << ", b = " << b << endl;
    cout << "Введите значение x (x > 0): ";
    cin >> x;
    if(x <= 0.0)
    {
        cout << "Ошибка: x должен быть строго положительным!" << endl;
        return 1;
    }
    double part1 = (cos(x - 1.0) - pow(b, -3.0)) / pow(x, 1.6);
    double part2 = (pow(a, 2.0 * x) + b) * log(a);
    double Y = part1 + part2;
    cout << fixed << setprecision(5);
    cout << "Результат Y(x = " << x << ") = " << Y << endl;
    return 0;
}
