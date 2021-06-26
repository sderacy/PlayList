#include <iostream>
#include <string>
#include "SongEntry.h"

using namespace std;

SongEntry::SongEntry() {

    uniqueID = "";
    songName = "";
    artistName = "";

    songLength = 0;

    nextNodePtr = NULL;
    head = NULL;

}

SongEntry::SongEntry(string id, string sname, string aname, int slength) {

    uniqueID = id;
    songName = sname;
    artistName = aname;
    songLength = slength;

}

SongEntry* SongEntry::getNext() {

    return nextNodePtr;

}

string SongEntry::getID() {

    return uniqueID;

}

string SongEntry::getSongName() {

    return songName;

}

string SongEntry::getArtistName() {

    return artistName;

}

int SongEntry::getSongLength() {

    return songLength;

}

void SongEntry::setID(string id) {

    uniqueID = id;

}

void SongEntry::setSongName(string sname) {

    songName = sname;

}

void SongEntry::setArtistName(string aname) {

    artistName = aname;

}

void SongEntry::setLength(int slength) {

    songLength = slength;

}

void SongEntry::setNext(SongEntry* next) {

    nextNodePtr = next;

}

void SongEntry::insertAfter() {

    string id = "";
    string sname = "";
    string aname = "";
    int slength = 0;
    cin.ignore();

    cout << "Enter song's unique id: ";
    getline(cin, id);

    cout << "Enter song's name: ";
    getline(cin, sname);

    cout << "Enter artist's name: ";
    getline(cin, aname);

    cout << "Enter song's length(in seconds): ";
    cin >> slength;

    SongEntry* newSong = new SongEntry();
    newSong->setID(id);
    newSong->setSongName(sname);
    newSong->setArtistName(aname);
    newSong->setLength(slength);

    newSong->setNext(NULL);

    if (head == NULL) {

        head = newSong;

    } else {

        SongEntry* current;

        current = head;

        while (current->getNext() != NULL) {

            current = current->getNext();

        }

        current->setNext(newSong);

    }

    total++; // total num of songs
    cout << "\n";

}

void SongEntry::removeSong(string remid) {

    int flag = 0;

    SongEntry* current;
    SongEntry* prev;

    string sname;

    current = head;
    prev = head;

    do {

        if (current->getID() == remid) {

            flag = 1;
            break;

        }

        prev = current;
        current = current->getNext();

    } while (current != NULL);

    if (flag == 0) {

        cout << "There is no song with " << "the id " << remid << " in the playlist." << endl;

    } else {

        sname = current->getSongName();

        if (head->getID() == remid) {

            head = head->getNext();
            delete current;

        } else {

            prev->setNext(current->getNext());
            delete current;

        }

        cout << sname << " has been removed" << "\n";
        total--;

    }

}

void SongEntry::moveHead(int currPos, int newPos) {

    int c = 1;
    string sname;
    SongEntry* curr;
    SongEntry* prev;

    curr = head->getNext();
    prev = head;

    SongEntry* tail;
    tail = head;

    do {

        if (c == newPos) {

            break; // fix this

        }

        prev = tail;
        tail = tail->getNext();
        c++;
    } while (tail != NULL);

    sname = head->getSongName();

    if (currPos == 1 && newPos == 2) {

        prev->setNext(tail->getNext());
        tail->setNext(prev);

        head = tail;

    } else {

        prev->setNext(head);
        head->setNext(tail->getNext());
        tail->setNext(curr);

        head = tail;

    }

    cout << "\"" << sname << "\" moved to " << "position " << newPos << endl;

}

void SongEntry::moveTail(int currPos, int newPos) {

    int c = 1;
    string sname;

    SongEntry* last;
    SongEntry* curr;
    SongEntry* prev;
    SongEntry* tail;

    prev = head;
    curr = head;
    last = head;
    tail = head;

    while (last->getNext() != NULL) {

        tail = last;
        last = last->getNext();

    }

    sname = last->getSongName();

    do {

        if (c == newPos) {

            break; //FIX

        }

        prev = curr;
        curr = curr->getNext();
        c++;

    } while (curr != NULL);

    if (newPos == 1 && total == 2) {

       prev->setNext(last->getNext());
       last->setNext(prev);
       head = last;

    } else if (newPos == 1 && total > 2) {

        last->setNext(curr->getNext());
        tail->setNext(curr);
        curr->setNext(NULL);
        head = last;

    } else if (newPos == total - 1 && newPos < currPos) {

        prev->setNext(last);
        last->setNext(curr);
        curr->setNext(NULL);

    } else {

        prev->setNext(last);
        last->setNext(curr->getNext());
        tail->setNext(curr);
        curr->setNext(NULL);

    }

    cout << "\"" << sname << "\" moved to " << "position " << newPos << endl;

}

void SongEntry::moveNodeToHead(int currPos, int newPos) {

    int c = 1;
    string sName;

    SongEntry* curr;
    SongEntry* prev;
    SongEntry* tail;

    tail = head->getNext();

    prev = head;
    curr = head;

    do {

        if (c == currPos) {

            break;

        }

        prev = curr;
        curr = curr->getNext();
        c++;

    } while (curr != NULL);

    sName = curr->getSongName();

    if (currPos == 2) {

        prev->setNext(curr->getNext());

        curr->setNext(prev);
        head = curr;

    } else {

        prev->setNext(head);
        head->setNext(curr->getNext());
        curr->setNext(tail);
        head = curr;

    }

    cout << "\"" << sName << "\" moved to ";
    cout << "position " << newPos << endl;

}

