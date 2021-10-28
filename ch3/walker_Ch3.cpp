// -------------------------------------
// Nicklaus Walker
// n2148996
// COSC-1337-003
// Program Status -- COMPLETE
// Take actual property value and amount of tax per $100 as user input and calculate the assessed value
// total and the amount of property tax paid.
// -------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // Declare doubles
    double assessedValue, propertyTax, propertyValueTotal, assessedValueTotal;

    // Take input from the user
    cout << "Enter the actual property value: $";
    cin >> propertyValueTotal;
    cout << "Enter the amount of tax per $100 of assessed value: $";
    cin >> assessedValue;

    // Calculate the assessed value total and the property tax
    assessedValueTotal = propertyValueTotal * .60;
    propertyTax = (assessedValueTotal / 100) * assessedValue;

    // Display the output with formatting applied
    cout << "Property Value: " << setw(3) << "$" << setw(10) << fixed << setprecision(2) << propertyValueTotal << endl;
    cout << "Assessed Value: " << setw(3) << "$" << setw(10) << fixed << setprecision(2) << assessedValueTotal << endl;
    cout << "Property Tax: " << setw(5) << "$" << setw(10) << fixed << setprecision(2) << propertyTax << endl;

    return 0;
}
