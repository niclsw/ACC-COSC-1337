#include <iostream>
#include <iomanip>
#include <istream>
#include <string>

using namespace std;

struct ListOfSongs {
    string artist;
    string song;
};

void getData(ListOfSongs Playlist[], int);
void sortList(ListOfSongs Playlist[], int);
void displayList(ListOfSongs Playlist[], int);

int main() {

    int SIZE = 10;
    ListOfSongs Playlist[10];

    getData(Playlist, SIZE);

    sortList(Playlist, SIZE);

    displayList(Playlist, SIZE);
}

void getData(ListOfSongs Playlist[], int SIZE) {

    string artistName;
    string songName;

    for (int i=0; i < SIZE; i++) {
        cout << "Artist: ";
        getline(cin, Playlist[i].artist);
        fflush(stdin);
        cout << "Song: ";
        getline(cin, Playlist[i].song);
        fflush(stdin);
    }
}

void sortList(ListOfSongs Playlist[], int SIZE) {

    for(int i = 0; i < SIZE-1; i++) {
        
        int minIndex = i;

        for(int y = i+1; y < SIZE; y++) {
            
            if (Playlist[y].artist < Playlist[minIndex].artist) {
                i = y;
            }
        }

        ListOfSongs temp = Playlist[i];
        Playlist[i] = Playlist[minIndex];
        Playlist[minIndex] = temp;
    }
}

void displayList(ListOfSongs Playlist[], int SIZE) {

    cout << "\tAritst \t Song Title" << endl;
    cout << "==================================" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << setw(20) << left << Playlist[i].artist 
             << setw(20) << Playlist[i].song << endl;
    }
}