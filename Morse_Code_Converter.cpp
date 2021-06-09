/*
    Gaddis Programming Challenge 10.17 - Morse Code Converter

    Write a program that asks the user to enter a string, and then converts that
    string to Morse code.
*/

#include <iostream>
#include <cstdlib>   // provides EXIT_SUCCESS
#include <string>
#include <cstring>   // provides strlen()

std::string morseCode(char*&);
char *convertStrObjToCString(std::string&);
void display(const std::string);

int main()
{
    std::string strObj = "", mCode = "";
    char *cString;

    std::cout << "\n\nEnter a string to convert to Morse code: ";
    getline(std::cin, strObj);    // allows string of arbitrary length

    cString = convertStrObjToCString(strObj);
    mCode = morseCode(cString);
    display(mCode);

    return EXIT_SUCCESS;
}

char *convertStrObjToCString(std::string& s)
{
    char *cStr = new char[s.length()];

    for (auto i = 0; i < s.length(); i++)
        *(cStr + i) = s[i];
    return cStr;
}

std::string morseCode(char*& cStr)
{
    std::string morse;
    for (int i = 0; i < strlen(cStr); i++)
    {
        if (*(cStr + i) == ',')         // boolean needs character comparison
            morse.append("--..--");  // mystring.append(str) appends str to
                                        // mystring
        else if (*(cStr + i) == ' ')
            morse.append(" ");
        else if (*(cStr + i) == '.')
            morse.append(".-.-.-");
        else if (*(cStr + i) == '?')
            morse.append("..--..");
        else if (*(cStr + i) == '0')
            morse.append("-----");
        else if (*(cStr + i) == '1')
            morse.append(".----");
        else if (*(cStr + i) == '2')
            morse.append("..---");
        else if (*(cStr + i) == '3')
            morse.append("...--");
        else if (*(cStr + i) == '4')
            morse.append("....-");
        else if (*(cStr + i) == '5')
            morse.append(".....");
        else if (*(cStr + i) == '6')
            morse.append("-....");
        else if (*(cStr + i) == '7')
            morse.append("--...");
        else if (*(cStr + i) == '8')
            morse.append("---..");
        else if (*(cStr + i) == '9')
            morse.append("----.");
        else if (*(cStr + i) == 'A')
            morse.append(".-");
        else if (*(cStr + i) == 'B')
            morse.append("-...");
        else if (*(cStr + i) == 'C')
            morse.append("-.-.");
        else if (*(cStr + i) == 'D')
            morse.append("-..");
        else if (*(cStr + i) == 'E')
            morse.append(".");
        else if (*(cStr + i) == 'F')
            morse.append("..-.");
        else if (*(cStr + i) == 'G')
            morse.append("--.");
        else if (*(cStr + i) == 'H')
            morse.append("....");
        else if (*(cStr + i) == 'I')
            morse.append("..");
        else if (*(cStr + i) == 'J')
            morse.append(".---");
        else if (*(cStr + i) == 'K')
            morse.append("-.-");
        else if (*(cStr + i) == 'L')
            morse.append(".-..");
        else if (*(cStr + i) == 'M')
            morse.append("--");
        else if (*(cStr + i) == 'N')
            morse.append("-.");
        else if (*(cStr + i) == 'O')
            morse.append("---");
        else if (*(cStr + i) == 'P')
            morse.append(".--.");
        else if (*(cStr + i) == 'Q')
            morse.append("--.-");
        else if (*(cStr + i) == 'R')
            morse.append(".-.");
        else if (*(cStr + i) == 'S')
            morse.append("...");
        else if (*(cStr + i) == 'T')
            morse.append("-");
        else if (*(cStr + i) == 'U')
            morse.append("..-");
        else if (*(cStr + i) == 'V')
            morse.append("...-");
        else if (*(cStr + i) == 'W')
            morse.append(".--");
        else if (*(cStr + i) == 'X')
            morse.append("-..-");
        else if (*(cStr + i) == 'Y')
            morse.append("-.--");
        else if (*(cStr + i) == 'Z')
            morse.append("--..");
        // account for lowercase letters --> morse code for 'A' = 'a'
        else if (*(cStr + i) == 'a')
            morse.append(".-");
        else if (*(cStr + i) == 'b')
            morse.append("-...");
        else if (*(cStr + i) == 'c')
            morse.append("-.-.");
        else if (*(cStr + i) == 'd')
            morse.append("-..");
        else if (*(cStr + i) == 'e')
            morse.append(".");
        else if (*(cStr + i) == 'f')
            morse.append("..-.");
        else if (*(cStr + i) == 'g')
            morse.append("--.");
        else if (*(cStr + i) == 'h')
            morse.append("....");
        else if (*(cStr + i) == 'i')
            morse.append("..");
        else if (*(cStr + i) == 'j')
            morse.append(".---");
        else if (*(cStr + i) == 'k')
            morse.append("-.-");
        else if (*(cStr + i) == 'l')
            morse.append(".-..");
        else if (*(cStr + i) == 'm')
            morse.append("--");
        else if (*(cStr + i) == 'n')
            morse.append("-.");
        else if (*(cStr + i) == 'o')
            morse.append("---");
        else if (*(cStr + i) == 'p')
            morse.append(".--.");
        else if (*(cStr + i) == 'q')
            morse.append("--.-");
        else if (*(cStr + i) == 'r')
            morse.append(".-.");
        else if (*(cStr + i) == 's')
            morse.append("...");
        else if (*(cStr + i) == 't')
            morse.append("-");
        else if (*(cStr + i) == 'u')
            morse.append("..-");
        else if (*(cStr + i) == 'v')
            morse.append("...-");
        else if (*(cStr + i) == 'w')
            morse.append(".--");
        else if (*(cStr + i) == 'x')
            morse.append("-..-");
        else if (*(cStr + i) == 'y')
            morse.append("-.--");
        else if (*(cStr + i) == 'z')
            morse.append("--..");
    }
    return morse;
}

void display(const std::string morse)
{
    std::cout << "Morse Code: ";
    for (auto i = 0; i < morse.length(); i++)
        std::cout << morse[i];
    std::cout << "\n\n";
}

