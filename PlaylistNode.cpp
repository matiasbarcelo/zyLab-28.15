#include "PlaylistNode.h"

   PlaylistNode::PlaylistNode(){
      uniqueID = "none";
      songName = "none";
      artistName = "none";
      songLength = 0;
   }
   
   PlaylistNode::PlaylistNode(string ID, string song, string artist, int length){
      uniqueID = ID;
      songName = song;
      artistName = artist;
      songLength = length;
   }
   
   string PlaylistNode::GetID(){return uniqueID;}
   string PlaylistNode::GetSongName(){return songName;}
   string PlaylistNode::GetArtistName(){return artistName;}
   int PlaylistNode::GetSongLength(){return songLength;}
   PlaylistNode* PlaylistNode::GetNext(){return nextNodePtr;}
   
   void PlaylistNode::InsertAfter(PlaylistNode* nodePtr){
      PlaylistNode* temp = this->GetNext();
      nextNodePtr = nodePtr;
      nodePtr->SetNext(temp);
   }
   void PlaylistNode::SetNext(PlaylistNode* nodePtr){
      nextNodePtr = nodePtr;
   }
   // Outputs uniqueID, songname, artistName, and songLength
   void PlaylistNode::PrintPlaylistNode(){
      cout << "Unique ID: " << uniqueID << endl;
      cout << "Song Name: " << songName << endl;
      cout << "Artist Name: " << artistName << endl;
      cout << "Song Length (in seconds): " << songLength << endl;
   }
