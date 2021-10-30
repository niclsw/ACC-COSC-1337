// Incomplete class attempt at a song list

#include <iostream>
#include <istream>
#include <string>

class SongList {
    private:
        std::string artistName;
        std::string songTitle;
        int size;

    public:
        SongList() {
            artistName = "";
            songTitle = "";
            size = 0;
        }
        void setSize(int);
        void setArtistName(std::string);
        void setSongTitle(std::string);
        std::string sortList(std::string, std::string);
};

void SongList::setSize(int num) {
    size = num;
}

void SongList::setArtistName(std::string s) {
    artistName = s;
}

void SongList::setSongTitle(std::string s) {
    songTitle = s;
}

std::string SongList::sortList(std::string one, std::string two) {

    std::string temp;

    return temp;
}

// void SongList::sortList() {

//     for(int i = 0; i < size; i++) {

//         for(int y = i+1; y < size; y++) {
//                 // i & y
//             if (aristName > Playlist[y]) {

//                 SongList temp = Playlist[i];
//                 Playlist[i] = Playlist[y];
//                 Playlist[y] = temp;
//             }
//         }
//     }
// }

// Prototypes
// void sortList(SongList Playlist, int);

int main() {
    // Declare some variables
    int size;
    std::string artist;
    std::string song;

    // Check if user entered acceptable size
    do {
        std::cout << "How many entries do you want to make: ";
        std::cin >> size;
        if (size < 0) {
            std::cout << "Error - Amount can not be less han 0" << std::endl;
        }
        else if ((!std::cin) || (size == 0)) {
            std::cout << "Guess you didn't want to sort a list :( " << std::endl;
            return 1;
        }
    } while(size < 0);
    
    // Fancy dynamic array magic
    SongList *Playlist;
    Playlist = new SongList[size];


    // User input for Artist and Song
    // fflush clears the stream/buffer
    for(int i = 0; i < size; i++) {

        std::cout << "Artist: ";
        std::cin >> artist;
        std::fflush(stdin);

        std::cout << "Song Title: ";
        std::cin >> song;
        std::fflush(stdin);

        Playlist[i].setArtistName(artist);
        Playlist[i].setSongTitle(song);
    }

    delete[] Playlist;
}

