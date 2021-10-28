//--------------------------------------------------------------------------------------
// Nick Walker
// n2148996
// COSC-1337-003
// This program will ask the user to enter the sales amounts for 4 seperate divisions
// and error check if those values are (> 0). It will then caluclate which division had
// the highest sales.
// PROGRAM STATUS -- COMPLETE
//--------------------------------------------------------------------------------------
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Prototypes
double getSales(string);
double findHighest(double, double, double, double);

int main() {
    // Initialize String Variables for the Divisions
    string 
    northEast = "Northeast", 
    southEast = "Southeast", 
    northWest = "Northwest", 
    southWest = "Soutwest";

    // Initialize double variables for the sales
    double 
    northEastSales,
    southEastSales,
    northWestSales,
    southWestSales;

    northEastSales = getSales(northEast);
    southEastSales = getSales(southEast);
    northWestSales = getSales(northWest);
    southWestSales = getSales(southWest);

    findHighest(northEastSales, southEastSales, northWestSales, southWestSales);

}

double getSales(string division) {
    double sales;

    // While loop to obtain proper input from user
    do {
        cout << "Enter the quarterly sales for the " << division << " division: ";
        cin >> sales;

        // Check if input is < 0
        if (sales < 0) {
            cout << "Sales figures cannot be negative. Please re-enter.";
        }

    } while(sales < 0);  // Sales < 0

    // Return sales back to main()
    return sales;
} 

double findHighest(double northEastSales, double southEastSales, double northWestSales, double southWestSales) {

    // Declare & assign to salesArray & divisionArray
    double salesArray[4] = {northEastSales, southEastSales, northWestSales, southWestSales};
    string divisionArray[4] = {"Northeast", "Southeast", "Northwest", "Southwest"};

    // Declare highestSales and highestDivision to be used later
    double highestSales;
    string highestDivision;
    
    // Calculate which division had the highest sales again to determine the position 
    // we need to get the divisions name
    int last = salesArray[0];
    for (int i = 0; i < 4; i++) {
        
        // If last sales is < current iteration of salesArray
        // Assign last to the current iteration of salesArray
        if (last < salesArray[i]) {
            last = salesArray[i];
            
            // Assign the highestDivision and highestSales to the corresponding value
            highestDivision = divisionArray[i];
            highestSales = salesArray[i];
         }
    }

    // Display Output
    cout << endl;
    cout << "The " << highestDivision << " division had the highest sales this quarter.\n";
    cout << "$" << setprecision(2) << fixed << highestSales;

    return 0;
}