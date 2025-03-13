#pragma once
#include "User.h"
#include "Book.h"

#include<iostream>
#include<string>        
#include<vector>


using namespace std;

class Member : public User { // Member class inherits attributes from the User class

private:
    vector<Book> borrowedBooks;   //Borrowed books are kept private, vector stores their list.
public:
    //Member details kept public so other classes like admin and librarian can access them.
    Member(const std::string& uname, const std::string& pass) : User(uname, pass) {}
	// Constructor for the Member class above. 

	// This menu is shown when member logs in.
    void mainMenu() override {
        cout << "\n--- Member Menu ---" << endl;
        cout << "1. Search for a book" << endl;
        cout << "2. Search for an author" << endl;
        cout << "3. Borrow a book" << endl;
        cout << "4. Return a book" << endl;
        cout << "5. Reserve a book" << endl;
        cout << "6. Exit" << endl;
    }

    // Function to handle member actions, operating on the library collection.
    void memberActions(std::vector<Book>& books);


	//function to add a book to the borrowedBooks vector. Pointer is used.
    void addBook(Book* book);


	//function to remove a book from the borrowedBooks vector. It can be done by entering book title. 
    void bookRemove(const string& bookTitle);


};



