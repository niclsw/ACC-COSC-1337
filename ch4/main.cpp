// Nicklaus Walker - n2148996
// This program has 3 choices a user can choose. Once a user chooses an option, it asks them how
// many feet the sound wave will travel. The program then calculates how long it will take to travel
// through the medium.
// Program Status - COMPLETE
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Declare Variables
    const int airSpeed = 1100,
        waterSpeed = 4900,
        steelSpeed = 16400;
    int choice;
    double feet, travelTime;
    string medium;

    // Menu with options
    cout << "This program will tell you how long it takes a sound wave \n" << "to travel a specific distance through a particular medium. \n" << endl;
    cout << "Select a substance for the sound to travel through:" << endl;
    cout <<  "\t1. Air" << endl;
    cout << "\t2. Water" << endl;
    cout << "\t3. Steel" << endl;

    // Choice Selection
    cout << "Choice (1, 2, 3): ";
    cin >> choice;

    // Number of feet input
    cout << "\nEnter the number of feet the sound wave will travel: ";
    cin >> feet;

    // Decision structure
    if (choice == 1) {
        travelTime = feet / airSpeed;
        medium = "air";
    }
    else if (choice == 2) {
        travelTime = feet / waterSpeed;
        medium = "water";
    }
    else if (choice == 3) {
        travelTime = feet / steelSpeed;
        medium = "steel";
    }
    else {
        cout << "You must choose 1, 2, or 3. Program closing...";
        return 0;
    }

    // Begin outputting results
    cout << "\nThe sound wave will travel " << feet << " feet through " << medium << " in " << setprecision(4) << fixed << travelTime << " seconds.";

    return 0;
}