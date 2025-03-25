#include <iostream>
#include <string>
#include <bitset>
#include <conio.h>
#include <algorithm>

using namespace std;

// Function to convert text to binary
string textToBinary(string text)
{
    string binary = "";
    for (char &_char : text)
    {
        binary += bitset<8>(_char).to_string();
        binary += " ";
    }
    return binary;
}

// Function to convert binary to text
string binaryToText(string binary)
{
    string text = "";
    // Remove spaces from binary
    binary.erase(remove(binary.begin(), binary.end(), ' '), binary.end());
    for (size_t i = 0; i < binary.size(); i += 8)
    {
        string byte = binary.substr(i, 8);
        text += char(bitset<8>(byte).to_ulong());
    }
    return text;
}

int main()
{
    // Declare Variable
    string text;

    // Ask if the user wants to enter text or binary
    std::cout << "Text to Binary and Binary to Text Converter" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    string choice = "1";
    std::cout << "Enter your choice : " << std::endl;
    std::cout << " 1. Text to Binary" << std::endl;
    std::cout << " 2. Binary to Text" << std::endl;

    // Get input
    try
    {
        std::cin >> choice;
        std::cin.ignore();
    }
    catch (const std::exception &e)
    {
        std::cout << std::endl
                  << "Invalid input. Defaulting to Text to Binary" << std::endl
                  << std::endl;
        choice = "1";
    }

    if (choice != "1" && choice != "2")
    {
        std::cout << std::endl
                  << "Invalid input. Defaulting to Text to Binary" << std::endl
                  << std::endl;
        choice = "1";
    }

    // New Line
    std::cout << std::endl;

    // Get input
    if (choice == "1")
    {
        std::cout << "Enter the text    : ";
    }
    else
    {
        std::cout << "Enter the binary  : ";
    }

    // Get input
    getline(cin, text);

    // New Line
    std::cout << std::endl;

    // Convert text to binary
    string binary;
    string translation;
    if (choice == "1")
    {
        translation = text;
        binary = textToBinary(text);
    }
    else
    {
        translation = binaryToText(text);
        binary = textToBinary(translation);
    }
    std::cout << "Text to Binary : " << binary << std::endl;

    // Get the text back from binary
    std::cout << "Back to Text   : " << binaryToText(binary) << std::endl;

    // Wait for any key press
    std::cout << "Press any key to continue...";
    _getch();

    return 0;
}