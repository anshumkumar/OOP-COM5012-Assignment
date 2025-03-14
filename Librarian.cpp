// Librarian.cpp
#include "Librarian.h"
#include "Member.h"
#include "User.h"
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

void Librarian::librarianActions(vector<Book>& books) {  //Vector that stores books is used.
    int libselection = 0;
    do {  //Do while loop is used to keep the menu running until user selects a choice.

        do {  //Do while loop is used to keep the menu running until user selects a choice.

            cout << "\n--- Librarian Menu ---" << endl;
            cout << "1. Add a book into system" << endl;
            cout << "2. Remove a book from the system" << endl;
            cout << "3. Borrow a book for yourself" << endl;
            cout << "4. Accept returned book from the user" << endl;
            cout << "5. Reserve a book for user" << endl;
            cout << "6. Update book records (Available/Overdue/Reserved)" << endl;
            cout << "7. Generate overdue books report" << endl;
            cout << "8. Add book to user account" << endl;
            cout << "9. Remove book from user account" << endl;
            cout << "10. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> libselection;
            cin.ignore();

            if (libselection == 1) { // For adding a book to the system
                cout << "Enter book title: ";
                string title;
                getline(cin, title);
                cout << "Enter book author: ";
                string author;
                getline(cin, author);
                books.push_back(Book(title, author));   //Pushes the book to the vector.
                cout << "Book added successfully." << endl;
            }
            else if (libselection == 2) { // Remove a book
                cout << "Enter the title of the book to remove: ";
                string title;
                getline(cin, title);
                bool removed = false;
                for (auto it = books.begin(); it != books.end(); ++it) {  //for loop to iterate through the vector.
                    if (it->getTitle() == title) {                       //Iterates through each object in vector of books.
                        books.erase(it);                                    //Removal function removes book, if the getTitle matches title
                        cout << "Book removed successfully." << endl;
                        removed = true;
                        break;
                    }
                }
                if (!removed)
                    cout << "Book not found." << endl;
            }
			else if (libselection == 3) { // Issue (borrow) a book for librarian
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
            else if (libselection == 4) { // Accept returned book
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
            else if (libselection == 5) { // Reserve a book
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
            else if (libselection == 6) { // Update book record
                cout << "Enter the title of the book to update: ";
                string title;
                getline(cin, title);
                bool found = false;
                for (auto& book : books) {
                    if (book.getTitle() == title) {
                        found = true;
                        cout << "Enter new status (Available/Borrowed/Reserved/Overdue): ";
                        string newbookStatus;
                        getline(cin, newbookStatus);
                        book.setStatus(newbookStatus);
                        cout << "Book record updated." << endl;
                        break;
                    }
                }
                if (!found)
                    cout << "Book not found." << endl;
            }
            else if (libselection == 7) { // Generate overdue report
                cout << "\n--- Overdue Books Report ---" << endl;
                bool overdueBook = false;
                for (auto& book : books) {
                    if (book.getStatus() == "Overdue") {
                        book.display();
                        overdueBook = true;
                    }
                }
                if (!overdueBook)
                    cout << "No overdue books found." << endl;
            }
            else if (libselection == 8) { // Add book to user account
                cout << "Enter the member id to add a book to: ";
                string memberId;
                getline(cin, memberId);
                Member* targetMember = nullptr;  //Initially it is set to null.
                for (User* u : User::accounts) {
                    Member* m = dynamic_cast<Member*>(u);  //Dynamic cast is used to check if the user is a member.
                    if (m != nullptr && m->getId() == memberId) {       //if the details match then the member is found.
                        targetMember = m; //The member is set to targetMember.
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
            else if (libselection == 9) { // Remove book from user account
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
            else if (libselection == 10) {
                cout << "Logging out..." << endl;
            }
            else {
                cout << "Invalid selection. Please try again." << endl;
            }
        } while (libselection != 10);
    } while (libselection != 10);
}

