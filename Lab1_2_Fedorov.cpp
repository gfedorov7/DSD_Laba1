#include <iostream>
#include <ctime>
#include "cstdlib"
#include "SetLab1_2_Fedorov.h"

int main() {
    setlocale(LC_ALL, "Russian");

    int min = 6, max = 9;
    int minValue = 1, maxValue = 10000;

    std::srand(std::time(nullptr));
    int count = min + std::rand() % (max - min + 1);
    int startValue = minValue + std::rand() % (maxValue - minValue + 1);
    int endValue = minValue + std::rand() % (maxValue - minValue + 1);

    std::cout << "Создано множество A - ";
    Set* set = create(count, startValue, endValue);
    std::cout << "Мощность множества А - " << calculatePower(set) << std::endl;
    std::cout << "Вывод множества A - " << out(set, ",") << std::endl;
    set = clear(set);
    std::cout << "Мощность множества А - " << calculatePower(set) << std::endl;
    std::cout << "Вывод множества A - " << out(set, ",") << std::endl;
}