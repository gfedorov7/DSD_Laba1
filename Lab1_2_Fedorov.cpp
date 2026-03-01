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
    int startValue = minValue + std::rand() % (maxValue - minValue-10 + 1);
    int endValue = minValue + std::rand() % (maxValue - minValue + 1);
    if (startValue > endValue) {
        int temp = startValue;
        startValue = endValue;
        endValue = temp;
    }

    Set* A = F5_createEven(count, startValue, endValue);
    Set* B = F5_createMultipleOf6(count, startValue, endValue);

    std::cout << "Создано множество A" << std::endl;
    std::cout << "Вывод множества A - " << F7_out(A, " ") << std::endl;

    std::cout << "Создано множество B" << std::endl;
    std::cout << "Вывод множества B - " << F7_out(B, " ") << std::endl;

    std::cout << "Является ли A подмножеством B: " << F9_isSubset(A, B) << std::endl;
    std::cout << "Является ли A подмножеством А: " << F9_isSubset(A, A) << std::endl;
    std::cout << "Равно ли A множеству B: " << F10_isEqual(A, B) << std::endl;
    std::cout << "Равно ли A множеству A: " << F10_isEqual(A, A) << std::endl;

    Set* temp = F11_unification(A, B);
    std::cout << "Объединение множеств А и В: " << F7_out(temp, ", ") << std::endl;
    temp = F12_intersection(A, B);
    std::cout << "Пересечение множеств А и В: " << F7_out(temp, ", ") << std::endl;
    temp = F13_difference(A, B);
    std::cout << "Разница множеств А и В: " << F7_out(temp, ", ") << std::endl;
    temp = F14_symmetricDifference(A, B);
    std::cout << "Симметричная разница множеств А и В: " << F7_out(temp, ", ") << std::endl;


    // std::cout << "Создано множество A - ";
    // Set* set = F5_create(count, startValue, endValue);
    // std::cout << "Мощность множества А - " << F6_calculatePower(set) << std::endl;
    // std::cout << "Вывод множества A - " << F7_out(set, ",") << std::endl;
    // set = F8_clear(set);
    // std::cout << "Мощность множества А - " << F6_calculatePower(set) << std::endl;
    // std::cout << "Вывод множества A - " << F7_out(set, ",") << std::endl;
}