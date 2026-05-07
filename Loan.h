#ifndef NEWLOAN_LOAN_H
#define NEWLOAN_LOAN_H
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

class Loan {
public:
    string memberID;
    string itemTitle;
    string itemType;
    int    extensions;
    bool   returned;
    time_t borrowDate;
    time_t dueDate;

    static const double FINE_PER_DAY;
    static const int    EXTENSION_DAYS;

    Loan(string mID, string title, string type, time_t due);

    void   requestExtension(time_t& due);
    double calculateFine() const;
    double closeLoan();
    void   display() const;

private:
    string formatDate(time_t t) const;
};
#endif //NEWLOAN_LOAN_H