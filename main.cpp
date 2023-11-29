
#include <iostream>
#include "PlaylistNode.h"
using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU\na - Add song\nd - Remove song\nc - Change position of song\ns - Output songs by specific artist\nt - Output total time of playlist (in seconds)\no - Output full playlist\nq - Quit" << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
      
}

int main() {
   string playlistTitle;
   
   cout << "Enter playlist's title: " << endl;
   cin >> playlistTitle;
   
   PrintMenu(playlistTitle);
   
   return 0;
}

