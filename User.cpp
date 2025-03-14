#include "User.h"
#include <iostream>
#include <string>
#include <vector>

vector<User*> User::accounts;  // Used to store user accounts

User::User(const string& uname, const string& pass) : id(uname), password(pass) {}

void User::mainMenu() {
    cout << "Welcome to the main page of Smart Library Management System." << endl;
	cout << "Please select your type:" << endl;
}

// Constructor for user class. 