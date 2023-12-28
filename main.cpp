#include "functions.h" //setup
#include <iostream>
#include <string>
#include<algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  string cheese, xbox, large, grey, purple, green, master; //variable setup
  int godzilla{}, keys{}, dooku{}, chess{}, africa{}; //more variables for counting and for loops
  Game:; //game loop
  cheese=start(); //read comments in the implementation
  xbox=cheese; //copies the word into another string
  keyboard(grey, purple, green); //read comments in implementation
  cout<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A\t   "; //once the keyboard is printed the program goes back up to the very first blank line to start the game
  while (godzilla<6) { //while the user has entered less than 6 attempts
    getline(cin, large); //gets the user guess
    if (large.length()!=5){ //if the word is less or more than 5 letters
      cout<<"\033[A\033[2K\r"<<"\t   _____\n"<<"\x1b[A\t   "; //deletes the input, reprints the blank line and sets the program to the same line the user just entered
      continue; //skips the rest of code and goes back to the user input part
    }
    master = colour(cheese, large, xbox); //read comments in implementation
    for (keys=0;keys<master.size();keys++){ //loop that gets the master string and returns the proper letters back into their proper colour specific strings for the kayboard function
      if (master[keys]=='.'){ //counts the amount of times the period occurs to tell the program which variable to switch to and put the letters in
        dooku++;
        continue;
      }
      if (dooku==0&&grey.find(master[keys])==string::npos){
        grey+=master[keys];
      }
      if (dooku==1&&purple.find(master[keys])==string::npos&&green.find(master[keys])==string::npos){
        purple+=master[keys];
      }
      if (dooku==2&&green.find(master[keys])==string::npos){
        green+=master[keys];
        if (purple.find(master[keys])!=string::npos){
          purple.erase(remove(purple.begin(), purple.end(), master[keys]), purple.end());
        }
      }
    }
    for (chess=5;chess>godzilla;chess--){
      cout<<endl; //brings the consol the end of the blank lines to print the keyboard
    }
    keyboard(grey, purple, green); //check implementation for comments
    for (chess=0;chess<8-godzilla;chess++){ //brings the consol line back up to the new blank line for user input
      if (chess==0){
        cout<<"\t   ";
      }
      cout<<"\x1b[A";
    }
    dooku=0; //resets the period variable
    godzilla++; //increases the amount of guesses
    if (large==cheese){ //if the user got the word
      for (chess=5;chess>godzilla-4;chess--){ //brings the consol line to the end
        cout<<endl;
      }
      cout<<"\x1b[31m"<<"You got the word in "<<godzilla<<"!\x1b[0m"<<endl; //winning message
      goto Win; //skips the failure message
    }
  }
  cout<<"\n\n\n\x1b[31m"<<"You're a failiure *"<<cheese<<"*\x1b[0m"<<endl; //failure message if they reach max guesses without getting the word
  Win:;
  cout<<"\nEnter 1 to play again or 2 to exit: "; //asks user to see if they want to play again
  cheese.clear(); xbox.clear(); large.clear();
  grey.clear(); purple.clear(); green.clear(); master.clear(); //resets all the variables
  godzilla=0; keys=0; dooku=0; chess=0; africa=0;
  cin>>africa; //gets input
  cin.ignore();
  if (africa==1){ //retarts program again for a new game
    goto Game; //goes to the start
  }
  else {
    exit(0); //ends the game
  }
}
