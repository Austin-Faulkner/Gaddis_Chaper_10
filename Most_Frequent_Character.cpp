/*
    Gaddis Programming Challenge 10.9 - Most Frequent Character

    Write a function that accepts either a pointer to a C-string, or a string
    object, as its argument. The function should return the character that
    appears most frequently in the string.
*/

#include <iostream>
#include <string>
#include <cstdlib>  // EXIT_SUCCESS, size_t

char freqChar(const char *);
char freqChar(const std::string);

int main()
{
    int size = 0;

    std::cout << "\n\n\t\tEnter the size of the C-string "
              << "(+ 1 for the null terminator): ";
    std::cin >> size;

    char *fChar = new char[size];
    std::string strFChar;

    std::cout << "\t\tEnter a C-string: ";
    std::cin.ignore();
    std::cin.getline(fChar, size);

    std::cout << "\t\tMost frequent character: " << freqChar(fChar);

    std::cout << "\n\n\t\tEnter a string as a string object: ";
    getline(std::cin, strFChar);
    std::cout << "\t\tMost frequent character: "
              << freqChar(strFChar) << "\n\n";

    return EXIT_SUCCESS;
}

char freqChar(const char *fChar)
{
    if (fChar == nullptr)
        return 0;

    char c;
    int count[127] = {0};
    int max = 0;
    while (*fChar)
    {
        if (++count[*fChar] > max)
        {
            max = count[*fChar];
            c = *fChar;
        }
        fChar++;    // pointer arithmetic
    }
    return c;
}

char freqChar(const std::string strFChar)
{
    char c;
    int count[127] = {0},
        max = 0;

    // In ASCII (space) ' ' = 32 (the first character) and '~' = 126 (the last)
    for (char ch = ' '; ch <= '~'; ch++)
    {
       for (int i = 0; i < strFChar.length(); i++)
       {
           if (ch == strFChar[i])
           {
               ++count[strFChar[i]];
               if (count[strFChar[i]] > max)
               {
                   max = count[strFChar[i]];
                   c = ch;
               }
           }
       }
    }
    return c;
}