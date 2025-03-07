#pragma once
#include "User.h"

#include<iostream>
#include<string>        
#include<vector>

using namespace std;

class Librarian : public User
{
public:
    Librarian(const string& uname, const string& pass) : User(uname, pass) {}

    void mainMenu() override {
        cout << "Welcome Librarian" << endl;
        cout << "Select one of the following options:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Remove a book" << endl;
        cout << "3. Issue a book" << endl;
        cout << "4. Return a book" << endl;
        cout << "5. Reserve a book" << endl;
        cout << "6. Generate a repor" << endl;
        cout << "7. Exit" << endl;
    }
};

