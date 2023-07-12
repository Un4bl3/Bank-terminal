/*
*   Si klase skirta saveikauti su vartotoju per terminalo sąsają.
*   Veikia kaip gidas kuris nusako, kas kaip veiks programuoje.
*/
#include "interface_.h"
#include "login_.h"
#include "obtainUser_.h"
#include "bankAccount_.h"
#include "transactions_.h"
#include "user_.h"
#include "reader_from_csv_.h"
#include <iostream>
using namespace std;

/*
*   Pagrindinis konstruktorius. Kuriane bandyta inicilizuoti pagrindinius objektus.
*/
Interface::Interface()
{
    //ObtainingUser obtainingUser;
    //Login login;
}
/*
*   Metodas skirtas ikrauti sveikinimo teksta
*/
void Interface::interfaceLoad()
{
    int terminalWidth = 80;
    int  terminalHeight = 5; 
    
  
    // Pozicijos nustatymas
    int messageWidth = 27;  // Kiek ilgas bus tekstas
    int padding = (terminalWidth - messageWidth) / 2;

    // Tusciuju eiluciu ispausdinimas
    for (int i = 0; i < (terminalHeight / 2) - 1; i++) {
        cout << endl;
    }

    // vieta pries teksta
    for (int i = 0; i < padding; i++) {
        cout << " ";
    }
        cout << "Hello, welcome to your terminal" << endl;
}
/* 
*    Metodas kuris iskviecia skirtingus metodus priklausomai nuo vartotojo pasirinkimo 
*/
void Interface::interfaceGuide(vector<User>&users) {
    int choice;
    cout << endl << "Do you have an accout?";
    cout << endl << "1. Login in";
    cout << endl << "2. Sign in" << endl;
    cin >> choice;
    // terminalo isvalymas
    cout << "\033[2J\033[H";
    if (choice == 1) {

    // Login objekto sukurimas
       Interface::interfaceLogin(users);



    }
    else if (choice == 2) {
        Interface::interfaceCreateUser();
    }
}
/*
*  Metodas Login moduliui sukurimui 
*/
void Interface::interfaceLogin(vector<User>&users)
{
    Login login;
    login.ioCreateLogin();
    if (login.isItMatches(users)) {
        cout << "we done";
       // cout << "\033[2J\033[H";
       // Interface::interfaceTransfer(c);
    }
    else {
        cout << "It's wrong";
    }
    
}
/*
*  Metodas sukurti moduliu pinigu keliavimui
*/
void Interface::interfaceTransfer(BankAccount c) {
    Transactions show(c);
    int choice;
    cout << endl << "What you want to do?" << endl;
    cout << endl << "1. Deposit";
    cout << endl << "2. Withdrawl";
    cout << endl << "3. Transfer";
    cout << endl << "4. Show balance";
    cout << endl << "5. Get back" << endl;
    cin >> choice;
        if (choice == 1) {
            show.deposit();
            cout << show.getBalance();
        }
        else if (choice == 2) {
            show.withdrawl();
            cout << show.getBalance();
        }
        else if (choice == 3) {
            //show.transfer(recipient);
            cout << show.getBalance();
        }
        else if (choice == 4) {
            cout << show.getBalance();
        }
}
/*
*   Metodas skirtas vartotojo sukurimui
*/
void Interface::interfaceCreateUser()
{
    ObtainingUser obtainingUser;
    obtainingUser.ioCreateUser();

    User a = obtainingUser.createUserObject();
    cout << "user created" << endl;
    BankAccount c(a);
    const User* retrieveUser = c.getUser();
    cout << "User name :" << retrieveUser->getName() << endl;
    cout << "User id: " << retrieveUser->getId() << endl;
    //Interface::interfaceLogin(a, c);
    
}
/*
*   Method for reading csv file using class Read
*   ReturnType is vector<User> for bringing back the vector
*/
std::vector<User>Interface::readUsers() {
    Reader read("data.csv");
    read.openReadFile();
    vector<User>list = read.readLines();
    read.closeReadFile();
    return list;
}