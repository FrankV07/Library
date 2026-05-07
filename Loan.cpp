#include "Loan.h"

const double Loan::FINE_PER_DAY   = 1.75;
const int    Loan::EXTENSION_DAYS = 10;


Loan::Loan(string mID, string title, string type, time_t due) {
    memberID   = mID;
    itemTitle  = title;
    itemType   = type;
    dueDate    = due;
    borrowDate = time(0);
    extensions = 0;
    returned   = false;
}


void Loan::requestExtension(time_t& due) {
    if (returned) {
        cout << "Cannot extend: item already returned." << endl;
        return;
    }
    dueDate += EXTENSION_DAYS * 24 * 60 * 60;
    due     += EXTENSION_DAYS * 24 * 60 * 60;
    extensions++;
    cout << "Due date extended by " << EXTENSION_DAYS << " days. New due date: "
         << ctime(&dueDate);
}


double Loan::calculateFine() const {
    if (returned) return 0.0;
    time_t now      = time(0);
    double diffSecs = difftime(now, dueDate);
    if (diffSecs <= 0) return 0.0;
    int daysLate = static_cast<int>(diffSecs / (24 * 60 * 60));
    double fee   = daysLate * FINE_PER_DAY;
    return fee;
}


double Loan::closeLoan() {
    if (returned) {
        cout << "This loan is already closed" << endl;
        return 0.0;
    }
    double fee = calculateFine();
    returned   = true;
    if (fee > 0.0) {
        cout << fixed << setprecision(2);
        cout << "Late fee: $" << fee << endl;
    } else {
        cout << "Book returned on time, no late fee." << endl;
    }
    return fee;
}

void Loan::display() const {
    cout << "Member ID  : " << memberID                          << endl;
    cout << "Item       : " << itemTitle << " (" << itemType << ")" << endl;
    cout << "Borrowed   : " << formatDate(borrowDate)            << endl;
    cout << "Due        : " << formatDate(dueDate)               << endl;
    cout << "Extensions : " << extensions                        << endl;
    cout << "Status     : " << (returned ? "Returned" : "Active")<< endl;
    double fee = calculateFine();
    if (fee > 0.0) {
        cout << fixed << setprecision(2);
        cout << "Late fee   : $" << fee                          << endl;
    }
}
string Loan::formatDate(time_t t) const {
    string s = ctime(&t);
    if (!s.empty() && s.back() == '\n') s.pop_back();
    return s;
}