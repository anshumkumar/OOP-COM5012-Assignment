#pragma once
#include "User.h"

#include<iostream>
#include<string>        
#include<vector>

using namespace std;

class Admin : public User
{
public:
    Admin(const string& uname, const string& pass) : User(uname, pass) {}

    void adminActions();

	void mainMenu() override {   //Polymorphism is used here. admin will have its own menu.
                                 //admin actions overrides main menu.
        adminActions();
    }



};

