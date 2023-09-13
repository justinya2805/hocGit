#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string decToHex(int decimal)
{
    string hex = "";
    while (decimal > 0)
    {
        int remainder = decimal % 16;
        if (remainder < 10)
            hex = char('0' + remainder) + hex;
        else
            hex = char('A' + remainder - 10) + hex;
        decimal /= 16;
    }
    return hex;
}

string decToBin(int decimal)
{
    string bin = "";
    while (decimal > 0)
    {
        int bit = decimal % 2;
        bin = char('0' + bit) + bin;
        decimal /= 2;
    }
    return bin;
}

string decToOct(int decimal)
{
    string oct = "";
    while (decimal > 0)
    {
        int digit = decimal % 8;
        oct = char('0' + digit) + oct;
        decimal /= 8;
    }
    return oct;
}

int hexToDec(string hex)
{
    int decimal = 0;
    int size = hex.length();
    for (int i = 0; i < size; i++)
    {
        char digit = hex[i];
        if (digit >= '0' && digit <= '9')
            decimal += (digit - '0') * pow(16, size - i - 1);
        else if (digit >= 'A' && digit <= 'F')
            decimal += (digit - 'A' + 10) * pow(16, size - i - 1);
        else if (digit >= 'a' && digit <= 'f')
            decimal += (digit - 'a' + 10) * pow(16, size - i - 1);
        else
        {
            cout << "Invalid hexadecimal input." << endl;
            return -1;
        }
    }
    return decimal;
}

int binToDec(string bin)
{
    int decimal = 0;
    int size = bin.length();
    for (int i = 0; i < size; i++)
    {
        char bit = bin[i];
        if (bit == '0' || bit == '1')
            decimal += (bit - '0') * pow(2, size - i - 1);
        else
        {
            cout << "Invalid binary input." << endl;
            return -1;
        }
    }
    return decimal;
}

int octToDec(string oct)
{
    int decimal = 0;
    int size = oct.length();
    for (int i = 0; i < size; i++)
    {
        char digit = oct[i];
        if (digit >= '0' && digit <= '7')
            decimal += (digit - '0') * pow(8, size - i - 1);
        else
        {
            cout << "Invalid octal input." << endl;
            return -1;
        }
    }
    return decimal;
}

int main()
{
    int choice;
    cout << "Choose the conversion type:" << endl;
    cout << "1. Decimal to Hexadecimal" << endl;
    cout << "2. Decimal to Binary" << endl;
    cout << "3. Decimal to Octal" << endl;
    cout << "4. Hexadecimal to Decimal" << endl;
    cout << "5. Binary to Decimal" << endl;
    cout << "6. Octal to Decimal" << endl;
    cin >> choice;

    if (choice == 1)
    {
        int decimal;
        cout << "Enter a decimal number: ";
        cin >> decimal;
        cout << "Hexadecimal: " << decToHex(decimal) << endl;
    }
    else if (choice == 2)
    {
        int decimal;
        cout << "Enter a decimal number: ";
        cin >> decimal;
        cout << "Binary: " << decToBin(decimal) << endl;
    }
    else if (choice == 3)
    {
        int decimal;
        cout << "Enter a decimal number: ";
        cin >> decimal;
        cout << "Octal: " << decToOct(decimal) << endl;
    }
    else if (choice == 4)
    {
        string hex;
        cout << "Enter a hexadecimal number: ";
        cin >> hex;
        int decimal = hexToDec(hex);
        if (decimal != -1)
            cout << "Decimal: " << decimal << endl;
    }
    else if (choice == 5)
    {
        string bin;
        cout << "Enter a binary number: ";
        cin >> bin;
        int decimal = binToDec(bin);
        if (decimal != -1)
            cout << "Decimal: " << decimal << endl;
    }
    else if (choice == 6)
    {
        string oct;
        cout << "Enter an octal number: ";
        cin >> oct;
        int decimal = octToDec(oct);
        if (decimal != -1)
            cout << "Decimal: " << decimal << endl;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}