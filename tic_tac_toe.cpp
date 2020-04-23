/*
    ██  ██ ████████ ██  ██████     ████████  █████   ██████     ████████  ██████  ███████
   ██  ██     ██    ██ ██             ██    ██   ██ ██             ██    ██    ██ ██
  ██  ██      ██    ██ ██             ██    ███████ ██             ██    ██    ██ █████
 ██  ██       ██    ██ ██             ██    ██   ██ ██             ██    ██    ██ ██
██  ██        ██    ██  ██████        ██    ██   ██  ██████        ██     ██████  ███████
*/

#include <iostream>
using namespace std;

char board[] = {'1','2','3','4', '5','6','7','8','9'};
char s[] = {'1','2','3','4', '5','6','7','8','9'};
char player,a,b;
int count = 0;

// Changing the player
TogglePlayer(char c,char d){
  if(player == c)
    player = d;
  else
    player = c;

  return 0;
}

// Drawing tic tac toe
void Draw(){
  cout << endl;
  cout << "######## ##  ######     ########  #####   ######     ########  ######  ####### " << endl;
  cout << "   ##    ## ##             ##    ##   ## ##             ##    ##    ## ##      " << endl;
  cout << "   ##    ## ##             ##    ####### ##             ##    ##    ## ####### " << endl;
  cout << "   ##    ## ##             ##    ##   ## ##             ##    ##    ## ##      " << endl;
  cout << "   ##    ##  ######        ##    ##   ##  ######        ##     ######  ####### " << endl;
  cout << endl;
  cout << " | " << board[0] << " | " << board[1] << " | " << board[2] << " | " << endl;
  cout << " ------------- " << endl;
  cout << " | " << board[3] << " | " << board[4] << " | " << board[5] << " | " << endl;
  cout << " ------------- " << endl;
  cout << " | " << board[6] << " | " << board[7] << " | " << board[8] << " | " << endl;
  cout << endl;
}

// get input from player
void input(){
  int a;
  cout << "Choose the number field " << player << ": ";
  cin >> a;
  count += 1;
  if (a == 1)
    board[0] = player;
  else if (a == 2)
    board[1] = player;
  else if (a == 3)
    board[2] = player;
  else if (a == 4)
    board[3] = player;
  else if (a == 5)
    board[4] = player;
  else if (a == 6)
    board[5] = player;
  else if (a == 7)
    board[6] = player;
  else if (a == 8)
    board[7] = player;
  else if (a == 9)
    board[8] = player;
}

// check if player is win algorithm
char check(){
  if (board[0] == board[1] && board[1] == board[2]){
    return player;
  }
  if (board[3] == board[4] && board[4] == board[5]){
    return player;
  }
  if (board[6] == board[7] && board[7] == board[8]){
    return player;
  }
  if (board[0] == board[3] && board[3] == board[6]){
    return player;
  }
  if (board[1] == board[4] && board[4] == board[7]){
    return player;
  }
  if (board[2] == board[5] && board[5] == board[8]){
    return player;
  }
  if (board[0] == board[4] && board[4] == board [8]){
    return player;
  }
  if (board[2] == board[4] && board[4] == board [6]){
    return player;
  }
  if(count == 9)
    return 'd';

return '/';
}

// clear the screen
void clear(){
  system("cls");
}

// output winner
int winner(char c){
  if(c == a ){
    cout << c << " Wins!! ()==|:::::::::::> Game Over" << endl;
    return 1;
  }
  if(c == b){
    cout << c << " Wins!! ()==|:::::::::::> Game Over" << endl;
    return 1;
  }
  if(c == 'd'){
    cout << "Draw!! ()==|:::::::::::> Game Over" << endl;
  return 1;
  }

return 0;
}

// to play playagain
int playagain(){
  char choice;
  cout << endl;
  cout << "Do you want to play again:\n";
  cout << "Y) Yes" << "\n" << "N) No" << endl;
  cout << "Choose: ";
  cin >> choice;
  if(choice == 'Y' || choice == 'y' || choice == '1')
    return 1;
  if(choice == 'N' || choice == 'n' || choice == '2')
    return 2;
return 0;
}

// Main function
int main(){
  int d = 1;
  int x = 0;
  clear();
  Draw();
  cout << "Enter Player one's character: ";
  cin >> a;
  cout << "Enter Player two's character: ";
  cin >> b;
    while(x != 1){
      clear();
      Draw();
      TogglePlayer(a,b);
      input();
      char test = check();
      clear();
      Draw();
      x = winner(test);
  }
  if(x == 1){
    d = playagain();
    if(d == 1){
      x = 0;
      count = 0;
      d = 0;
      for(int i=0;i<10;i++)
      board[i] = s[i];
      main();
    }
    else if( d == 2)
      exit(0);
  }
}
