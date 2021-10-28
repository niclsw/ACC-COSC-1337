// -------------------------------------
// Nicklaus Walker
// n2148996
// COSC-1337-003
// Program Status -- COMPLETE
// Take total sales from 3 stores and calculate the amount of sales in stars per
// 100 dollars. Use a while look to check user entered amount >= $0
// -------------------------------------
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Declare variables
    float salesStore1, salesStore2, salesStore3;
    int starsStore1, starsStore2, starsStore3;

    // Take users input and assign amount entered to the corresponding store
    // Store 1
    cout << "Enter today's sales for Store 1: ";
    cin >> salesStore1;
    while (salesStore1 < 0) {
        cout << "Please enter a positive number for Store 1: ";
        cin >> salesStore1;
    }

    // Store 2
    cout << "Enter today's sales for Store 2: ";
    cin >> salesStore2;
    while (salesStore2 < 0) {
        cout << "\nPlease enter a positive number for Store 2: ";
        cin >> salesStore2;
    }

    // Store 3
    cout << "Enter today's sales for Store 3: ";
    cin >> salesStore3;
    while (salesStore3 < 0) {
        cout << "\nPlease enter a positive number for Store 3: ";
        cin >> salesStore3;
    }

    // Calculate the stars per store
    // Stars = sales / 100
    starsStore1 = round(salesStore1 / 100);
    starsStore2 = round(salesStore2 / 100);
    starsStore3 = round(salesStore3 / 100);

    cout << endl;
    cout << "\tDAILY SALES \n";
    cout << "\t(each * = $100)";
    cout << endl;

    // Store 1 Sales per $100
    cout << "Store 1: ";
    for (int i = 0; i < starsStore1; i++) {
        cout << "*";
    }

    // Store 2 Sales per $100
    cout << "\nStore 2: ";
    for (int i = 0; i < starsStore2; i++) {
        cout << "*";
    }

    // Store 3 Sales per $100
    cout << "\nStore 3: ";
    for (int i = 0; i < starsStore3; i++) {
        cout << "*";
    }

    // End Program
    return 0;
}
