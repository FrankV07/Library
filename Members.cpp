#include "Members.h"
// sets up the member with name and type, everything starts at zero
Members::Members(string n, string t) {
    name = n;
    type = t;
    bookCount = 0;
    magazineCount = 0;
    fines = 0;
}
// borrows a book if the member hasnt hit their limit
// students can have 5, faculty/staff can have 10
void Members::borrowBook(Book* b) {
    int limit;
    if (type == "Student") {
        limit = 5;
    } else {
        limit = 10;
    }
    if (bookCount < limit) {
        books[bookCount] = b;
        bookCount++;
        b->borrowBook();
    } else {
        cout << "Book limit reached.\n";
    }
}
// calls returnBook on the book object
void Members::returnBook(Book* b) {
    b->returnBook();
}
// borrows a magazine, no limit on magazines
void Members::borrowMagazine(Magazine* m) {
    magazines[magazineCount] = m;
    magazineCount++;
    m->borrowMagazine();
}
// just calls returnMagazine on the magazine object
void Members::returnMagazine(Magazine* m) {
    m->returnMagazine();
}
// prints everything about the member, books, magazines and fines
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
