#include <iostream>
#include <string>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
}

void ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   if (option == 'o'){
      cout << endl << playlistTitle << " - OUTPUT FULL PLAYLIST";
      if(headNode->GetNext() == nullptr){
         cout << endl << "Playlist is empty" << endl;
      }
      int count = 1;
      while (headNode->GetNext() != nullptr){
         cout << endl;
         cout << count << "." << endl;
         cout << "Unique ID: " << headNode->GetNext()->GetID() << endl;
         cout << "Song Name: " << headNode->GetNext()->GetSongName() << endl;
         cout << "Artist Name: " << headNode->GetNext()->GetArtistName() << endl;
         cout << "Song Length (in seconds): " << headNode->GetNext()->GetSongLength() << endl;
         count++;
         headNode = headNode->GetNext();
      }
   }
   else if (option == 'd'){
      string uniqueID;
      string songName;
      cout << endl << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      getline(cin, uniqueID);
      while (headNode -> GetNext() != nullptr){
         if (headNode->GetNext()->GetID() == uniqueID){
            PlaylistNode* temp = headNode->GetNext()->GetNext();
            songName = headNode->GetNext()->GetSongName();
            delete headNode->GetNext();
            headNode->SetNext(temp);
            cout << "\"" << songName << "\" removed." << endl;
         }
         headNode = headNode->GetNext();
      }
   }
   else if (option == 's'){
      string artistName;
      int count = 1;
      cout << endl << "OUPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name:" << endl;
      getline(cin, artistName);
      while (headNode -> GetNext() != nullptr){
         if (headNode->GetNext()->GetArtistName() == artistName){
            cout << endl << count << "." << endl;
            cout << "Unique ID: " << headNode->GetNext()->GetID() << endl;
            cout << "Song Name: " << headNode->GetNext()->GetSongName() << endl;
            cout << "Artist Name: " << headNode->GetNext()->GetArtistName() << endl;
            cout << "Song Length (in seconds): " << headNode->GetNext()->GetSongLength() << endl;
         }
         count++;
         headNode = headNode->GetNext();
      }
   }
   else if (option == 't'){
      cout << endl << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      int totalTime = 0;
      while (headNode -> GetNext() != nullptr) {
         totalTime += headNode -> GetNext() -> GetSongLength();
         headNode = headNode->GetNext();
      }
      cout << "Total time: " << totalTime << " seconds" << endl;
   }
   else if (option == 'a'){
      cout << endl << "ADD SONG" << endl;
      string uniqueID;
      string songName;
      string artistName;
      string songLengthString;
      int songLength;
      
      cout << "Enter song's unique ID:";
      getline(cin, uniqueID);
      cout << endl;
      cout << "Enter song's name:";
      getline(cin,songName);
      cout << endl;
      cout << "Enter artist's name:";
      getline(cin,artistName);
      cout << endl;
      cout << "Enter song's length (in seconds):";
      getline(cin,songLengthString);
      songLength = stoi(songLengthString);
      cout << endl;
      
      PlaylistNode* newSong = new PlaylistNode(uniqueID, songName, artistName, songLength);
      while (headNode->GetNext() != nullptr){
         headNode = headNode->GetNext();
      }
      headNode->InsertAfter(newSong);
   }
   cout << endl;
}

int main() {
   /* Type your code here */
   PlaylistNode* head = new PlaylistNode();
   string playlistTitle;
   string choice;
   
   cout << "Enter playlist's title:" << endl << endl;
   getline(cin, playlistTitle);
   PrintMenu(playlistTitle);
   cout << endl << "Choose an option:";
   getline(cin, choice);
   cout << choice;
   ExecuteMenu(choice[0], playlistTitle, head);
   
   while(choice != "q"){
      PrintMenu(playlistTitle);
      cout << endl << "Choose an option:";
      getline(cin, choice);
      cout << choice;
      ExecuteMenu(choice[0], playlistTitle, head);
   }
   
   return 0;
}
