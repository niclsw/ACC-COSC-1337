//--------------------------------------------------------------------------------------
// Nick Walker
// n2148996
// COSC-1337-003
// This program allows the user to enter 10 artists and songs. It then sorts them to
// display alphabetically.
// PROGRAM STATUS -- COMPLETE
//--------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <istream>
#include <string>

using namespace std;

// Declare struct for ListOfSongs
struct ListOfSongs {
    string artist;
    string song;
};

// Prototypes
void getData(ListOfSongs Playlist[], int);
void sortList(ListOfSongs Playlist[], int);
void displayList(ListOfSongs Playlist[], int);

int main() {

    // Int Size
    int SIZE = 10;

    // Playlist Object
    ListOfSongs Playlist[10];

    // Send playlist and size to getData for user input
    getData(Playlist, SIZE);

    // Send playlist and size to sortList
    sortList(Playlist, SIZE);

    // Send the playlist and size to displayList
    displayList(Playlist, SIZE);
}

void getData(ListOfSongs Playlist[], int SIZE) {

    // String variables for temp use
    string artistName;
    string songName;

    // For loop to get user input Artist name & Song
    for (int i=0; i < SIZE; i++) {
        // Artist input
        cout << "Artist: ";
        getline(cin, Playlist[i].artist);

        // flush the stream
        fflush(stdin);

        // Song title input
        cout << "Song: ";
        getline(cin, Playlist[i].song);

        // flush the stream
        fflush(stdin);
    }
}

void sortList(ListOfSongs Playlist[], int SIZE) {

    // Sequence sort
    for(int i = 0; i < SIZE-1; i++) {
        
        // current index of i for use later
        int minIndex = i;

        // y=i+1 to look at the next element of the array
        for(int y = i+1; y < SIZE; y++) {
            
            // if the 2nd element is < or lower in the alphabet, change i var to y's value
            if (Playlist[y].artist < Playlist[minIndex].artist) {
                i = y;
            }
        }

        // Begin sort
        // Temp variable for the new value that will be placed in i's position
        ListOfSongs temp = Playlist[i];
        Playlist[i] = Playlist[minIndex];
        Playlist[minIndex] = temp;
    }
}

void displayList(ListOfSongs Playlist[], int SIZE) {

    cout << "\tAritst \t Song Title" << endl;
    cout << "==================================" << endl;

    // Display the artists and song title with format
    for (int i = 0; i < SIZE; i++) {
        cout << setw(20) << left << Playlist[i].artist 
             << setw(20) << Playlist[i].song << endl;
    }
}