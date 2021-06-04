/*
    Programming Challenge 10.4 - Average number of letters in each word in a string.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>

int wordCount(char *, int);
double avgNumLetters(char *, int);
int wordCount(std::string);
double avgNumLetters(std::string);

int main() {

    int len = 0;

    std::cout << std::endl;
    std::cout << "\t\tEnter the size of your C-string: ";
    std::cin >> len;

    char *cStr = new char[len];
    std::string line = "";

    std::cout << "\t\tEnter a string (as C-string): ";
    std::cin.ignore();
    std::cin.getline(cStr, len);
    std::cout << "\t\tThere are " << wordCount(cStr, len)
              << " words in the C-string.";

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\t\tEnter a string (as object): ";
    getline(std::cin, line);
    std::cout << "\t\tThere are " << wordCount(line)
              << " words in the string object\n\n";

    std::cout << "\t\tAverage letters in a word for C-string: "
              << avgNumLetters(cStr, len) << std::endl;

    std::cout << "\t\tAverage letters in a word for string a object: "
              << avgNumLetters(line) << std::endl;

    delete [] cStr;
    cStr = nullptr;

    return EXIT_SUCCESS;
}

int wordCount(char *cStr, int len)
{
    int count = 0;

    for (int i = 0; i < len; i++)
        if (isspace(cStr[i]))
            count++;
    return count + 1;
}

double avgNumLetters(char *cStr, int len)
{
    int wc = wordCount(cStr, len),
        count = 0;

    for (int i = 0; i < len; i++)
        if (isalpha(cStr[i]) && cStr[i] != '.' && cStr[i] != '!' && cStr[i] != '?')
            count++;
    return static_cast<double>(count) / wc;
}

int wordCount(std::string line)
{
    int count = 0;

    for (int i = 0; i < line.length(); i++)
        if (line[i] == ' ')
            count++;
    return count + 1;
}

double avgNumLetters(std::string line)
{
    int wc = wordCount(line),
        count = 0;

    for (int i = 0; i < line.length(); i++)
        if (line[i] != ' ' && line[i] != '.' && line[i] != '!' && line[i] != '?')
            count++;
    return static_cast<double>(count) / wc;
}