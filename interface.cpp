#include "interface_.h"
#include <iostream>
using namespace std;
Interface::Interface()
{
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

}

void Interface::interfaceLogin()
{

}

void Interface::interfaceCreateUSer()
{
}