#include <iomanip>
#include "Book.h"
#include "Magazine.h"
#include "Members.h"
#include "Loan.h"

int main() {
    // all the books in the library with their LCC classifications
    Book books[] = {
        Book("1.) |Percy Jackson|",          "Rick Riordan",        "PZ7.R4829 Li 2005"),
        Book("2.) |House of Branches|",      "Mark Z. Danielewski", "PS3554.A613 H68 2000"),
        Book("3.) |A Game Of Seats|",        "George R.R Martin",   "PS3563.A7239 G36 1996"),
        Book("4.) |1849|",                   "George Orwell",       "PR6029.R8 N49 1949"),
        Book("5.) |The Martian|",            "Andy Weir",           "PS3623.E446 M37 2014"),
        Book("6.) |Paradise Lost|",          "John Milton",         "PR3560 .A1 1667"),
        Book("7.) |Diary Of A Wimpy Kid|",   "Jeff Kinney",         "PZ7.K6235 Di 2007"),
        Book("8.) |Lord Of The Flies|",      "William Golding",     "PR6013.O35 L6 1954"),
        Book("9.) |Death Of A Salesman|",    "Arthur Miller",       "PS3525.I515 D4 1949"),
        Book("10.) |Don Quixote|",           "Miguel de Cervantes", "PQ6329 .A1 1605"),
        Book("11.) |Animal Farm|",           "George Orwell",       "PR6029.R8 A63 1945"),
    };
    int bookCount = 11;
    // magazines, using issue field for the issue number
    Magazine magazines[] = {
        Magazine("Zark Muckerberg, lizard pretending to be human?", "#12"),
        Magazine("What Office Character are you (Opps all Dwights!)","#45"),
        Magazine("Killer Penguins Break Out Of The Bronx Zoo",      "#30"),
        Magazine("Air, friend or foe?",                             "#1038"),
        Magazine("CLICKBAIT TITLE CLICKBAIT TITLE CLICKBAIT TI",   "#2026"),
    };
    int magCount = 5;
    string memberName, memberType;
    int typeChoice;
    // ask if the user is a student or faculty to set borrow limits
    cout << "Welcome to the University Library System!" << endl;
    cout << "Are you a:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Faculty / Staff" << endl;
    cout << "Enter choice: ";
    cin >> typeChoice;
    cout << "Enter your name: ";
    cin >> memberName;
    if (typeChoice == 1) {
        memberType = "Student";
    } else {
        memberType = "Faculty";
    }
    Members currentMember(memberName, memberType);
    cout << "\nWelcome, " << memberName << "! (" << memberType << ")" << endl;
    if (memberType == "Student") {
        cout << "You can borrow up to 5 books." << endl;
    } else {
        cout << "You can borrow up to 10 books." << endl;
    }
    int choice;
    do {
        cout << "\n1. Display Books" << endl;
        cout << "2. Display Magazines" << endl;
        cout << "3. Borrow Book" << endl;
        cout << "4. Borrow Magazine" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Return Magazine" << endl;
        cout << "7. Extend Book" << endl;
        cout << "8. Check Loan Cost" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            // show all books in the library
            case 1:
                cout << "\n=== Books ===" << endl;
                for (int i = 0; i < bookCount; i++) {
                    books[i].display();
                }
                break;
            // show all magazines
            case 2:
                cout << "\n=== Magazines ===" << endl;
                for (int i = 0; i < magCount; i++) {
                    magazines[i].display();
                }
                break;
            // borrow a book, members class handles the limit check
            case 3: {
                cout << "\n=== Books ===" << endl;
                for (int i = 0; i < bookCount; i++) {
                    books[i].display();
                }
                int b;
                cout << "Enter book number to borrow: ";
                cin >> b;
                if (b >= 1 && b <= bookCount) {
                    currentMember.borrowBook(&books[b - 1]);
                } else {
                    cout << "Invalid number.\n";
                }
                break;
            }
            // borrow a magazine
            case 4: {
                cout << "\n=== Magazines ===" << endl;
                for (int i = 0; i < magCount; i++) {
                    magazines[i].display();
                }
                int m;
                cout << "Enter magazine number to borrow: ";
                cin >> m;
                if (m >= 1 && m <= magCount) {
                    currentMember.borrowMagazine(&magazines[m - 1]);
                } else {
                    cout << "Invalid number.\n";
                }
                break;
            }
            // only shows books you currently have borrowed
            case 5: {
                cout << "\n=== Your Borrowed Books ===" << endl;
                bool anyBorrowed = false;
                for (int i = 0; i < bookCount; i++) {
                    if (books[i].isBorrowed) {
                        cout << i + 1 << ". ";
                        books[i].display();
                        anyBorrowed = true;
                    }
                }
                if (!anyBorrowed) {
                    cout << "You have no borrowed books.\n";
                    break;
                }
                int b;
                cout << "Enter book number to return: ";
                cin >> b;
                if (b >= 1 && b <= bookCount) {
                    currentMember.returnBook(&books[b - 1]);
                } else {
                    cout << "Invalid number.\n";
                }
                break;
            }
            // return a magazine
            case 6: {
                cout << "\n=== Magazines ===" << endl;
                for (int i = 0; i < magCount; i++) {
                    magazines[i].display();
                }
                int m;
                cout << "Enter magazine number to return: ";
                cin >> m;
                if (m >= 1 && m <= magCount) {
                    currentMember.returnMagazine(&magazines[m - 1]);
                } else {
                    cout << "Invalid number.\n";
                }
                break;
            }
            // extend due date, only shows your borrowed books
            case 7: {
                cout << "\n=== Your Borrowed Books ===" << endl;
                bool anyBorrowed = false;
                for (int i = 0; i < bookCount; i++) {
                    if (books[i].isBorrowed) {
                        cout << i + 1 << ". ";
                        books[i].display();
                        anyBorrowed = true;
                    }
                }
                if (!anyBorrowed) {
                    cout << "You have no borrowed books.\n";
                    break;
                }
                int b;
                cout << "Enter book number to extend: ";
                cin >> b;
                if (b >= 1 && b <= bookCount) {
                    books[b - 1].extendDueDate();
                } else {
                    cout << "Invalid number.\n";
                }
                break;
            }
            // check how much you owe if you return a book late
            // uses the Loan class to calculate the fine
            case 8: {
                cout << "\n=== Your Borrowed Books ===" << endl;
                bool anyBorrowed = false;
                for (int i = 0; i < bookCount; i++) {
                    if (books[i].isBorrowed) {
                        cout << i + 1 << ". ";
                        books[i].display();
                        anyBorrowed = true;
                    }
                }
                if (!anyBorrowed) {
                    cout << "You have no borrowed books.\n";
                    break;
                }
                int b;
                cout << "Enter book number to check loan cost: ";
                cin >> b;

                if (b < 1 || b > bookCount) { cout << "Invalid number.\n"; break; }

                Book* chosen = &books[b - 1];

                if (!chosen->isBorrowed) {
                    cout << "That book is not currently borrowed.\n";
                    break;
                }
                Loan loan("MBR-001", chosen->title, "Book", chosen->dueDate);

                cout << "How many days late is the return: ";
                int daysLate;
                cin >> daysLate;

                if (daysLate <= 0) {
                    cout << "Book returned on time, no late fee.\n";
                } else {
                    // set the due date back to simulate being late
                    loan.dueDate = time(0) - daysLate * 24 * 60 * 60;
                    double fee = loan.calculateFine();
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
