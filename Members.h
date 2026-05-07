
#ifndef NEWLOAN_MEMBERS_H
#define NEWLOAN_MEMBERS_H
#include <iostream>
#include <string>
#include "Book.h"
#include "Magazine.h"
using namespace std;

class Members {
public:
    string name;
    string type;

    Book* books[10];
    int bookCount;

    Magazine* magazines[10];
    int magazineCount;

    double fines;

    Members(string n, string t);

    void borrowBook(Book* b);
    void returnBook(Book* b);

    void borrowMagazine(Magazine* m);
    void returnMagazine(Magazine* m);

    void display();
};
#endif //NEWLOAN_MEMBERS_H