#include <iostream>
#include <windows.h>
#include "Kinematics.h"

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    cout << "=== Расчет кинематических параметров ===" << endl;

    double s = 100.0;
    double t = 5.0;
    cout << "Скорость (s=100, t=5): " << Kinematics::velocity(s, t) << " м/с" << endl;
    cout << "Пройденный путь (v=20, t=5): " << Kinematics::distance(20.0, t) << " м" << endl;
    cout << "Время (s=100, v=20): " << Kinematics::time(s, 20.0) << " с" << endl;
    cout << "Ускорение (v0=0, v=20, t=5): " << Kinematics::acceleration(0.0, 20.0, t) << " м/с^2" << endl;

    cout << "\nНажмите Enter для выхода...";
    cin.get();
    return 0;
}