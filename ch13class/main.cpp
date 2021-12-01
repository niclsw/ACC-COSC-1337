#include <iostream>
#include <fstream>
#include <string>

// Prototype
void fileOpenError(void);

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
        void setKey(int);
};

// Encrypt function
void Encode::encrypt(std::string uncFileName, std::string encFileName) {

    std::fstream inFile, outFile;

    // Open the unencrypted file
    // Detect any errors with the file open operation
    inFile.open(uncFileName, std::ios::in);
    if (!inFile) {
        std::cout << "Error opening original file\n" << std::endl;
        atexit(fileOpenError); // Go to fileOpenError function
    }

    // Open the file that will be encrypted
    // Detect any errors with the file open operation
    outFile.open(encFileName, std::ios::out);
    if (!outFile) {
        std::cout << "Eror opening out file\n" << std::endl;
        atexit(fileOpenError);
    }

    // Read data from the inFile to the new file 
    while(inFile >> std::noskipws >> c) {
        int temp = (c + key); // encrypt each char of inFile with the key
        outFile << (char)temp;
    }

    // Close the files
    inFile.close();
    outFile.close();

}

// Decrypt function
void Encode::decrypt(std::string encFileName, std::string decFileName) {

    std::fstream encryptedFile, decryptedFile;

    // Open the encrypted file
    // Check for any errors
    encryptedFile.open(encFileName, std::ios::in);
    if (!encryptedFile) {
        std::cout << "Error opening encrypted file\n" << std::endl;
        atexit(fileOpenError);
    }

    // Open the file that will show the uncrypted text
    // Check for any errors
    decryptedFile.open(decFileName, std::ios::out);
    if (!decryptedFile) {
        std::cout << "Error opening decrypted file\n" << std::endl;
        atexit(fileOpenError);
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
void Encode::setKey(int newKey) {
    key = newKey;

    std::cout << "\n*** NEW KEY IS " << newKey << " ***\n\n";
}



int main() {

    // Initialize Object and char
    Encode encodeObj;
    char c;

    do {
        // Main Menu
        std::cout << "=== WEAK ENCRYPT : MENU ===" << std::endl;
        std::cout << "(1) Encrypt" << std::endl;
        std::cout << "(2) Decrypt" << std::endl;
        std::cout << "(3) Set Key" << std::endl;
        std::cout << "(4) Exit" << std::endl;
        std::cout << "Choice: ";
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

                int newKey;

                do {
                    std::cout << "\nEnter a key: ";
                    std::cin >> newKey;
                    if (!std::cin) {
                        std::cout << "\nThe key must be an integer..." << std::endl;
                    }
                    fflush(stdin);
                } while(!std::cin);
                encodeObj.setKey(newKey);
                break;
            }
            default: {
                return 0;
            }
        }
    } while(c != '4');
}

// This somehow works it calls the main function again.
// After adding this, you have to enter 4 to exit twice.
void fileOpenError(void) {
    main();
}