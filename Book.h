#pragma once

#include<iostream>
#include<string>        
#include<vector>

using namespace std;


class Book {    //First class in SLM system, book class.
private:        // Private memvers added, encapsulation. 
    string title;
    string author;
    string status;
public:      // public members.
    Book(const string& t, const string& a, const string& s = "Available")
    : title(t), author(a), status(s) {}

    // get functions.

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getStatus() const { return status; }

    // set status function for setting the book status. 
    void setStatus(const string& s) { status = s; }

    // Borrow book function

    void borrowBook(); 

    // Function for returning a book

    void returnBook();

    void reserveBook();

    void searchBook() const;

	void display() const;
};

