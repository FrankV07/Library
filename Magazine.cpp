#include "Magazine.h"
// sets up the magazine with title and issue number
Magazine::Magazine(string t, string i) {
    title = t;
    issue = i;
    isBorrowed = false;
    dueDate = 0;
}
// prints magazine info, shows due date if borrowed
void Magazine::display() {
    cout << "Magazine: " << title
         << ", Issue: " << issue
         << (isBorrowed ? " [Borrowed]" : " [Available]") << endl;
    if (isBorrowed) {
        cout << "Due date: " << ctime(&dueDate);
    }
}
// borrows the magazine if its available
void Magazine::borrowMagazine(int loanDays) {
    if (!isBorrowed) {
        isBorrowed = true;
        time_t now = time(0);
        dueDate = now + loanDays * 24 * 60 * 60;
        cout << "Magazine borrowed. Due in " << loanDays << " days." << endl;
    } else {
        cout << "Magazine is already borrowed." << endl;
    }
}
// returns the magazine and clears the due date
void Magazine::returnMagazine() {
    if (isBorrowed) {
        isBorrowed = false;
        dueDate = 0;
        cout << "Magazine return success." << endl;
    } else {
        cout << "Magazine isn't borrowed." << endl;
    }
}
