//
// Created by james on 5/7/2026.
//

#ifndef NEWLOAN_BOOK_H
#define NEWLOAN_BOOK_H
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

class Book {
public:
    string title;
    string author;
    string classification;
    bool   isBorrowed;
    time_t dueDate;

    Book(string t, string a, string c);

    void display();
    void borrowBook(int loanDays = 14);
    void returnBook();
    void extendDueDate(int extraDays = 10);
};
#endif //NEWLOAN_BOOK_H