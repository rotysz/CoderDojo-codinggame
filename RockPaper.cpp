#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 struct GameInfo {
     int player;
     string move;
     int lose_players[10];
 };
 
 int CheckWinner ( string p1, string p2) {
  
  char p1_char = p1[0];
  char p2_char = p2[0];

  string WinPairs = "CP PR RL LS SC CL LP PS SR RC";
   
  if ( p1 == p2) 
     return -1;
  for (int i =0; i<WinPairs.length();i+=3) {
      if (p1_char == WinPairs[i] && p2_char == WinPairs[i+1])
        return 0;
       if ((p2_char == WinPairs[i] && p1_char == WinPairs[i+1])) 
         return 1;
  }   
  cerr << "UNNOWN PAIR";
  return 100; 
 }

int main()
{
    int N;
    int poziom = 0;
    GameInfo tab_in[1024];
    GameInfo tab_out[512];
    int tab_out_size;
    int tab_in_size;

    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int NUMPLAYER;
        string SIGNPLAYER;
        cin >> NUMPLAYER >> SIGNPLAYER; cin.ignore();
        tab_in[i].player = NUMPLAYER;
        tab_in[i].move= SIGNPLAYER;
    }
    tab_out_size = N/2;
    tab_in_size = N;
    while(tab_out_size >0) {
        int j =0;
       for (int i=0, j=0; i< tab_in_size; i+=2,j++) {
         int win_idx;
         int lose_idx;  
         int res = CheckWinner(tab_in[i].move,tab_in[i+1].move);
         cerr <<  tab_in[i].move << tab_in[i+1].move << res <<" ";
         if (res == -1) {
             if (tab_in[i].player < tab_in[i+1].player) {
                win_idx = i;
                lose_idx = i+1;
             }  else {
                win_idx =i+1;
                lose_idx= i;
             }
                   
         } else {
             win_idx = i+res;
             lose_idx = i+1-res;
         }
         tab_out[j] = tab_in[win_idx];
         tab_out[j].lose_players[poziom]=tab_in[lose_idx].player;   
       }
       cerr << endl;
       for (int i =0; i < tab_out_size;i++) 
         tab_in[i] =tab_out[i];
       poziom++;
       tab_in_size = tab_out_size;
       tab_out_size = tab_in_size/2;   
    } 
    cout << tab_out[0].player << endl;
    cout <<  tab_out[0].lose_players[0];
    for (int i=1; i < poziom; i++)
      cout << " " << tab_out[0].lose_players[i];
    cout << endl;  
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "WHO IS THE WINNER?" << endl;
}
