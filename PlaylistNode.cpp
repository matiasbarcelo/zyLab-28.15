#include "PlaylistNode.h"

   PlaylistNode::PlaylistNode(){
      uniqueID = "";
      songName = "";
      artistName = "";
      songLength = 0;
      nextNodePtr = nullptr;
   }
   
   string PlaylistNode::GetID(){return uniqueID;}
   string PlaylistNode::GetSongName(){return songName;}
   string PlaylistNode::GetArtistName(){return artistName;}
   int PlaylistNode::GetSongLength(){return songLength;}
   PlaylistNode* PlaylistNode::GetNext(){return nextNodePtr;}
   void PlaylistNode::InsertAfter(PlaylistNode* nodePtr){
      PlaylistNode* temp = nextNodePtr;
      nextNodePtr->SetNext(nodePtr);
      nodePtr->SetNext(temp);
   }
   void PlaylistNode::SetNext(PlaylistNode* nodePtr){
      nextNodePtr = nodePtr;
   }
   // Outputs uniqueID, songname, artistName, and songLength
   void PlaylistNode::PrintPlaylistNode(){
      cout << "Song Name: " << songName << endl;
      cout << "Artist Name: " << artistName << endl;
      cout << "Song Length (in seconds): " << songLength << endl;
   }
