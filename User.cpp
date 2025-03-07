#include "User.h"
#include <iostream>
#include <string>
#include <vector>

vector<User*> User::accounts;

User::User(const string& uname, const string& pass) : id(uname), password(pass) {}

// Constructor for user class. 