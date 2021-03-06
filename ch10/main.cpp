//--------------------------------------------------------------------------------------
// Nick Walker
// n2148996
// COSC-1337-003
// This program takes the amount of students from the user and creates a dyn. array.
// PROGRAM STATUS -- COMPLETE
//--------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <algorithm>

// Prototypes
void getData(int *, int);
void sortData(int *, int);
void displayData(int *, int);
double average(int *, int);

int main() {

    int numOfStudents, *movieArray;
    
    // Do-while to error check the number of students

    do {
        std::cout << "Enter number of Students: ";
        std::cin >> numOfStudents;

        // if < 0 return an error
        if (numOfStudents < 0) {
            std::cout << "Number must be positivie" << std::endl;
        }

        // if 0 then user clearly does not want to run this program
        // also catches if characters were entered and closes program
        else if (numOfStudents == 0) {
            std::cout << "0 students = no run -- program ending...";
            return 1;
        }

    } while (numOfStudents < 0);
    
    // Create dynamic array called movieArray
    movieArray = new int[numOfStudents];

    // Send movieArray and numOfStudents to getData
    getData(movieArray, numOfStudents);

    // Send movieArray and numOfStudents to sortData
    sortData(movieArray, numOfStudents);

    // Send movieArray and numOfStudents to displayData
    displayData(movieArray, numOfStudents);

    // clearing memory
    delete [] movieArray;
    movieArray = 0;

    return 0;
}

void getData(int *movieArray, int numOfStudents) {

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Enter Number of movies each student watched" << std::endl;

    // For loop to put data into movieArray
    for (int i = 0; i < numOfStudents; i++) {
        
        // Error check to make sure user enters a number >= 0
        do {
            std::cout << i+1 << ": ";
            std::cin >> movieArray[i];

            if (movieArray[i] < 0) {
                std::cout << "Number of movies can not be negative" << std::endl;
            }

        } while (movieArray[i] < 0);
    }
}

void sortData(int *movieArray, int numOfStudents) {

    // Sort the movie array from smallest to largest numbers
    std::sort(movieArray, movieArray+numOfStudents);

}

void displayData(int *movieArray, int numOfStudents) {

    // Obtain average from average function
    double avg = average(movieArray, numOfStudents);

    std::cout << std::endl;
    std::cout << "Number of Movies Watched per Student" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    // for loop to print out elements of array
    for (int i = 0; i < numOfStudents; i++) {

        std::cout << movieArray[i] << std::endl;

    }

    // print out the average
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Average = " << std::setprecision(1) << std::fixed << avg;
}

double average(int *movieArray, int numOfStudents) {
    // declare variable
    double total = 0.0;

    // for loop to calculate the total of all elements in array
    for (int i = 0; i < numOfStudents; i++) {
        total += movieArray[i];
    }

    // return the average
    return (total / numOfStudents);
}