void SongEntry::moveNodeToTail(int currPos, int newPos) {

    int c = 1;
    string sName;

    SongEntry* last;
    SongEntry* curr;
    SongEntry* prev;
    SongEntry* tail;

    prev = head;
    curr = head;
    last = head;
    tail = head;

    while (last->getNext() != NULL) {

        tail = last;
        last = last->getNext();

    }

    do {

        if (c == currPos) {

            break;

        }

        prev = curr;
        curr = curr->getNext();
        c++;

    } while (curr != NULL);

    sName = curr->getSongName();

    if (c == newPos - 1) {

        prev->setNext(last);
        last->setNext(curr);
        curr->setNext(NULL);

    } else if (currPos == 1) {

       last->setNext(curr->getNext());
       tail->setNext(curr);
       curr->setNext(NULL);
       head = last;

    } else {

        prev->setNext(last);
        last->setNext(curr->getNext());
        tail->setNext(curr);
        curr->setNext(NULL);

    }

    cout << "\"" << sName << "\" moved to ";
    cout << "position " << newPos << endl;

}

void SongEntry::moveNodeUp(int currPos, int newPos) {

    int c = 1;
    int s = 1;
    string sName;

    SongEntry* curr;
    SongEntry* prev;
    SongEntry* last;
    SongEntry* tail;

    tail = head;
    last = head;
    prev = head;
    curr = head;

    do {

        if (c == currPos) {

            break;

        }

        prev = curr;
        curr = curr->getNext();
        c++;

    } while (curr != NULL);

    do {

        if (s == newPos) {

            break;

        }

        tail = last;
        last = last->getNext();
        s++;

    } while (last != NULL);

    sName = last->getSongName();

    SongEntry* nextNode;
    nextNode = last->getNext();

    if (newPos == currPos + 1) {

        prev->setNext(last);
        last->setNext(curr);
        curr->setNext(nextNode);

    } else {

        prev->setNext(last);
        last->setNext(curr->getNext());
        tail->setNext(curr);
        curr->setNext(nextNode);

    }

    cout << "\"" << sName << "\" moved to ";
    cout << "position " << newPos << endl;

}

void SongEntry::moveNodeDown(int currPos, int newPos) {

    int c = 1;
    int s = 1;
    string sName;

    SongEntry* curr;
    SongEntry* prev;
    SongEntry* last;
    SongEntry* tail;

    tail = head;
    last = head;
    prev = head;
    curr = head;

    do {

        if (c == currPos) {

            break;

        }

        prev = curr;
        curr = curr->getNext();
        c++;

    } while (curr != NULL);

    do {

        if (s == newPos) {

            break;

        }

        tail = last;
        last = last->getNext();
        s++;

    } while (last != NULL);

    sName = last->getSongName();

    SongEntry* nextNode;
    nextNode = curr->getNext();

    if (newPos == currPos - 1) {

        tail->setNext(curr);
        curr->setNext(last);
        last->setNext(nextNode);

    } else {

        tail ->setNext(curr);
        curr->setNext(last->getNext());
        prev->setNext(last);
        last->setNext(nextNode);

    }

    cout << "\"" << sName << "\" moved to ";
    cout << "position " << newPos << endl;

}

void SongEntry::changePosition(int currPos, int newPos) {

    if (currPos == newPos) {

        cout << "Re-write the distinct positions." << endl;

    } else if (currPos <= 0 || currPos > total
           || newPos <= 0 || newPos>total) {

        cout << "Invalid positions. Pick within range." << endl;

    } else if (currPos == 1) {

        moveHead(currPos, newPos);

    } else if (currPos == total) {

        moveTail(currPos, newPos);

    } else if (newPos == 1) {

        moveNodeToHead(currPos, newPos);

    } else if (newPos == total) {

        moveNodeToTail(currPos, newPos);

    } else if (currPos < newPos) {

        moveNodeUp(currPos, newPos);

    } else if (currPos > newPos) {

        moveNodeDown(currPos, newPos);

    }

}

void SongEntry::printSongsByArtistName(string artistName) {

    int c = 1;
    int f = 0;

    SongEntry* current;
    current = head;

    do {

      if (current->getArtistName() == artistName) {

          cout << c << ".\n";
          cout << "Unique ID: " << current->getID() << "\n";
          cout << "Song Name: " << current->getSongName() << "\n";
          cout << "Artist Name: " << current->getArtistName() << "\n";
          cout << "Song Length(in seconds): " << current->getSongLength() << "\n";

          f = 1;

      }

      current = current->getNext();
      c++;

    } while (current != NULL);


    if (f == 0) {

        cout << "There is no song of " << artistName << " in the playlist. \n";

    }

}

int SongEntry::getPlaylistTime() {

    if (total == 0) {

        return 0;

    }

    int totalSeconds = 0;

    SongEntry* curr;

    curr = head;

    while (curr != NULL) {

        totalSeconds = totalSeconds + curr->getSongLength();
        curr = curr->getNext();

    }

    return totalSeconds;

}

void SongEntry::printSong(string title) {

    SongEntry* curr;
    curr = head;

    int count = 1;
    cout << title << "- OUTPUT FULL PLAYLIST\n";

    do {

        cout << count << ".\n";
        cout << "Unique ID: " << curr->getID() << "\n";
        cout << "Song Name: " << curr->getSongName() << "\n";
        cout << "Artist Name: " << curr->getArtistName() << "\n";
        cout << "Song Length(in seconds): " << curr->getSongLength() << "\n";
        curr = curr ->getNext();
        count++;

    } while (curr != NULL);

    cout << endl;

}
