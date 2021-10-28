#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
//Structure
struct Song
{
    string artist;
    string title;
};
//This function takes data from user
void getDataFromUser(Song Playlist[], int Size)
{
    cout << "***********************************Enter Song Details******************************************************" << endl;
    for (int i = 0; i < Size; i++)
    {
        fflush(stdin);
        cout << "Artist of song" << i + 1 << ":";
        getline(cin, Playlist[i].artist);
        fflush(stdin);
        cout << "Title of song" << i + 1 << ":";
        getline(cin, Playlist[i].title);
    }
}
//This function sort the playlist song using selection sort
void sortList(Song Playlist[], int Size)
{

    for (int i = 0; i < Size; i++)
    {
        for (int j = i + 1; j < Size; j++)
        {
            if (Playlist[i].artist > Playlist[j].artist)
            {
                Song temp = Playlist[i];
                Playlist[i] = Playlist[j];
                Playlist[j] = temp;
            }
        }
    }
}
//This function display the song list
void displaySong(Song Playlist[], int Size)
{
    cout << "********************Song in sorted order with Song no. artist || title *********************************" << endl;
    for (int i = 0; i < Size; i++)
    {
        cout << "Song" << i + 1 << ":" << Playlist[i].artist << "||" << Playlist[i].title << endl;
    }
}
int main()
{
    //created 10 object of song
    Song Playlist[10];
    int Size = 10;
    //get data from user
    getDataFromUser(Playlist, Size);
    //sort the song list
    sortList(Playlist, Size);
    //display the list
    displaySong(Playlist, Size);
    return 0;
}
