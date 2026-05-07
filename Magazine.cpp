#include "Magazine.h"

Magazine::Magazine(string t, string i) {
    title = t;
    issue = i;
    isBorrowed = false;
    dueDate = 0;
}

void Magazine::display() {
    cout << "Magazine: " << title
         << ", Issue: " << issue
         << (isBorrowed ? " [Borrowed]" : " [Available]") << endl;
    if (isBorrowed) {
        cout << "Due date: " << ctime(&dueDate);
    }
}

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

void Magazine::returnMagazine() {
    if (isBorrowed) {
        isBorrowed = false;
        dueDate = 0;
        cout << "Magazine return success." << endl;
    } else {
        cout << "Magazine isn't borrowed." << endl;
    }
}