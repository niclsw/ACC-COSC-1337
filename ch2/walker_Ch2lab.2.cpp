// -------------------------------------
// Nicklaus Walker
// n2148996
// COSC-1337-003
// Program Status -- COMPLETE
// 2.	Basketball Player Height –The star player of a high school basketball team is 75 inches tall.
// Write a program to compute and display the height in feet/inches form.
// Hint:   Try using the modulus and integer divide operations.
// -------------------------------------

#include <iostream>

using namespace std;

int main() {
    // Declare int var
    int playerHeight = 75,
            feet = 75 / 12,
            inches = 75 % 12;

    // Print statement
    cout << "A "<< playerHeight << " inch tall basketball player is " << feet << " feet " << inches << " inches tall.";

    return 0;

}