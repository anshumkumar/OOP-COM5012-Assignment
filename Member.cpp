// Member.cpp
#include "Member.h"
#include <iostream>
#include <string>
using namespace std;

void Member::memberActions(vector<Book>& books) {
    int memberSelection = 0;
    do {
        mainMenu();
        cout << "Enter your choice: ";
        cin >> memberSelection;
        cin.ignore(); // Clear newline

        if (memberSelection == 1) {
            // Search for a book by title
            cout << "Enter the title of the book: ";
            string searchTitle;
            getline(cin, searchTitle);

            bool found = false;
            for (auto& book : books) {
                if (book.getTitle() == searchTitle) {
                    cout << "Book found: " << book.getTitle() << " by " << book.getAuthor()
                        << " - Status: " << book.getStatus() << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book not found in the library." << endl;
        }
        else if (memberSelection == 2) {
            // Search for books by author
            cout << "Enter the name of the author: ";
            string searchAuthor;
            getline(cin, searchAuthor);

            bool found = false;
            cout << "\nBooks by " << searchAuthor << ":" << endl;
            for (auto& book : books) {
                if (book.getAuthor() == searchAuthor) {
                    cout << "- " << book.getTitle() << " (Status: " << book.getStatus() << ")" << endl;
                    found = true;
                }
            }
            if (!found)
                cout << "No books found by this author." << endl;
        }
        else if (memberSelection == 3) {
            // Borrow a book
            cout << "Enter the title of the book you want to borrow: ";
            string borrowTitle;
            getline(cin, borrowTitle);

            bool found = false;
            for (auto& book : books) {
                if (book.getTitle() == borrowTitle) {
                    book.borrowBook();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book not found in the library." << endl;
        }
        else if (memberSelection == 4) {
            // Return a book
            cout << "Enter the title of the book you want to return: ";
            string returnTitle;
            getline(cin, returnTitle);

            bool found = false;
            for (auto& book : books) {
                if (book.getTitle() == returnTitle) {
                    book.returnBook();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book not found in the library." << endl;
        }
        else if (memberSelection == 5) {
            // Reserve a book
            cout << "Enter the title of the book you want to reserve: ";
            string reserveTitle;
            getline(cin, reserveTitle);

            bool found = false;
            for (auto& book : books) {
                if (book.getTitle() == reserveTitle) {
                    book.reserveBook();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book not found in the library." << endl;
        }
        else if (memberSelection == 6) {
            cout << "Logging out..." << endl;
        }
        else {
            cout << "Invalid selection. Please try again." << endl;
        }
    } while (memberSelection != 6);
}
