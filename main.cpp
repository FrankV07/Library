#include <iomanip>
#include "Book.h"
#include "Magazine.h"
#include "Members.h"
#include "Loan.h"
int main() {
    Book book1("1.) |Percy Jackson|"    , "Rick Riordan", "Placeholder");
    Book book2("2.) |House of Leaves|"  , "Mark Z. Danielewski", "Placeholder");
    int choice;
    do {
        cout << "1. Display Books\n2. Borrow Book\n3. Return Book\n4. Extend Book\n 5. Check Loan\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                book1.display();
                book2.display();
                break;
            case 2: {
                int b;
                cout << "What book do you want to borrow (1 or 2): ";
                cin >> b;
                if (b == 1) book1.borrowBook();
                else if (b == 2) book2.borrowBook();
                else cout << "Invalid number.\n";
                break;
            }
            case 3: {
                int b;
                cout << "What book do you want to return (1 or 2): ";
                cin >> b;
                if (b == 1) book1.returnBook();
                else if (b == 2) book2.returnBook();
                else cout << "Invalid number.\n";
                break;
            }
            case 4: {
                int b;
                cout << "Enter book number to extend (1 or 2): ";
                cin >> b;
                if (b == 1) book1.extendDueDate();
                else if (b == 2) book2.extendDueDate();
                else cout << "Invalid number\n";
                break;
            }
            case 5: {
                cout << "Which book do you want to check loan cost for (1 or 2): ";
                int b;
                cin >> b;

                Book* chosen = nullptr;
                if (b == 1) chosen = &book1;
                else if (b == 2) chosen = &book2;
                else { cout << "Invalid number.\n"; break; }

                if (!chosen->isBorrowed) {
                    cout << "That book is not currently borrowed.\n";
                    break;
                }

                cout << "How many days late is the return: ";
                int daysLate;
                cin >> daysLate;

                if (daysLate <= 0) {
                    cout << "Book returned on time, no late fee.\n";
                } else {
                    double fee = daysLate * 1.75;
                    cout << fixed << setprecision(2);
                    cout << "Days late: " << daysLate << endl;
                    cout << "Late fee: $" << fee << endl;
                }
                break;
            }

            case 0:
                cout << "Thank You for using our Library System!\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);
}