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



int main() {

    if (User::accounts.empty())

        // Admin can add user accounts here.
    {

        User::accounts.push_back(new Member("user1", "password1"));
        User::accounts.push_back(new Member("user2", "password2"));
        User::accounts.push_back(new Member("user3", "password3"));
        User::accounts.push_back(new Member("user4", "password4"));
        User::accounts.push_back(new Member("user5", "password5"));

    }

    // Create a library collection as a vector of Book objects.
    //Admin can add book titles. Librarian is also able to add them.

    vector<Book> library;
    library.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald"));
    library.push_back(Book("To Kill a Mockingbird", "Harper Lee"));
    library.push_back(Book("1984", "George Orwell"));
    library.push_back(Book("Pride and Prejudice", "Jane Austen"));
    library.push_back(Book("The Catcher in the Rye", "J.D. Salinger"));

    // Display the main user selection menu.


    int userSelection = 0;  //User choice will be stored once they select it. 
    do
    {
        User::userMenu();    //This will display the user menu
		cin >> userSelection;    //User's selection collected here.
        cin.ignore();



        if (userSelection == 4) {
            cout << "Application is closing." << endl;
            break;
        }

        // Appliation closes if user selects option 4.

        // Ask the user to enter id and password.
        string userId, userPassword;
        cout << "Please enter your user id: ";
        getline(cin, userId);
        cout << "Please enter your password: ";
        getline(cin, userPassword);


        User* loggedinUser = nullptr;
        if (userSelection == 1) { // Member
            for (User* u : User::accounts) {
                if (u->getId() == userId && u->getPassword() == userPassword) {
                    if (dynamic_cast<Member*>(u) != nullptr) {  // This will check if the user is a member.
                                                                // It's important because only members should login here, not admins/librarians.
                        loggedinUser = u;
                        break;
                    }
                }
            }
            if (loggedinUser == nullptr) {
                cout << "Invalid Member credentials. Please try again." << endl;
                continue; //The user can try again to login
            }
        }

        else if (userSelection == 2) { 
            if (userId == "SLMS_Librarian" && userPassword == "secretlib123") {
				//These are login credentials for librarian.
                
                for (User* u : User::accounts) {
					if (u->getId() == userId && dynamic_cast<Librarian*>(u) != nullptr) {   //Dyanmic cast makes sure user is a librarian.
                        loggedinUser = u;
                        break;
                    }
                }
               
                if (loggedinUser == nullptr) {
                    loggedinUser = new Librarian(userId, userPassword);
                    User::accounts.push_back(loggedinUser); 
                }
            }

            else {
                cout << "Invalid Admin credentials. Please try again." << endl;
				continue; // This allowws the librarian to try again.
            }

        }


        else if (userSelection == 3) { // Admin
            
            if (userId == "SLMS_Admin" && userPassword == "secretpass123.abc") {
                
                for (User* u : User::accounts) {
                    if (u->getId() == userId && dynamic_cast<Admin*>(u) != nullptr) {
                        loggedinUser = u;
                        break;
                    }
                }
                if (loggedinUser == nullptr) {
                    loggedinUser = new Admin(userId, userPassword);
                    
                    User::accounts.push_back(loggedinUser);
                }
            }
            else {
                cout << "Invalid Admin credentials. Please try again." << endl;
                continue;
            }

			// Similar logic like member and librarian is used here.
        }
        else {
            cout << "Invalid selection. Please try again." << endl;
            continue;
        }

        cout << "\nHello, " << loggedinUser->getId() << "!\n";

        
        if (dynamic_cast<Admin*>(loggedinUser)) {
            // For Admin, mainMenu() calls adminActions()
            loggedinUser->mainMenu();
        }
        else if (dynamic_cast<Librarian*>(loggedinUser)) {
            
            dynamic_cast<Librarian*>(loggedinUser)->librarianActions(library);
            // Librarian function appears once librarian logs in.
        }
        else if (dynamic_cast<Member*>(loggedinUser)) {
            dynamic_cast<Member*>(loggedinUser)->memberActions(library);
			// Member function appears once member logs in.
        }

        

    } while (userSelection != 4);

    
    for (User* u : User::accounts)
        delete u;
    User::accounts.clear();

    return 0;
}

