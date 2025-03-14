// Member.cpp
#include "Member.h"

#include <iostream>
#include <string>
using namespace std;

//Memberactions function is defined here.
void Member::memberActions(vector<Book>& books) {
    int memberSelection = 0;  //This will store user's selection choice and then process it.
	//It is kept at 0 as default value.

    do {   //Do while statement will keep this menu running until the user selects a choice.
        mainMenu();
        cout << "Enter your choice: ";
		cin >> memberSelection;    //User's choice will be stored in memberSelection.
        cin.ignore(); // Clear newline, ignore it.

        if (memberSelection == 1) {
            // Search for a book by title
            cout << "Enter the title of the book: ";
            string searchTitle;
            getline(cin, searchTitle);

			bool found = false;  //boolean variable to check if the book is found or not.
            for (auto& book : books) { //Uses vector which stored books
                if (book.getTitle() == searchTitle) {  //If user's search matches getTitle function
                    cout << "Book found: " << book.getTitle() << " by " << book.getAuthor()
                        << " - Status: " << book.getStatus() << endl;
                    //Then the book has been found, its details and status are displayed through getTitle and getStatus.
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book not found in the library." << endl;
			//If book is not found, this message will be displayed.
        }
        else if (memberSelection == 2) {
            // This is for searching for a book by author name.
            cout << "Enter the name of the author: ";
            string searchAuthor;
            getline(cin, searchAuthor);

            bool found = false;
            cout << "\nBooks by " << searchAuthor << ":" << endl;
            for (auto& book : books) {
                if (book.getAuthor() == searchAuthor) {
                    cout << "- " << book.getTitle() << " (Status: " << book.getStatus() << ")" << endl;
                    found = true;
					// Similar logic is used like memberSelection 1, but for an author's name.
                }
            }
            if (!found)
                cout << "No books found by this author." << endl;
        }
        else if (memberSelection == 3) {
            // This is for borrowing a book
            cout << "Enter the title of the book you want to borrow: ";
            string borrowbyTitle;   //String variable created to borrow book by title.
            getline(cin, borrowbyTitle);

            bool found = false;
			for (auto& book : books) { //reference to book vector where books are stored.
				if (book.getTitle() == borrowbyTitle) {  // if title entered by user matches getTitle function
                    addBook(&book);     //Then addBook function is used, it completes process of borrowinh the book.
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
            string returnbyTitle;
            getline(cin, returnbyTitle);

            bool found = false;
            for (auto& book : books) {
                if (book.getTitle() == returnbyTitle) {
                    book.returnBook();
                    found = true;
                    break;
				}     //Similar logic used like adding book, this one is for returning the book.
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
                    book.reserveBook();  // Reserves book function. Present in book class.
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
		if (memberSelection != 6)
			cout << "Select your next option.";
    } while (memberSelection != 6);
}


// addBook function is defined here. Its a function of member class.
// pointer is used to add a book to the borrowedBooks vector.

void Member::addBook(Book* book) {  //addBook function is defined here, it is from member class.
    if (book != nullptr) {   
        book->setStatus("Borrowed");    //Book's status is changed.
        cout << "Book has been borrowed" << endl;
    }
}

void Member::bookRemove(const string& bookTitle)
{
    cout << "Book '" << bookTitle << "Book removed from the account " << endl;
}

    //Althought the user returns the book and they have been showed with this message.
    //The librarian needs to approve the return by returning the book.


