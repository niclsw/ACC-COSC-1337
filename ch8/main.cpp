//--------------------------------------------------------------------------------------
// Nick Walker
// n2148996
// COSC-1337-003
// Thsi program takes a workers hour and pay from a datafile and calculates the gross
// pay using a class.
// PROGRAM STATUS -- COMPLETE
//--------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Payroll class
class Payroll {

    private:
        double hoursWorked;
        double payRate;

    public:
        // Constructor
        Payroll() {
            hoursWorked = 0;
            payRate = 0;
        }
        // Functions from class Payroll
        void setHoursWorked(double);
        void setPayRate(double);
        double calculateGrossPay();

};

// Setter for hours worked
void Payroll::setHoursWorked(double hours) {
    hoursWorked = hours;
}
// Setter for payrate 
void Payroll::setPayRate(double pay) {
    payRate = pay;
}
// Caclulate the gross pay from a worker
double Payroll::calculateGrossPay() {
    return hoursWorked * payRate;
}

int main() {
    // Initialize temp placehold variables
    double hours, rate;

    // Intitialize Payroll object array
    Payroll payrolldata[7];

    // Open file
    ifstream infile;
    infile.open("payrollss.dat");

    // Check if file was opened - return 1 if not
    if (!infile) {
        cerr << "Uh oh, payroll.dat could not be opened for reading! " << endl;
        return 1;
    }
    

    // read file from payroll data to the object array
    for (int x = 0; x < 7; x++) {
        infile >> hours;
        infile >> rate;

        payrolldata[x].setHoursWorked(hours);
        payrolldata[x].setPayRate(rate);
    }

    // close file because we should
    infile.close();

    // Display output header
    cout << "Employee\tGross Pay" << endl;
    cout << "========\t=========" << endl;

    // Display gross pay from object array
    for (int x = 0; x < 7; x++) {
        cout << setw(4) << x+1 << ":" << setw(14) << "$ " 
        << setprecision(2) << fixed << payrolldata[x].calculateGrossPay() 
        << endl;
    }

    return 0;

}