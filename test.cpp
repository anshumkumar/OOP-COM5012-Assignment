#include <iostream>
#include <vector>
#include "User.h"   
#include "Member.h"
#include "Librarian.h"
#include "Admin.h"
#include "Book.h"
using namespace std;

vector<class User*> accounts;

int main() {
	//vector<Book*> books;  //Have a look at this line later.
 //   books.push_back(new Book("Title1", "Author1", "Available"));

    int userSelection = 0;

    Admin user1("SLMS_Admin", "123");
    // This will display the main menu.
    user1.userMenu();
    cin >> userSelection;
    cin.ignore();

    if (userSelection == 4) {
        cout << "Application is closing." << endl;
        return 0;
    }

    string userId, userPassword;
    cout << "Please enter your user id: ";
    getline(cin, userId);

    cout << "Please enter your password: ";
    getline(cin, userPassword);

    User* userType = nullptr;

    switch (userSelection) {
    case 1:
        cout << "\nYou are logged in as Member" << endl;
        userType = new Member(userId, userPassword);
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

    userType->mainMenu();

    return 0;
}
