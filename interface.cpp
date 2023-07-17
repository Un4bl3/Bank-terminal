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
#include "writer_to_csv_.h"
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
void Interface::interfaceGuide(vector<User>&users, vector<BankAccount>&accounts) {
    int choice;
    cout << endl << "Do you have an accout?" << endl;
    cout << endl << "1. Login in" << endl;
    cout << endl << "2. Create account" << endl;
    cout << endl << "3. Exit program" << endl;
    cin >> choice;
    // terminalo isvalymas
    cout << "\033[2J\033[H";
    if (choice == 1) {

    // Login objekto sukurimas
       Interface::interfaceLogin(users, accounts);



    }
    else if (choice == 2) {
        Interface::interfaceCreateUser(users, accounts);
    }
    else if (choice == 3) {

    }
}
/*
*  Metodas Login moduliui sukurimui 
*/
// REDESIGN THIS PART
void Interface::interfaceLogin(vector<User>&users, vector<BankAccount>&accounts)
{ 
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
*  Metodas sukurti moduliu pinigu keliavimui
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
            transfer.withdrawl();
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
*   Metodas skirtas vartotojo sukurimui
*/
void Interface::interfaceCreateUser(vector<User>& users, vector<BankAccount>& accounts)
{
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
    Writer write("Data_06.15.csv");
    write.writeFile(accounts);

    Interface::interfaceLogin(users, accounts);
    
   
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