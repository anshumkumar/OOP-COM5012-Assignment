#include "Book.h"

Book::Book(const string& t, const string& a, const string& s)
{
    // these letters provide reference to title, author and status.
    title = t;
    author = a;
    status = s;
}

void Book::borrowBook()
{

    if (status == "Available") {    // If book is available
        status = "Borrowed";        // its status can become borrowed.
        cout << "You have borrowed the book, here are the detils:" << title << endl;
    }            // Therefore, we can display the message to user that book has been borrowed.
    else {
        cout << "Sorry, the book " << title << "is not avalable for borrowing, try again later." << endl;
    }    // If book is not available or borrowed by someone else, then this message will be displayed.
}

void Book::returnBook()
{
    {
        if (status == "Borrowed") {   //If book is already borrowed
            status = "Available";     // Then change the book's status to available, when its returned
            cout << "Book has been returned, thank you " << title << "Returned." << endl;
        }
        else {
            cout << "You have not borrowed this book." << title << endl;
        }     // This message will be displayed when the book is returned/
    }
}

void Book::reserveBook()
{
    {   // Function for reserving a boOk

        if (status == "Available") {   // If book is available
            status = "Reserved";    // Then change the status of the book to reserved
            cout << "You have reserved the book, here are the detils:" << title << endl;
        }
        else {
            cout << "Sorry, the book " << title << "is not avalable for reservation curently, try later." << endl;
        }    //This message will then be displayed.
    }
}
