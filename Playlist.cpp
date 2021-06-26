
#include "SongEntry.h"
#include <iostream>

using namespace std;

void printMenu(string tit) {

    cout << tit << " Playlist Menu\n";
    cout << "a - Add Song\n";
    cout << "d - Remove Song\n";
    cout << "c - Change position of song\n";
    cout << "s - Output songs by specific artist\n";
    cout << "t - Output total time of playlist (in seconds)\n";
    cout << "o - Output full playlist\n";
    cout << "q - Quit\n";
    cout << "Enter your selection: ";

}

int main() {

char input;
SongEntry songs;
string id = "";
string artistName = "";
string title = "";
int currPos = 0;
int newPos = 0;

cout << "Enter the title of the playlist: ";
cin >> title;
cout << "\n";

    while (input != 'q') {

        printMenu(title);
        cin >> input;
        cout << "\n";

        switch (input) {

            case 'a':
            cout << "ADD SONG\n";
            songs.insertAfter();
            break;

            case 'd':
            cout << "Enter the id of the song: ";
            cin >> id;
            cout << "\n";
            songs.removeSong(id);
            break;

            case 'c':
            cout << "Enter the current position of the song: ";
            cin >> currPos;
            cout << "\n";
            cout << "Enter the new position: ";
            cin >> newPos;
            cout << "\n";
            songs.changePosition(currPos, newPos);
            break;

            case 's':
            cout << "Enter the name of the artist whose songs you'd like to see: ";
            cin >> artistName;
            cout << "\n";
            songs.printSongsByArtistName(artistName);
            break;

            case 't':
            cout << "The total time of playlist in seconds is " << songs.getPlaylistTime() << " seconds" << endl;
            break;

            case 'o':
            songs.printSong(title);
            break;

            case 'q':
            break;

            default:
            cout << "Invalid selection. Try again\n";
            break;

        }

    }


}
