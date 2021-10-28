#include <iostream>
#include <iomanip>
#include <istream>
#include <string>

using namespace std;

struct ListOfSongs {
    string artist;
    string song;
};

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

    for(int i = 0; i < SIZE; i++) {
        for(int y = i+1; y < SIZE; y++) {
            if (Playlist[i].artist > Playlist[y].artist) {
                ListOfSongs temp = Playlist[i];
                Playlist[i] = Playlist[y];
                Playlist[y] = temp;
            }
        }
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

int main() {

    int SIZE = 10;

    ListOfSongs Playlist[10];
    
    getData(Playlist, SIZE);

    sortList(Playlist, SIZE);

    displayList(Playlist, SIZE);
}