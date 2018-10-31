#include "Password.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//********Function Prototypes******//
int print_menu();
void create_password(Password* password, int length); // Reference them since
void make_choices(Password* password);
void write_to_file(Password* password);

int main()
{
    int choice = print_menu();
    
    switch(choice) {
    case 1: {
        std::cout << "How long do you want your password to be?";
        int length_of_password;
        std::cin >> length_of_password;
        std::cout << "What would you like the name of this password to be: ";
        std::string name_of_password;
        std::cin.ignore();
        std::getline(std::cin, name_of_password);
        Password* password = new Password{name_of_password};
        create_password(password, length_of_password);
        std::cout << "The name of the password is: " << password->GetNameOfPassword() << std::endl;
        std::cout << "The actual password is: " << password->GetActualPassword() << std::endl;
        std::cout << "Length of password is: " << password->GetActualPassword().length() << std::endl;
        password->write_to_file();
        delete password;

        break;
    }
    case 2:
        break;
        // Retrieve existing password;
    }
    std::cout << "End of main scope" << std::endl;
    return 0;
}

/// Menu function: Displays the menu of the program. Reads input from user and returns an int///
int print_menu()
{
    int choice;
    std::cout << "Hello and welcome to the prototype build of the password generator\n";
    std::cout << "As of right now, we have only two options.\n";
    std::cout << "1: Create a new password\n"
              << "2: Retrieve a password based on the name\n";
    std::cout << "Please enter your choice: ";
    std::cin >> choice;
    system("CLS");
    return choice;
}

void create_password(Password* password, int length)
{
    std::cout << "For your password, you can choose the following:\n"
              << "numbers, symbols, and letters(both upper and lower case) " << std::endl;
    std::cout << "Press 1 to add numbers\n" 
                   << "2 to add symbols\n"
                   << "3 for lower case\n" 
                   << "4 for upper case\n" 
                   << "5 to include all choices in your password. " << std::endl;
    std::cout << "When you are done, type 0 for done." << std::endl;
    system("CLS");
    make_choices(password);
    std::vector<int> functions;
    int count = 0;
    if(password->IsIncludeNumbers()){
        functions.push_back(0);
        password->generate_number();
        count++;
    }
    if(password->IsIncludeSymbols()){
        functions.push_back(1);
        password->generate_symbol();
        count++;
    }
    if(password->IsLowerCase()){
        functions.push_back(2);
        password->generate_lowcase_letter();
        count++;
    }
    if(password->IsUpperCase()){
        functions.push_back(3);
        password->generate_uppcase_letter();
        count++;
    }

    for(int i = 0; i < length - count; i++) {
        int random_num = rand() % functions.size();
        
        switch(functions.at(random_num)) {
        case 0:
            password->generate_number();
            break;
        case 1:
            password->generate_symbol();
            break;
        case 2:
            password->generate_lowcase_letter();
            break;
        case 3:
            password->generate_uppcase_letter();
            break;
        }
    }
    password->shuffle_elements();
}

void make_choices(Password* password)
{
    bool done = false;
    do {
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        switch(choice) {
        case 0:
            if(password->check_if_everything_is_false()){
                std::cout << "You did not choose any of the options.\n ";
            }
            else
                done = true;
            break;
        case 1:
            password->SetIncludeNumbers(true);
            std::cout << "Numbers will be added." << std::endl;
            break;
        case 2:
            password->SetIncludeSymbols(true);
            std::cout << "Symbols will be added." << std::endl;
            break;
        case 3:
            password->SetLowerCase(true);
            std::cout << "Lower case letters will be added" << std::endl;
            break;
        case 4:
            password->SetUpperCase(true);
            std::cout << "Upper case letters will be added" << std::endl;
            break;
        case 5:
            password->enableAll();
            std::cout << "Everything will be added" << std::endl;
            break;
        default:
            std::cout << "Invalid response, try again" << std::endl;
            break;
        }
    } while(!done);
    system("CLS");
}

