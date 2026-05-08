#include "Book.h"

// sets up the book with its info makes it not borrowed from the start
Book::Book(string t, string a, string c) {
    title = t;
    author = a;
    classification = c;
    isBorrowed = false;
    dueDate = 0;
}
// prints book info, shows due date if its currently borrowed
void Book::display() {
    cout << "Book " << title
         << ", Author:" << author
         << ", Classification: " << classification
         << (isBorrowed ? " [Borrowed]" : " [Available]") << endl;
    if (isBorrowed) {
        cout << "Due Date: " << ctime(&dueDate);
    }
}
// marks book as borrowed and sets the due date
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
// marks book as returned and clears the due date
void Book::returnBook() {
    if (isBorrowed) {
        isBorrowed = false;
        dueDate = 0;
        cout << "Book returned successfully." << endl;
    } else {
        cout << "Book was not borrowed." << endl;
    }
}
// adds extra days to the due date, default is 10
void Book::extendDueDate(int extraDays) {
    if (isBorrowed) {
        dueDate += extraDays * 24 * 60 * 60;
        cout << "Due date extended by " << extraDays << " days. New due date: "
             << ctime(&dueDate);
    } else {
        cout << "Book is not borrowed, cannot extend." << endl;
    }
}
