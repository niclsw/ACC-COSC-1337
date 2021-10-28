// -------------------------------------
// Nicklaus Walker
// n2148996
// COSC-1337-003
// Program Status -- COMPLETE
// 1.	Flash Drive Price  - An electronics company makes 64 gigabyte USB flash drives that cost them $8.00 apiece to produce.
// Write  a program to determine how much the company should sell them for if it wants to make a 35 percent profit.
// Display the result on the screen.
// -------------------------------------

#include <iostream>

using namespace std;

int main() {
    // Declare float variables
    float profit = .35,
            cost = 8.00,
            sellingPrice = 0;

    // Calculate desired selling price
    sellingPrice = (cost * profit) + cost;

    // Print statement
    cout << "To have a 35% profit, the flash drive should sell for $" << sellingPrice;

    return 0;

}
