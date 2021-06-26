#include <iostream>
#include <string>

using namespace std;
class SongEntry {

    public:

        int total = 0;
        SongEntry(); // done
        SongEntry(string id, string sname, string aname, int slength); //done 
        void moveHead(int currPos, int newPos); // done
        void moveTail(int currPos, int newPos); // done
        void moveNodeToHead(int currPos, int newPos); // done
        void moveNodeToTail(int currPos, int newPos); // done
        void moveNodeUp(int currPos, int newPos); // done
        void moveNodeDown(int currPos, int newPos); // done
        void insertAfter(); // done
        void removeSong(string remid); // done
        void changePosition(int currPos, int newPos); // done
        void printSongsByArtistName(string artName); // done
        void setNext(SongEntry* next); // done
        string getID(); // done 
        string getSongName(); // done 
        string getArtistName(); // done 
        int getSongLength(); // done
        void setID(string id); // done 
        void setSongName(string sname); // done 
        void setArtistName(string aname); // done 
        void setLength(int slength); // done
        SongEntry* getNext(); // done 
        int getPlaylistTime(); // done
        void printSong(string title); // done


    private:

        string uniqueID;
        string artistName;
        string songName;
        int songLength;
        SongEntry* nextNodePtr;
        SongEntry* head;

};
