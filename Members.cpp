#include "Members.h"

Members::Members(string n, string t) {

    name = n;
    type = t;

    bookCount = 0;
    magazineCount = 0;

    fines = 0;
}

// Borrow Book
void Members::borrowBook(Book* b) {

    int limit;

    if (type == "Student") {
        limit = 5;
    }
    else {
        limit = 10;
    }

    if (bookCount < limit) {

        books[bookCount] = b;
        bookCount++;

        b->borrowBook();
    }
    else {
        cout << "Book limit reached.\n";
    }
}

void Members::returnBook(Book* b) {

    b->returnBook();
}

void Members::borrowMagazine(Magazine* m) {

    magazines[magazineCount] = m;
    magazineCount++;

    m->borrowMagazine();
}

// Return Magazine
void Members::returnMagazine(Magazine* m) {

    m->returnMagazine();
}

void Members::display() {

    cout << "\nName: " << name << endl;
    cout << "Type: " << type << endl;

    cout << "\nBooks Borrowed:\n";

    for (int i = 0; i < bookCount; i++) {
        cout << books[i]->title << endl;
    }

    cout << "\nMagazines Borrowed:\n";

    for (int i = 0; i < magazineCount; i++) {
        cout << magazines[i]->title << endl;
    }

    cout << "\nFines: $" << fines << endl;
}