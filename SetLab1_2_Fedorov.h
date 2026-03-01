//
// Created by User on 10.02.2026.
//

#ifndef DSD_LABA1_SETLAB1_2_FEDOROV_H
#define DSD_LABA1_SETLAB1_2_FEDOROV_H


struct Set {
    int value;
    Set* next;
};

Set* F1_createEmpty();
bool F2_isEmpty(Set* firstElement);
bool F3_containsElement(Set* firstElement, int value);
Set* F4_add(Set* firstElement, int value);
Set* F5_createMultipleOf6(int count, int min, int max);
Set* F5_createEven(int count, int min, int max);
Set* F5_create(int count, int min, int max);
int F6_calculatePower(Set* firstElement);
std::string F7_out(Set* firstElement, const std::string& delimiter);
Set* F8_clear(Set* firstElement);
bool F9_isSubset(Set* A, Set* B);
bool F10_isEqual(Set* A, Set* B);
Set* F11_unification(Set* A, Set* B);
Set* F12_intersection(Set* A, Set* B);
Set* F13_difference(Set* A, Set* B);
Set* F14_symmetricDifference(Set* A, Set* B);

#endif //DSD_LABA1_SETLAB1_2_FEDOROV_H
