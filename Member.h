#pragma once
#include "User.h"

#include<iostream>
#include<string>        
#include<vector>

using namespace std;

class Member : public User
{
public:
    Member(const string& uname, const string& pass) : User(uname, pass) {}

    void mainMenu() override {
        cout << "Welcome Member" << endl;
        cout << "Select one of the following options:" << endl;
        cout << "1. Search for a book" << endl;
        cout << "2. Search for an author" << endl;
        cout << "3. Borrow a book" << endl;
        cout << "4. Return a book" << endl;
        cout << "5. Exit" << endl;
    }
};

