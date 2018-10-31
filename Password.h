#ifndef _Password_
#define _Password_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
class Password
{
    
private:
    std::string name_of_password;
    std::string actual_password;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string numbers = "0123456789";
    std::string symbols = "~`!@#$%^&*()-_+={}[]<>,./?";
   bool lower_case = false;
    bool upper_case = false;
    bool include_numbers = false;
    bool include_symbols = false;

public:
    Password(std::string name_of_password);

    const std::string& GetActualPassword() const
    {
        return actual_password;
    }
    const std::string& GetNameOfPassword() const
    {
        return name_of_password;
    }

    Password& SetIncludeNumbers(bool include_numbers)
    {
        this->include_numbers = include_numbers;
        return *this;
    }
    Password& SetIncludeSymbols(bool include_symbols)
    {
        this->include_symbols = include_symbols;
        return *this;
    }
    Password& SetLowerCase(bool lower_case)
    {
        this->lower_case = lower_case;
        return *this;
    }
    Password& SetUpperCase(bool upper_case)
    {
        this->upper_case = upper_case;
        return *this;
    }
    bool IsIncludeNumbers() const
    {
        return include_numbers;
    }
    bool IsIncludeSymbols() const
    {
        return include_symbols;
    }
    bool IsLowerCase() const
    {
        return lower_case;
    }
    bool IsUpperCase() const
    {
        return upper_case;
    }

    void enableAll();
    void shuffle_elements();
    
    void generate_lowcase_letter();
    void generate_uppcase_letter();
    void generate_number();
    void generate_symbol();
    void write_to_file();
    bool check_if_everything_is_false();
    ~Password();
};

#endif // _Password_
