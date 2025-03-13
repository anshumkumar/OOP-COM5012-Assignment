#pragma once
#include "User.h"
#include "Book.h"

#include<iostream>
#include<string>        
#include<vector>


using namespace std;

class Librarian : public User
{
public:
    Librarian(const string& uname, const string& pass) : User(uname, pass) {}

    void mainMenu() override {
		cout << "Welcome to the Librarian dashboard" << endl;

    }
    void librarianActions(vector<Book>& books);
};

