#pragma once
#include<iostream>
#include<string>        
#include<vector>

using namespace std;

vector<class User*> accounts;

class User
{
    //2nd class in the system, user class. 
    // Other classes will inherit features from this.
    protected:       
        // Id and password are kept protected. They can't be accessed in other classes.
        string id;
        string password;

    public:
        User(const string & uname, const string & pass) : id(uname), password(pass) {}
        virtual ~User() = default;

        virtual void mainMenu() = 0;

        // Get functions.

        const string& getId() const { return id; }
        const string& getPassword() const { return password; }

        // main menu.

        static void userMenu() {
            cout << "Welcome to SMART LIBRARY MANAGEMENT SYSTEM" << endl;
            cout << "Please select a user type:" << endl;
            cout << "1. Member" << endl;
            cout << "2. Librarian" << endl;
            cout << "3. Admin" << endl;
            cout << "4. Exit" << endl;
        }
};
