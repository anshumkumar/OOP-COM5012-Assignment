#include "Book.h"


// Function definition for searchBook
void Book::searchBook() const {
    cout << "Searching for book: " << title << " by " << author << endl;
}
// Function to borrow a book
void Book::borrowBook() {
    if (status == "Available") {
        status = "Borrowed";   //status is changed to borrowed/
        cout << "You have borrowed the book: " << title << endl;
    }
    else {
        cout << "Sorry, the book \"" << title << "\" is not available for borrowing." << endl;
    }
}

// Return book function
void Book::returnBook() {
    if (status == "Borrowed") {
        status = "Available";
        cout << "You have returned the book: " << title << endl;
    }
    else {
        cout << "The book \"" << title << "\" is not currently borrowed." << endl;
    }
}

// Reserve book function
void Book::reserveBook() {
    if (status == "Available") {
        status = "Reserved";   //changes status to reserved.
        cout << "You have reserved the book: " << title << endl;
    }
    else {
        cout << "Sorry, the book \"" << title << "\" is not available for reservation." << endl;
    }
}

// function for displaying book details
void Book::display() const {
    cout << "Title: " << title << ", Author: " << author
        << ", Status: " << status << endl;
}
