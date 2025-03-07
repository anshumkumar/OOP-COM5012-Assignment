#include "Admin.h"
#include "User.h"
#include "Member.h"
#include "Librarian.h"

void Admin::adminActions()
{
    {
        int adminselection = 0;

        do {
            cout << "Select an option below" << endl;
            cout << " 1. Create a user account " << endl;
            cout << " 2. Logout of the system" << endl;
            cin >> adminselection;
            cin.ignore();

            if (adminselection == 1) {
                cout << "Enter the user id: ";
                string addId;
                getline(cin, addId);

                cout << "Enter the password: ";
                string userPass;
                getline(cin, userPass);

                cout << "Select the type of account you want to create" << endl;
                cout << "1. Member" << endl;
                cout << "2. Librarian" << endl;

                int admChoice;
                cin >> admChoice;

                if (admChoice == 1) {
                    accounts.push_back(new Member(addId, userPass));
                    cout << "Member account created successfully for " << addId << endl;
                }
                else if (admChoice == 2) {
                    accounts.push_back(new Librarian(addId, userPass));
                    cout << "Librarian account created successfully for " << addId << endl;

                }
                else {
                    cout << "Invalid selection. Please try again" << endl;
                }

            }
            else if (adminselection != 2) {
                cout << "Invalid selection. Please try again" << endl;
            }
        } while (adminselection != 2);
    }
}
