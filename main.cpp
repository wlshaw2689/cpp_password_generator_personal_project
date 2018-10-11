#include <iostream>
#include <string>
#include <memory>
#include "Password.h"

//********Function Prototypes******//
int print_menu();

int main(){
    /*
     * 
     * Hello and welcome to the password generator.
     * Alright so what do I want this password generator to do?
     * U
     * */
     int choice = print_menu();
   
    /*
     * 
     * Going to test something first before I make my decision.
     * Testing to see which would be better
     * Looping through a string?
     * Looping through an array of characters?
     * Looping through a vector of characters?
     *
     * After testing things, it seems there was no difference. A vector of characters in not needed. I will be going with the string
     * Do I want to use resize?
     * */
    
    
    switch(choice){
        case 1:{
                std::cout << "How long do you want your password to be?";
                int length_of_password;
                std::cin >> length_of_password;
                std::cout << "What would you like the name of this password to be? ";
                std::string name_of_password;
                std::cin.ignore();
                std::getline(std::cin, name_of_password);
                std::unique_ptr<Password> password = std::make_unique<Password>(name_of_password, length_of_password);
                std::cout << password->GetNameOfPassword() << std::endl;
                std::cout << "Length of pasword: " << password->GetActualPassword().length() << std::endl;
                break;
        }
        case 2:
            break;
                //Retrieve existing password;
    }
    return 0;
}


int print_menu(){
    int choice;
    std::cout << "Hello and welcome to the prototype build of the password generator\n";
    std::cout << "As of right now, we have only two options.\n";
    std::cout << "1: Create a new password\n" << 
                            "2: Retrieve a password based on the name\n";
    std::cout << "Please enter your choice: ";
    std::cin >> choice;
    return choice;
    
}
