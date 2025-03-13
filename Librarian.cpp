// Librarian.cpp
#include "Librarian.h"
#include "Member.h"
#include "User.h"
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

void Librarian::librarianActions(vector<Book>& books) {  //Vector that stores books is used.
    int selection = 0;
	do {  //Do while loop is used to keep the menu running until user selects a choice.

        cout << "\n--- Librarian Menu ---" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Remove a book" << endl;
        cout << "3. Issue a book (handle borrowing request)" << endl;
        cout << "4. Accept returned book" << endl;
        cout << "5. Reserve a book" << endl;
        cout << "6. Update book record" << endl;
        cout << "7. Generate overdue report" << endl;
        cout << "8. Add book to user account" << endl;
        cout << "9. Remove book from user account" << endl;
        cout << "10. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> selection;
        cin.ignore();  

        if (selection == 1) { // For adding a book to the system
            cout << "Enter book title: ";
            string title;
            getline(cin, title);
            cout << "Enter book author: ";
            string author;
            getline(cin, author);
            books.push_back(Book(title, author));
            cout << "Book added successfully." << endl;
        }
        else if (selection == 2) { // Remove a book
            cout << "Enter the title of the book to remove: ";
            string title;
            getline(cin, title);
            bool removed = false;
            for (auto it = books.begin(); it != books.end(); ++it) {
                if (it->getTitle() == title) {
                    books.erase(it);
                    cout << "Book removed successfully." << endl;
                    removed = true;
                    break;
                }
            }
            if (!removed)
                cout << "Book not found." << endl;
        }
        else if (selection == 3) { // Issue (borrow) a book
            cout << "Enter the title of the book to issue: ";
            string title;
            getline(cin, title);
            bool found = false;
            for (auto& book : books) {
                if (book.getTitle() == title) {
                    book.borrowBook();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book not found." << endl;
        }
        else if (selection == 4) { // Accept returned book
            cout << "Enter the title of the book to accept return: ";
            string title;
            getline(cin, title);
            bool found = false;
            for (auto& book : books) {
                if (book.getTitle() == title) {
                    book.returnBook();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book not found." << endl;
        }
        else if (selection == 5) { // Reserve a book
            cout << "Enter the title of the book to reserve: ";
            string title;
            getline(cin, title);
            bool found = false;
            for (auto& book : books) {
                if (book.getTitle() == title) {
                    book.reserveBook();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book not found." << endl;
        }
        else if (selection == 6) { // Update book record
            cout << "Enter the title of the book to update: ";
            string title;
            getline(cin, title);
            bool found = false;
            for (auto& book : books) {
                if (book.getTitle() == title) {
                    found = true;
                    cout << "Enter new status (Available/Borrowed/Reserved/Overdue): ";
                    string newStatus;
                    getline(cin, newStatus);
                    book.setStatus(newStatus);
                    cout << "Book record updated." << endl;
                    break;
                }
            }
            if (!found)
                cout << "Book not found." << endl;
        }
        else if (selection == 7) { // Generate overdue report
            cout << "\n--- Overdue Books Report ---" << endl;
            bool anyOverdue = false;
            for (auto& book : books) {
                if (book.getStatus() == "Overdue") {
                    book.display();
                    anyOverdue = true;
                }
            }
            if (!anyOverdue)
                cout << "No overdue books found." << endl;
        }
        else if (selection == 8) { // Add book to user account
            cout << "Enter the member id to add a book to: ";
            string memberId;
            getline(cin, memberId);
            Member* targetMember = nullptr;
            for (User* u : User::accounts) {
                Member* m = dynamic_cast<Member*>(u);
                if (m != nullptr && m->getId() == memberId) {
                    targetMember = m;
                    break;
                }
            }
            if (targetMember == nullptr) {
                cout << "Member not found." << endl;
            }
            else {
                cout << "Enter the title of the book to add to the member's account: ";
                string bookTitle;
                getline(cin, bookTitle);
                bool found = false;
                for (auto& book : books) {
                    if (book.getTitle() == bookTitle) {
                        // Add the address of the book in the library vector.
                        targetMember->addBook(&book);
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Book not found in the library." << endl;
            }
        }
        else if (selection == 9) { // Remove book from user account
            cout << "Enter the member id to remove a book from: ";
            string memberId;
            getline(cin, memberId);
            Member* targetMember = nullptr;
            for (User* u : User::accounts) {
                Member* m = dynamic_cast<Member*>(u);
                if (m != nullptr && m->getId() == memberId) {
                    targetMember = m;
                    break;
                }
            }
            if (targetMember == nullptr) {
                cout << "Member not found." << endl;
            }
            else {
                cout << "Enter the title of the book to remove from the member's account: ";
                string bookTitle;
                getline(cin, bookTitle);
                targetMember->bookRemove(bookTitle);
            }
        }
        else if (selection == 10) {
            cout << "Logging out..." << endl;
        }
        else {
            cout << "Invalid selection. Please try again." << endl;
        }
    } while (selection != 10);
} 




