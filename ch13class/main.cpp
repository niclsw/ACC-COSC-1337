// Nick Walker
// ACC-COSC-1337
// This program is an example of a class being used to encode and decode files
// It will prompt the user to select from a menu with the options to encrypt,
// decrypt, or set a key.
// Note: You MUST set a key for the file to encrypt

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Prototype
void returnToMenu(void);
bool isInt(const std::string&);

// Class Encode
class Encode {

    private:
        int key;
        std::string fileName;
        char c;
    public:
        Encode() {
            key = 0;
            fileName = "";
            c = 0;
        }
        void encrypt(std::string, std::string);
        void decrypt(std::string, std::string);
        void setKey(std::string);
};

// Encrypt function
void Encode::encrypt(std::string uncFileName, std::string encFileName) {

    std::fstream uncFile, encFile;

    // Open the unencrypted file
    // Detect any errors with the file open operation
    uncFile.open(uncFileName, std::ios::in);
    if (!uncFile) {
        std::cout << "Error opening unecrypted file\n" << std::endl;
        atexit(returnToMenu); // Go to returnToMenu function
    }

    // Open the file that will be encrypted
    // Detect any errors with the file open operation
    encFile.open(encFileName, std::ios::out);
    if (!encFile) {
        std::cout << "Error opening encrypted file\n" << std::endl;
        atexit(returnToMenu);
    }

    // Read data from the inFile to the new file 
    // do not skip white spaces while going through each char
    while(uncFile >> std::noskipws >> c) {
        int temp = (c + key); // encrypt each char of inFile with the key
        encFile << (char)temp;
    }

    // Close the files
    uncFile.close();
    encFile.close();

}

// Decrypt function
void Encode::decrypt(std::string encFileName, std::string decFileName) {

    std::fstream encryptedFile, decryptedFile;

    // Open the encrypted file
    // Check for any errors
    encryptedFile.open(encFileName, std::ios::in);
    if (!encryptedFile) {
        std::cout << "Error opening encrypted file\n" << std::endl;
        atexit(returnToMenu);
    }

    // Open the file that will show the uncrypted text
    // Check for any errors
    decryptedFile.open(decFileName, std::ios::out);
    if (!decryptedFile) {
        std::cout << "Error opening decrypted file\n" << std::endl;
        atexit(returnToMenu);
    }

    // Begin decrypting the encryptedFile and put decrypted chars
    // into the decrypted file
    while (encryptedFile >> std::noskipws >> c) {
        int temp = (c - key);
        decryptedFile << (char)temp;
    }

    // Close the files
    encryptedFile.close();
    decryptedFile.close();
}

// Mutator for private key
void Encode::setKey(std::string newKey) {
    key = stoi(newKey);

    std::cout << "\n*** NEW KEY IS " << newKey << " ***\n\n";
}



int main() {

    // Initialize Object and char
    Encode encodeObj;
    char c;

    // Intro
    std::cout << "Note: you must set a key if you want the file to be encrypted\n";
    std::cout << "Note: Enter anything other than 1, 2, or 3 to EXIT\n\n";

    do {
        // Main Menu
        std::cout << "=== WEAK ENCRYPT : MENU ===" << std::endl;
        std::cout << "(1) Encrypt" << std::endl;
        std::cout << "(2) Decrypt" << std::endl;
        std::cout << "(3) Set Key" << std::endl;
        std::cout << "(ANY) Exit" << std::endl;
        std::cout << "Option: ";
        std::cin >> c;

        // Switch for the menu
        switch (c) {
            case '1': {

                std::cout << "\n\n=== WEAK ENCRYPT : Encrypt ===" << std::endl;

                std::string uncFileName, encFileName;
                std::cout << "\nEnter the name for the file to be encrypted: ";
                std::cin >> uncFileName;


                std::cout << "Enter the name for the encrypted file: ";
                std::cin >> encFileName;

                encodeObj.encrypt(uncFileName, encFileName);
                break;
            }
            case '2': {

                std::cout << "\n\n=== WEAK ENCRYPT : Decrypt ===" << std::endl;

                std::string encFileName, decFileName;
                std::cout << "\nEnter the name for the encrypted file: ";
                std::cin >> encFileName;


                std::cout << "Enter the name for the file to be decrypted: ";
                std::cin >> decFileName;
                encodeObj.decrypt(encFileName, decFileName);
                break;
            }
            case '3': {

                std::cout << "\n\n=== WEAK ENCRYPT : Set Key ===" << std::endl;

                std::string newKey;
                bool testKey = true;

                do {
                    
                    std::cout << "\nEnter a key: ";
                    std::cin >> newKey;
                    testKey = isInt(newKey); // tests if user input is integer

                    if (!testKey) {
                        std::cout << "\nKey must be all integers" << std::endl;
                    }

                } while(!testKey);

                // send newKey to class mutator
                encodeObj.setKey(newKey);
                break;
            }
            default: {
                return 1;
            }
        }
    } while(c != '4');
}

// This somehow works it calls the main function again.
// After adding this, you have to enter 4 to exit twice.
void returnToMenu(void) {
    main();
}

bool isInt(const std::string& str) {
    bool test;

    // Found this online that checks each char of a string to see if they are all
    // integers. If it is not an integer, it returns false. 
    return !str.empty() &&
        std::find_if(str.begin(), str.end(),
            [](unsigned char c) { return !std::isdigit(c); }) == str.end();
}