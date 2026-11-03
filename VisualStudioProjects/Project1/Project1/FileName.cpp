#include <windows.h>
#include <iostream>

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int sum = 0;

    for(int number = 1; number <= 10; number++)
    {
        sum += number;
        std::cout << "Число: " << number
            << ", сумма: " << sum << '\n';
    }

    std::cout << "Итоговая сумма: " << sum << '\n';

    return 0;
}