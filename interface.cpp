/*
*   Si klase skirta saveikauti su vartotoju per terminalo sąsają.
*   Veikia kaip gidas kuris nusako, kas kaip veiks programuoje.
*/
#include <iostream>

#include "interface_.h"
#include "login_.h"
#include "obtainUser_.h"
#include "bankAccount_.h"
#include "transactions_.h"
#include "user_.h"
#include "reader_from_csv_.h"
#include "writer_to_csv_.h"

using namespace std;

/*
*	Class responsible for managing the user interface and coordinating interactions between different classes.
*/
Interface::Interface()  {}

/*
*	Method for displaying the initial interface screen.
*	Prints a welcome message centered on the screen.
*/
void Interface::interfaceLoad() {
    int terminalWidth = 80;
    int  terminalHeight = 5; 
    
  
    // Positioning calculation
    int messageWidth = 27;  // Length of the message
    int padding = (terminalWidth - messageWidth) / 2;

    // Printing empty lines
    for (int i = 0; i < (terminalHeight / 2) - 1; i++) {
        cout << endl;
    }

    // Positioning before the text
    for (int i = 0; i < padding; i++) {
        cout << " ";
    }
        cout << "Hello, welcome to your terminal" << endl;
}

/*
*	Method for guiding the user through the interface.
*	Prompts the user to choose an action: login, create an account, or exit the program.
*	Based on the choice, it calls the respective interface method.
*	Parameters:
*	- users: Reference to the vector of User objects.
*	- accounts: Reference to the vector of BankAccount objects.
*/
void Interface::interfaceGuide(vector<User>&users, vector<BankAccount>&accounts) {

    int choice;

    cout << endl << "Do you have an accout?" << endl;
    cout << endl << "1. Login in" << endl;
    cout << endl << "2. Create account" << endl;
    cout << endl << "3. Exit program" << endl << endl;
    cin >> choice;

    // Clearing the terminal
    cout << "\033[2J\033[H";

    if (choice == 1) {

        // Create a Login object and initiate the login process
       Interface::interfaceLogin(users, accounts);

    }
    else if (choice == 2) {

        // Create a new user account
        Interface::interfaceCreateUser(users, accounts);

    }
    else if (choice == 3) {

        // Exit the program

    }
}
/*
*	Method for handling the user login process.
*	Creates a Login object, prompts the user for login information, and checks if the login matches any user.
*	If the login is successful, calls the interfaceTransfer method to perform account transactions.
*/
void Interface::interfaceLogin(vector<User>&users, vector<BankAccount>&accounts) { 
   
    Login login;
    
    login.ioCreateLogin();
    int i = login.isItMatches(users);

    if (i >= 0) {
        i--;
        if (i < accounts.size()) {
            
            cout << "Login succesful. " << i;
            Interface::interfaceTransfer(accounts[i], accounts);
        }
        else {
            cout << "Error: Invalid index for accounts vector. ";
        }
    }
    else {
        cout << "Login failed, there is no such user.";
    }
    
}

/*
*	Method for handling the account transactions interface.
*	Allows the user to perform various transactions: deposit, withdrawal, transfer, or view balance.
*	Continuously prompts the user for a choice until they choose to exit.
*	Parameters:
*	- account: Reference to the BankAccount object representing the logged-in account.
*	- accounts: Reference to the vector of BankAccount objects.
*/
void Interface::interfaceTransfer(BankAccount account, vector<BankAccount>& accounts) {

    Transactions transfer(account);
    account.disp();

    int recipientID;
    int choice = 0;

    while (choice != 5) {
        cout << "\033[2J\033[H";
        cout << " Your balance is: " << account.getBalance();
        transfer.printOptions();
        cin >> choice;
   
        if (choice == 1) {
            transfer.deposit();
            cout << transfer.getBalance();
        }
        else if (choice == 2) {
            transfer.withdrawal();
            cout << transfer.getBalance();
        }
        else if (choice == 3) {
            transfer.transferTo(account, accounts);
            cout << transfer.getBalance();
        }
        else if (choice == 4) {
            cout << account.getBalance();

        }
    }
}

/*
*	Method for handling the user account creation process.
*	Creates an ObtainingUser object, prompts the user for account information, creates a new User object,
*	and adds it to the users vector. Also creates a corresponding BankAccount object and adds it to the accounts vector.
*	Writes the account information to a CSV file using the Writer class.
*	After successful account creation, calls the interfaceLogin method to proceed with login.
*	Parameters:
*	- users: Reference to the vector of User objects.
*	- accounts: Reference to the vector of BankAccount objects.
*/
void Interface::interfaceCreateUser(vector<User>& users, vector<BankAccount>& accounts) {

    ObtainingUser obtainingUser;
    obtainingUser.ioCreateUser();

    User a = obtainingUser.createUserObject();
    cout << "User created " << endl;

    BankAccount c(a);
    const User* retrieveUser = c.getUser();

    cout << "User name :" << retrieveUser->getName() << endl;
    cout << "User id: " << retrieveUser->getId() << endl;
    users.push_back(a);
    accounts.push_back(c);

    Writer write("Data_.csv");
    write.writeFile(accounts);

    Interface::interfaceLogin(users, accounts);
      
}

/*
*	Method for reading user information from a CSV file.
*	Creates a Reader object, opens the file, reads the lines, closes the file, and returns the vector of User objects.
*/
vector<User>Interface::readUsers() {

    Reader read("data.csv");
    read.openReadFile();

    vector<User>list = read.readLines();
    read.closeReadFile();

    return list;

}