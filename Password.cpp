#include "Password.h"
#include <iostream>
#include <string>

Password::Password(std::string name_of_password)
    :name_of_password{name_of_password}
{
    srand(time(0));
}
void Password::enableAll(){
    SetIncludeNumbers(true);
    SetIncludeSymbols(true);
    SetLowerCase(true);
    SetUpperCase(true);
}

void Password::generate_lowcase_letter(){
    int position = rand() % alphabet.length();
    char gen_letter = alphabet.at(position);
    actual_password += gen_letter;
}

void Password::generate_uppcase_letter(){
   int position = rand() % alphabet.length();
    char gen_letter = toupper(alphabet.at(position));
    actual_password += gen_letter;
}

void Password::generate_number(){
    int position = rand() % numbers.length();
    char gen_num = numbers.at(position);
    actual_password += gen_num;
}

void Password::generate_symbol(){
    int position = rand() % symbols.length();
    char gen_sym = symbols.at(position);
    actual_password += gen_sym;
}

bool Password::check_if_everything_is_false(){
   return  ((!lower_case && !upper_case && !include_numbers && !include_symbols ) ? true : false);
}


Password::~Password()
{

}

