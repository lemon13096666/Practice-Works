#include <iostream>
#include <windows.h>
#include <stdexcept>
#include <stdio.h>
#include <time.h>
using namespace std;
int main() {
    time_t start, end;

    time(&start);
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int a;
    int sum = 0;
    cout << "Введите число: " << endl;
    cin >> a;
    try {
        if(a <= 0) {
            throw invalid_argument("Ошибка: Число должно быть больше 0.");
        }
        cout << "Четные числа: \n";
        for(int i = 1; i < a; ++i) {
            if(i % 2 == 0) {
                cout << i << " " << endl;
                sum += i;
            }
        }
        cout << "Сумма четных чисел: " << sum << endl;
    }
    catch(const invalid_argument& e) {
        cout << e.what() << endl;
    }
    time(&end);
    double seconds = difftime(end, start);
    printf("The time: %f seconds\n", seconds);
}
