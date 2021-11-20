#include <iostream>
#include <string>
#include "User.h"
#include "Auth.h"
#include "CSVfileHandler.h"
#include "program.h"
using namespace std;

/*
* Main method
* To compile - "g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o test2.out main.cpp"
* Compilation will create an executable test2.out file
* To run the Executable file - "./test2.out"
* If get a compilation error refer Auth.h file
*/
int main() {
    
    Auth auth;
    User user;
    string username, password;

    // Read username
    cout<<"Enter username: ";
    cin>>username;

    // Read password
    cout<<"Enter password: ";
    cin>>password;

    try {
        user = auth.login(username, password);
        cout<<"Logged as "<<user.getName()<<endl;
    } catch(invalid_argument &e) {
        cerr<<e.what()<<endl;
        return 1;
    }
    program(user);
    return 0;
}