#pragma once
#include<iostream>
#include<string>        
#include<vector>


using namespace std;

//vector<class User*> accounts;  I think this is needed in test file.

class User
{
    //2nd class in the system, user class. 
    // Other classes will inherit features from this.
    protected:       
        // Id and password are kept protected. They can't be accessed in other classes.
        string id;
        string password;

    public:
		// de constructor
        User(const string& uname, const string& pass);
        virtual ~User() = default;

		virtual void mainMenu() = 0; //used for polymorphism. 
                                     // different members will have their own menu. They will override this.

        // Get functions.

        const string& getId() const { return id; }
        const string& getPassword() const { return password; }

        

        

        // main menu for every user.
        //this allows the person on system to choose an account type for login.

        static void userMenu() {
            cout << "Welcome to SMART LIBRARY MANAGEMENT SYSTEM" << endl;
            cout << "Please select a user type:" << endl;
            cout << "1. Member" << endl;
            cout << "2. Librarian" << endl;
            cout << "3. Admin" << endl;
            cout << "4. Exit" << endl;
        }

        static vector<User*> accounts;  //Used to store accounts


};
