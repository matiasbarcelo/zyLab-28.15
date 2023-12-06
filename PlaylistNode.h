#ifndef PLAYLISTNODEH
#define PLAYLISTNODEH

#include <iostream>
#include <string>
using namespace std;

class PlaylistNode {
   private:
      string uniqueID;
      string songName;
      string artistName;
      int songLength;
      PlaylistNode* nextNodePtr = nullptr;
   
   public:
      PlaylistNode();
      PlaylistNode(string ID, string song, string artist, int length);
      
      void SetID(string ID){uniqueID = ID;}
      void SetSongName(string song){songName = song;}
      void SetArtistName(string artist){artistName = artist;}
      void SetSongLength(int length) {songLength = length;}
      
      string GetID();
      string GetSongName();
      string GetArtistName();
      int GetSongLength();
      PlaylistNode* GetNext();
      
      void InsertAfter(PlaylistNode* nodePtr);
      void SetNext(PlaylistNode* nodePtr);
      void PrintPlaylistNode();
   };
   
#endif
