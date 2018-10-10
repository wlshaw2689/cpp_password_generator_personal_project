#include <iostream>

int main(){
    /*
     * 
     * Hello and welcome to the password generator.
     * Alright so what do I want this password generator to do?
     * U
     * */
     int choice;
     std::cout << "Hello and welcome to the prototype build of the password generator\n";
     std::cout << "As of right now, we have only two options.\n";
     std::cout << "1: Create a new password\n" << 
                            "2: Retrieve a password based on the name\n";
    std::cout << "Please enter your choice: ";
    std::cin >> choice;
    /*
     * 
     * Going to test something first before I make my decision.
     * Testing to see which would be better
     * Looping through a string?
     * Looping through an array of characters?
     * Looping through a vector of characters?
     * */
    
    
    switch(choice){
        case 1:
                //Create the new password;
        case 2:
                //Retrieve existing password;
    }
    return 0;
}
