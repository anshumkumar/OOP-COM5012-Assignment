#pragma once
#include "User.h"
#include "Book.h"

#include<iostream>
#include<string>        
#include<vector>

using namespace std;// Member.h
#include "User.h"
#include "Book.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Member : public User {
public:
    Member(const std::string& uname, const std::string& pass) : User(uname, pass) {}

    // This menu is shown when entering the member actions loop.
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
};
