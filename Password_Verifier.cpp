/*
    Gaddis Programming Challenge 10.12 - Password Verifier

    Imagine you are developing a software package that requires users to enter
    their own passwords. Your software requires that user's passwords meet the
    following criteria:

    - The password should be at least 6 characters long
    - The password should contain at least one uppercase and at least one lowercase
    - The password should have at least one digit
    - The password should have at least one special character*  (my adaptation)

    Write a program that asks for a password and then verifies that it meets the
    stated criteria. If it doesn't the program should display a message telling
    the user why.
*/


#include <iostream>
#include <cstdlib>   // EXIT_SUCCESS
#include <string>
#include <cstring>   // strlen()
#include <cctype>    // isupper(), islower()

char *convertToCString(std::string);
bool isSixCharsPlus(char *);
bool existsUppercase(char *);
bool existsLowercase(char *);
bool existsDigit(char *);
bool existsSpecChar(char *);

int main() {

    std::string strObj = " ";
    char *pwd = nullptr;

    std::cout << "\n\n\t\tEnter your password: ";
    getline(std::cin, strObj);

    pwd = convertToCString(strObj);

    while (isSixCharsPlus(pwd) || existsUppercase(pwd) || existsLowercase(pwd) ||
           existsDigit(pwd) || existsSpecChar(pwd))
    {
        if (isSixCharsPlus(pwd) == true)
        {
            std::cout << "\t\tPassword does not contain six or more characters! "
                      << "Please try again.";
            std::cout << "\n\t\tEnter your password: ";
            getline(std::cin, strObj);
            pwd = convertToCString(strObj);
            if (isSixCharsPlus(pwd) == false)
                continue;

        }

        if (existsUppercase(pwd) == true)
        {
            std::cout << "\t\tPassword does not contain at least one uppercase letter! "
                      << "Please try again.";
            std::cout << "\n\t\tEnter your password: ";
            getline(std::cin, strObj);
            pwd = convertToCString(strObj);
            if (existsUppercase(pwd) == false)
                continue;
        }

        if (existsLowercase(pwd) == true)
        {
            std::cout << "\t\tPassword does not contain at least one lowercase letter! "
                      << "Please try again.";
            std::cout << "\n\t\tEnter your password: ";
            getline(std::cin, strObj);
            pwd = convertToCString(strObj);
            if (existsLowercase(pwd) == false)
                continue;
        }

        if (existsDigit(pwd) == true)
        {
            std::cout << "\t\tPassword does not contain at least one digit! "
                      << "Please try again.";
            std::cout << "\n\t\tEnter your password: ";
            getline(std::cin, strObj);
            pwd = convertToCString(strObj);
            if (existsDigit(pwd) == false)
                continue;
        }

        if (existsSpecChar(pwd) == true)
        {
            std::cout << "\t\tPassword does not contain at least one special character! "
                      << "Please try again.";
            std::cout << "\n\t\tEnter your password: ";
            getline(std::cin, strObj);
            pwd = convertToCString(strObj);
            if (existsSpecChar(pwd) == false)
                continue;
        }
    }

    std::cout << "\n\t\tLogging you in . . . \n";

    return EXIT_SUCCESS;
}

char *convertToCString(std::string s)
{
    char *pwd = new char[s.length()];

    for (int i = 0; i < s.length(); i++)
    {
        *(pwd + i) = s[i];
    }
    return pwd;
}

bool isSixCharsPlus(char *cString)
{
    int necLength = 6;

    if (strlen(cString) >= necLength)
        return false;
    else
        return true;
}

bool existsUppercase(char *cString)
{
    for (int i = 0; i < strlen(cString); i++)
        if (isupper(*(cString + i)) == true)
            return false;
    return true;
}

bool existsLowercase(char *cString)
{
    for (int i = 0; i < strlen(cString); i++)
        if (islower(*(cString + i)) == true)
            return false;
    return true;
}

bool existsDigit(char *cString)
{
    for (int i = 0; i < strlen(cString); i++)
        if (isdigit(*(cString + i)) == true)
            return false;
    return true;
}

bool existsSpecChar(char *cString)
{
    for (char ch = ' '; ch <= '~'; ch++)
    {
        for (int i = 0; i < strlen(cString); i++)
            if ((*(cString + i) == ch) && (isalnum(*(cString + i))) == false)
                return false;
    }
    return true;
}

