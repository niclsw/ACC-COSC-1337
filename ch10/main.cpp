#include <iostream>
#include <string>
#include <algorithm>

void getData(int, int);
void sortData(int, int);
void displayData(int, int);
int average(int, int);

int main() {

    int numOfStudents, numOfMovies;
    
    do {
        std::cout << "Enter number of Students: ";
        std::cin >> numOfStudents;

        if (numOfStudents < 0) {
            std::cout << "Number must be positivie" << std::endl;
        }
        else if (numOfStudents == 0) {
            std::cout << "0 students = no run -- Press any key to close the program...";
            std::cin.get();
            return 1;
        }

    } while (numOfStudents < 0);
    

    int *numOfMovies = new int[numOfStudents];

    getData(numOfMovies, numOfStudents);

    return 0;
}

void getData(int *numOfMovies[], int numOfStudents) {

    std::cout << "Enter Number of movies each student watched" << std::endl;

    for (int i = 0; i < numOfStudents; i++) {
        std::cout << i << ": ";
        std::cin >> *(numOfMovies[i]);
    }
}

void sortData(int *numOfMovies[], int numOfStudents) {

    std::sort(std::begin(numOfMovies), std::end(numOfMovies));
    // doesn't work with pointers i guess

}

void displayData(int *numOfMoves[], int numOfStudents) {


}

int average(int *numOfMovies[], int numOfStudents) {
    double average;
    int total = 0;
    int count = 0;

    for (int i = 0; i < numOfStudents; i++) {
        total += *(numOfMovies[i]);
        count++;
    }

    average = total / count;

    return average;
}