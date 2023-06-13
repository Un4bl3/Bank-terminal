#include "interface_.h"
#include "login_.h"
#include "obtainUser_.h"
#include "bankAccount_.h"
#include "transactions_.h"
#include "user_.h"
#include <iostream>
using namespace std;
Interface::Interface()
{
    //ObtainingUser obtainingUser;
    //Login login;
}

void Interface::interfaceLoad()
{
    int terminalWidth = 80;
    int  terminalHeight = 5; 
    
  
    // Calculate the position for the message
    int messageWidth = 27;  // Width of the message "Hello, welcome to your terminal"
    int padding = (terminalWidth - messageWidth) / 2;

    // Print empty lines to position the message vertically
    for (int i = 0; i < (terminalHeight / 2) - 1; i++) {
        cout << endl;
    }

    // Print the message with padding
    for (int i = 0; i < padding; i++) {
        cout << " ";
    }
        cout << "Hello, welcome to your terminal" << endl;
}
/* Metodas kuris iskviecia skirtingus metodus priklausomai nuo vartotojo pasirinkimo 
*
*/
void Interface::interfaceGuide() {
    int choice;
    cout << endl << "Do you have an accout?";
    cout << endl << "1. Login in";
    cout << endl << "2. Sign in" << endl;
    cin >> choice;
    // clear screen
    cout << "\033[2J\033[H";
    if (choice == 1) {
    //use ioLogin in member functions

    // Create login obj
    Login login;
    login.ioCreateLogin();
    // Verify whether it matches for alphabet
    // For no there is no Users created 
    /*
    char currentChar = 'a';
    while (currentChar <= 'z') {
        if (login.isItMatches(currentChar)) {
            cout << "good";
            break;
        }
        else {

        }
    }
   */
    // Access granted

    // Access denied
    }
    else if (choice == 2) {
        Interface::interfaceCreateUser();
    }
}

void Interface::interfaceLogin(User a, BankAccount c)
{
    Login login;
    login.ioCreateLogin();
    if (login.isItMatches(a)) {
        cout << "\033[2J\033[H";
        Interface::interfaceTransfer(c);
    };
    
}
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
    Interface::interfaceLogin(a, c);
    
}