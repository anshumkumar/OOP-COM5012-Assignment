#include <iostream>
#include <string>
#include <vector>
#include "User.h"   
#include "Member.h"
#include "Librarian.h"
#include "Admin.h"
#include "Book.h"
#include <fstream>
#include <sstream>

using namespace std;

// Assuming User::accounts is declared as a static vector in User.h
// e.g., in User.h, you might have: 
//   static vector<User*> accounts;

int main() {

    // Create some default accounts (for testing purposes)
    User::accounts.push_back(new Member("user1", "password1"));
    User::accounts.push_back(new Member("user2", "password2"));
    User::accounts.push_back(new Member("user3", "password3"));
    User::accounts.push_back(new Member("user4", "password4"));
    User::accounts.push_back(new Member("user5", "password5"));

    // Create a library collection as a vector of Book objects.
    vector<Book> library;
    library.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald"));
    library.push_back(Book("To Kill a Mockingbird", "Harper Lee"));
    library.push_back(Book("1984", "George Orwell"));
    library.push_back(Book("Pride and Prejudice", "Jane Austen"));
    library.push_back(Book("The Catcher in the Rye", "J.D. Salinger"));

    // Display the main user selection menu.
    User::userMenu();
    int userSelection = 0;
    cin >> userSelection;
    cin.ignore();

    if (userSelection == 4) {
        cout << "Application is closing." << endl;
        return 0;
    }

    // Ask the user to enter id and password.
    string userId, userPassword;
    cout << "Please enter your user id: ";
    getline(cin, userId);
    cout << "Please enter your password: ";
    getline(cin, userPassword);

    User* userType = nullptr;

    switch (userSelection) {
    case 1:
        cout << "\nYou are logged in as Member" << endl;
        if ((userId == "user1" && userPassword == "password1") ||
            (userId == "user2" && userPassword == "password2") ||
            (userId == "user3" && userPassword == "password3") ||
            (userId == "user4" && userPassword == "password4") ||
            (userId == "user5" && userPassword == "password5")) {
            userType = new Member(userId, userPassword);
        }
        else {
            cout << "Invalid login details. Application is closing." << endl;
            return 1;
        }
        break;
    case 2:
        cout << "\nYou are logged in as Librarian" << endl;
        userType = new Librarian(userId, userPassword);
        break;
    case 3:
        cout << "\nYou are logged in as Admin" << endl;
        if (userId == "SLMS_Admin" && userPassword == "secretpass123.abc") {
            userType = new Admin(userId, userPassword);
        }
        else {
            cout << "Invalid login details. Application is closing." << endl;
            return 1;
        }
        break;
    default:
        cout << "Invalid selection. Application is closing." << endl;
        return 1;
    }

    cout << "\nHello, " << userId << "\n";

    // If the user is a Member, call memberActions (which accepts the library).
    // For other types, just call mainMenu.
    Member* mPtr = dynamic_cast<Member*>(userType);
    if (mPtr != nullptr) {
        mPtr->memberActions(library);
    }
    else {
        userType->mainMenu();
    }

    delete userType;
    // Clean up the accounts created under the User class.
    for (User* u : User::accounts)
        delete u;
    User::accounts.clear();

    return 0;
}

