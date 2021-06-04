/*
    Gaddis Programming Challenge 10.8 - Sum of Digits in a String

    Write a program that asks the user to enter a series of single digit with
    nothing separating them. Read the input as a C-string or a string object.
    The program should display the sum of all the single-digit numbers of the
    string. For example, if the user enters 92514, the program should display 21.
    The program should also display the highest and lowest str in the string.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>      // EXIT_SUCCESS

int sumCString(char *, int);
int sumStringObject(std::string);
int *charToDigitsArr(char *, int);
int *strToDigitsArr(std::string);
void swapping(int&, int&);
void bubbleSort(int *, int);
int charMax(int *, int);
int charMin(int *, int);
int strMax(int *, int size);
int strMin(int *);
void freeMem(int *, int *, char *);

int main()
{
    int size = 0;
    std::cout << "\n\n\t\tEnter the size of your C-string (plus 1 for the null terminator): ";
    std::cin >> size;

    std::string str;
    char *cStr = new char[size];

    std::cout << "\t\tEnter a C-string: ";
    std::cin.ignore();
    std::cin.getline(cStr, size);
    std::cout << "\t\tSum: " << sumCString(cStr, size) << "\n";
    std::cout << "\t\tMax Digit: " << charMax(charToDigitsArr(cStr, size), size)
              << "\n";
    std::cout << "\t\tMin Digit: " << charMin(charToDigitsArr(cStr, size), size)
              << "\n\n";

    std::cout << "\t\tEnter a string as a string object: ";
    getline(std::cin, str);
    std::cout << "\t\tSum: " << sumStringObject(str) << "\n";
    std::cout << "\t\tMax Digit: " << strMax(strToDigitsArr(str), size)
              << "\n";
    std::cout << "\t\tMin Digit: " << strMin(strToDigitsArr(str))
              << "\n\n";

    int *digCArr = charToDigitsArr(cStr, size);
    int *digStrArr = strToDigitsArr(str);

    freeMem(digCArr, digStrArr, cStr);

    return EXIT_SUCCESS;
}

int sumCString(char *cStr, int size)
{
    int sum = 0;
    int *digits = new int[size];

    for (int i = 0; i < strlen(cStr); i++)
    {
        digits[i] = (int) *(cStr + i) - '0';
        sum += *(digits + i);
    }
    delete [] digits;
    return sum;
}

int *charToDigitsArr(char *cStr, int size)
{
    int *digits = new int[size];

    for (int i = 0; i < strlen(cStr); i++)
        digits[i] = (int) *(cStr + i) - '0';         // notice this . . .
    return digits;
}

int *strToDigitsArr(std::string str)
{
    int num = std::stoi(str);

    int *strDigits = new int[str.length()];
    for (int i = str.length() - 1; i >= 0; i--)
    {
        strDigits[i] = num % 10;
        num /= 10;

        bubbleSort(strDigits, str.length());
    }
    return strDigits;
}

int sumStringObject(std::string str)
{
    int num = std::stoi(str);
    int strSum = 0;

    int digits[str.length()];
    for (int i = str.length() - 1; i >= 0; i--)
    {
        digits[i] = num % 10;
        num /= 10;
        strSum += digits[i];
    }
    return strSum;
}

// helper function
void swapping(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

// helper function
void bubbleSort(int* digits, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool swap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (digits[j] > digits[j + 1])
            {
                swapping(digits[j], digits[j + 1]);
                swap = true;
            }
        }
        if (!swap)
            break;
    }
}

int charMax(int *digits, int size)
{
    bubbleSort(digits, size);;
    return *(digits + (size - 1));
}

int charMin(int *digits, int size)
{
    bubbleSort(digits, size);
    return *(digits + 1);               // + 1 to avoid the null terminator
}

int strMax(int *arr, int size)
{
    return *(arr + (size - 2));
}

int strMin(int *arr)
{
    return *arr;
}

void freeMem(int *digCArr, int *digStrArr, char *cStr)
{
    delete [] digCArr;
    delete [] digStrArr;
    delete [] cStr;

    digCArr = nullptr;
    digStrArr = nullptr;
    cStr = nullptr;
}