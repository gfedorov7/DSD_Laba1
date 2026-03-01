#include <iostream>
#include <ctime>
#include "cstdlib"
#include "SetLab1_2_Fedorov.h"

int main() {
    setlocale(LC_ALL, "Russian");

    int min = 6, max = 9;
    int minValue = 10, maxValue = 100;

    std::srand(std::time(nullptr));
    int count = min + std::rand() % (max - min + 1);
    int startValue = minValue + std::rand() % (maxValue - minValue + 1);
    int endValue = startValue + std::rand() % (maxValue - startValue + 1);

    std::cout << "Создано множество A - ";
    Set* set = F5_create(count, startValue, endValue);
    std::cout << "Мощность множества А - " << F6_calculatePower(set) << std::endl;
    std::cout << "Вывод множества A - " << F7_out(set, ",") << std::endl;
    set = F8_clear(set);
    std::cout << "Мощность множества А - " << F6_calculatePower(set) << std::endl;
    std::cout << "Вывод множества A - " << F7_out(set, ",") << std::endl;
}