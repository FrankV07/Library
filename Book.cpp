#include "Book.h"

Book::Book(string t, string a, string c) {
    title = t;
    author = a;
    classification = c;
    isBorrowed = false;
    dueDate = 0;
}

void Book::display() {
    cout << "Book " << title
         << ", Author:" << author
         << ", Classification: " << classification
         << (isBorrowed ? " [Borrowed]" : " [Available]") << endl;
    if (isBorrowed) {
        cout << "Due Date: " << ctime(&dueDate);
    }
}

void Book::borrowBook(int loanDays) {
    if (!isBorrowed) {
        isBorrowed = true;
        time_t now = time(0);
        dueDate = now + loanDays * 24 * 60 * 60;
        cout << "Book borrowed successfully. Due in " << loanDays << " days." << endl;
    } else {
        cout << "Book is already borrowed." << endl;
    }
}

void Book::returnBook() {
    if (isBorrowed) {
        isBorrowed = false;
        dueDate = 0;
        cout << "Book returned successfully." << endl;
    } else {
        cout << "Book was not borrowed." << endl;
    }
}

void Book::extendDueDate(int extraDays) {
    if (isBorrowed) {
        dueDate += extraDays * 24 * 60 * 60;
        cout << "Due date extended by " << extraDays << " days. New due date: "
             << ctime(&dueDate);
    } else {
        cout << "Book is not borrowed, cannot extend." << endl;
    }
}