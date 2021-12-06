#include <iostream>
#include <fstream>
#include <string>

void encrypt(std::fstream&, std::fstream&);
void decrypt(std::fstream&, std::fstream&);
bool errorCheck(std::fstream&);

int main() {
    std::string fileName;
    bool error;
    std::fstream inFile, fileEncrypt, fileDecrypt;

    // in file do while loop
    do {
        std::cout << "Enter File Name: ";
        std::cin >> fileName;

        //std::ifstream inFile(fileName, std::ios::in);
        inFile.open(fileName, std::ios::in);

        // Check if any errors during file open
        error = errorCheck(inFile);

        // clear stream
        fflush(stdin);

    } while (error);


    // Encrypt file operation
    fileEncrypt.open("ENCRYPTED " + fileName, std::ios::out);
    encrypt(fileEncrypt, inFile);
    fileEncrypt.close();

    // Decrypt file operation
    // open Encrypted file as ios::in
    fileEncrypt.open("ENCRYPTED " + fileName, std::ios::in);
    fileDecrypt.open("DECRYPTED " + fileName, std::ios::out);
    decrypt(fileEncrypt, fileDecrypt);

    // close file(s)
    fileEncrypt.close();
    fileDecrypt.close();
    inFile.close();

    return 0;
}

void encrypt(std::fstream& fileEncrypt, std::fstream& inFile) {

    char ch;

    ch = inFile.peek();
    while (ch != EOF) {
        ch = inFile.get();
        ch += 10;
        fileEncrypt << ch; 
        ch = inFile.peek();
    }
}

void decrypt(std::fstream& fileEncrypt, std::fstream& fileDecrypt) {

    char ch;

    ch = fileEncrypt.peek();
    while (ch != EOF) {
        ch = fileEncrypt.get();
        ch -= 10;
        fileDecrypt << ch; 
        ch = fileEncrypt.peek();
    }
}

bool errorCheck(std::fstream& fileToCheck) {

    bool error;

    if (!fileToCheck) {
        std::cout << "Error Opening File - Try Again" << std::endl;
        error = true;
    }
    else {
        error = false;
    }

    return error;
}