//
// Created by User on 10.02.2026.
//

#ifndef DSD_LABA1_SETLAB1_2_FEDOROV_H
#define DSD_LABA1_SETLAB1_2_FEDOROV_H


struct Set {
    int value;
    Set* next;
};

Set* createEmpty();
bool isEmpty(Set* firstElement);
bool containsElement(Set* firstElement, int value);
Set* add(Set* firstElement, int value);
Set* create(int count, int min, int max);
int calculatePower(Set* firstElement);
std::string out(Set* firstElement, const std::string& delimiter);
Set* clear(Set* firstElement);

#endif //DSD_LABA1_SETLAB1_2_FEDOROV_H
