#ifndef NEWLOAN_MAGAZINE_H
#define NEWLOAN_MAGAZINE_H

#include <iostream>
#include <string>
#include <ctime>
#include "Book.h"
#include "Magazine.h"
using namespace std;

class Magazine {
public:
    string title;
    string issue;
    bool isBorrowed;
    time_t dueDate;

    Magazine(string t, string i);

    void display();

    void borrowMagazine(int loanDays = 14);

    void returnMagazine();
};

#endif //NEWLOAN_MAGAZINE_H