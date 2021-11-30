//--------------------------------------------------------------------------------------
// Nick Walker
// n2148996
// COSC-1337-003
// This program takes word like HelloMyLove and runs some functions to seperate, upper,
// lower, and flip it
// PROGRAM STATUS -- COMPLETE
//--------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>

std::string seperate(char *);
std::string upper(char *);
std::string lower(char *);
std::string flip(char *);
bool errorCheck(char *);

int main() {

    char inputChar[100];
    char option = 'Y';


    // Do while loop to allow multiple words
    do {
        // Take input from user
        // Check if what was entered is not a letter
        do {
            std::cout << "Enter a word: ";
            std::cin.getline(inputChar, 100);
        } while (!errorCheck(inputChar));
        

        // Begin displaying the word with format
        std::cout << std::endl;
        std::cout << "=======================" << std::endl;

        std::cout << "Seperated -- " << seperate(inputChar) << std::endl;
        std::cout << "All Upper -- " << upper(inputChar) << std::endl;
        std::cout << "All Lower -- " << lower(inputChar) << std::endl;
        std::cout << "Flip      -- " << flip(inputChar) << std::endl;

        std::cout << "=======================" << std::endl;

        // Ask user if they want to enter another word
        std::cout << "Do you want to do another word(Y/y): ";
        std::cin >> option;
        std::cout << std::endl;

        // Clear the stream
        fflush(stdin);

    } while (option == 'Y' || option == 'y');
    

}

std::string seperate(char *inputChar) {

    std::string output;

    // Assign output[0] to inputchar[0] since we do not need to 
    // check that.
    output += inputChar[0];

    // for loop to check each character
    for (int i{1}; i < std::strlen(inputChar); i++) {
        if (isupper(inputChar[i])) {
            output += ' '; // Add a space
            output += inputChar[i]; // Add the upper char
        }
        else {
            output += inputChar[i];
        }
    }

    return output;
}

std::string upper(char *inputChar) {

    // There is a more efficient way to do this
    // assign output to the seperated char
    std::string output = seperate(inputChar);

    // for loop to convert each char to uppercase
    for (int i{0}; i < output.length(); i++) {
        if (islower(output[i]))
            output[i] = toupper(output[i]);
    }

    return output;
}

std::string lower(char *inputChar) {

    // There is a more efficient way to do this
    // assign output to the seperated char
    std::string output = seperate(inputChar);

    // for loop to convert each char to lowercase
    for (int i{0}; i < output.length(); i++) {
        if (isupper(output[i]))
            output[i] = tolower(output[i]);
    }

    return output;
}

std::string flip(char *inputChar) {

    // There is a more efficient way to do this
    // assign output to the seperated char
    std::string output = seperate(inputChar);

    // Check if char is an upper or lower
    for (int i{0}; i < output.length(); i++) {
        if (isupper(output[i])) {
            output[i] = tolower(output[i]);
        }
            
        else if (islower(output[i])) {
            output[i] = toupper(output[i]);
        }
            
    }

    return output;
}

bool errorCheck(char *inputChar) {
    
    // Default errorCheck = true
    bool errorCheck = true;

    // Go through each char in array and check if it is not alpha
    for(int i{0}; i < std::strlen(inputChar); i++) {
        if (!isalpha(inputChar[i])) {
            errorCheck = false; // assign errorCheck to false if non-alpha found
        }

    }

    // Print error message if non-alpha found
    if (!errorCheck) {
        std::cout << "Error - number found" << std::endl;
    }

    return errorCheck;

}