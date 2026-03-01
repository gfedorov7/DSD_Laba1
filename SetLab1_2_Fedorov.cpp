//
// Created by User on 10.02.2026.
//
#include <ctime>
#include "cstdlib"
#include "iostream"
#include "string"
#include "SetLab1_2_Fedorov.h"


Set* F1_createEmpty() {
    return nullptr;
}

bool F2_isEmpty(Set* firstElement) {
    return firstElement == nullptr;
}

bool F3_containsElement(Set* firstElement, int value) {
    if (F2_isEmpty(firstElement))
        return false;

    Set* current = firstElement;
    while (current != nullptr) {
        if (value == current->value)
            return true;
        current = current->next;
    }

    return false;
}

Set* F4_add(Set* firstElement, int value) {
    if (F3_containsElement(firstElement, value))
        return firstElement;

    Set* newSet = new Set();
    newSet->value = value;
    newSet->next = firstElement;
    return newSet;
}

Set* F5_create(int count, int min, int max) {
    if (count > (max - min + 1)) {
        // пишу на английском тк почему-то ломается кодировка при выводе в консоль, в main все нормально
        std::cout << "Cannot create in this range" << std::endl;
        return nullptr;
    }

    Set* set = nullptr;
    int currentCount = 0;

    while (currentCount < count)
    {
        int value = min + std::rand() % (max - min + 1);

        Set* temp = F4_add(set, value);
        if (temp != set) {
            set = temp;
            currentCount++;
        }
    }

    return set;
}

int F6_calculatePower(Set* firstElement)
{
    if (F2_isEmpty(firstElement))
        return 0;

    int power = 0;
    Set* current = firstElement;
    while (current != nullptr)
    {
        power++;
        current = current->next;
    }

    return power;
}

std::string F7_out(Set* firstElement, const std::string& delimiter) {
    std::string outString;

    if (F2_isEmpty(firstElement))
        return outString;

    Set* current = firstElement;
    while (current != nullptr)
    {
        outString += std::to_string(current->value) + delimiter;
        current = current->next;
    }

    if (outString.length() > delimiter.length())
        outString.erase(outString.length() - delimiter.length());

    return outString;
}

Set* F8_clear(Set* firstElement) {
    if (F2_isEmpty(firstElement))
        return firstElement;

    Set* current = firstElement;
    while (current != nullptr) {
        Set* temp = current->next;
        delete current;
        current = temp;
    }

    return current;
}

bool F9_isSubset(Set* A, Set* B) {
    if (F2_isEmpty(A))
        return true;

    if (F2_isEmpty(B))
        return false;

    Set* currentA = A;
    while (currentA != nullptr) {
        bool found = false;
        Set* currentB = B;

        while (currentB != nullptr) {
            if (currentA->value == currentB->value) {
                found = true;
                break;
            }
            currentB = currentB->next;
        }
        if (!found)
            return false;

        currentA = currentA->next;
    }

    return true;
}

bool F10_isEqual(Set* A, Set* B) {
    return F9_isSubset(A, B) && F9_isSubset(B, A);
}

Set* F11_unification(Set* A, Set* B) {
    if (F2_isEmpty(A))
        return B;

    if (F2_isEmpty(B))
        return A;

    Set* newSet = nullptr;
    Set* current = A;
    while (current != nullptr) {
        newSet = F4_add(newSet, current->value);
        current = current->next;
    }

    current = B;
    while (current != nullptr) {
        newSet = F4_add(newSet, current->value);
        current = current->next;
    }

    return newSet;
}

Set* F12_intersection(Set* A, Set* B) {
    if (F2_isEmpty(A) || F2_isEmpty(B))
        return nullptr;

    Set* newSet = nullptr;
    Set* current = A;
    while (current != nullptr) {
        int value = current->value;
        if (F3_containsElement(B, value))
            newSet = F4_add(newSet, value);
        current = current->next;
    }

    return newSet;
}

Set* F13_difference(Set* A, Set* B) {
    if (F2_isEmpty(A))
        return nullptr;

    if (F2_isEmpty(B))
        return A;

    Set* difference = F1_createEmpty();
    Set* current = A;
    while (current != nullptr) {
        int value = current->value;
        if (!F3_containsElement(B, value))
            difference = F4_add(difference, value);
        current = current->next;
    }

    return difference;
}

Set* F14_symmetricDifference(Set* A, Set* B) {
    Set* unionSet = F11_unification(A, B);
    Set* intersectionSet = F12_intersection(A, B);
    Set* result = F13_difference(unionSet, intersectionSet);

    return result;
}