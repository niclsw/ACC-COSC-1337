//--------------------------------------------------------------------------------------
// Nick Walker
// n2148996
// COSC-1337-003
// This program will ask the user the tax rate, bill total, and how much % of a tip they
// want to leave. It will calculate the tip the user should leave. Will run until the user
// decides to leave.
// PROGRAM STATUS -- COMPLETE
//--------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

// Class Tips
class Tips {
    
    // Private Access Specifier
    private:
        double taxRate;
    
    // Public Access Specifier
    public:
        // Default constructor
        Tips() {
            // Set tax rate to default value
            taxRate = 0.085;
        }

        // Initialize class methods
        double computeTip(double, double);
        void setTaxRate(double);
};

// Compute tip accepting totalBill and desired tip rate
double Tips::computeTip(double totalBill, double tipRate) {
    // Initialize variable tipAmount
    double tipAmount;

    // Fix totalBill amount to accept user input without cents
    totalBill = totalBill + .00;
    
    totalBill = totalBill / (1 + taxRate);
    tipAmount = totalBill * (tipRate / 100);

    return tipAmount;
}

// Mutator for taxRate
void Tips::setTaxRate(double rate) {
    if (rate != 0 && rate != taxRate) {
        taxRate = rate / 100;
    }  
}

int main() {
    // Initialize Tips Obj and variables
    Tips tips;
    double taxRate, totalBill, tipRate, tipAmount;
    char choice;

    // show welcome message
    cout << "This program will compute a restaurant tip based on a total \n";
    cout << "bill amount and the % the patron wihes to tip the server." << endl;

    // do-while check to make sure user entered > 0 taxRate
    do {
        // I tried a million different things to accept 'enter' as nothing but I
        // just couldn't get it to work :( 0 is the default 0.085!!!!
        cout << "\nTax % for this location(0 for default): ";
        cin >> taxRate;

        if (taxRate < 0 ) {
            cout << "Tax %' cannont be less than 0. Please re-enter tax %";
        }

    } while (taxRate < 0);

    // send tax rate to Tips taxRate mutator
    tips.setTaxRate(taxRate);

    // do-while to compute tips until user exits 
    do {
        // Seperator
        cout << endl;
        cout << "************** Tip Helper ***************" << endl;
        cout << endl;

        // User totalBill & tipRate input
        cout << "Enter total bill amount: ";
        cin >> totalBill;
        cout << "Enter desired tip % ";
        cin >> tipRate;

        // tipAmount = computeTip with totalBill and tipRate variables
        tipAmount = tips.computeTip(totalBill, tipRate);

        // Display how much the user should tip based on desired paramaters
        cout << "\nThe tip should be $ " << setprecision(2) << fixed << tipAmount;

        // Ask the user if they would like to compute another tip
        cout << "\nCompute another Tip? (y/n): ";
        cin >> choice;

        // clear stream
        cin.clear();
        cin.ignore(100, '\n');

    } while (choice == 'y' || choice == 'Y');

    return 0;
}