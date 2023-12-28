#include "functions.h" //setup
#include <iostream>
#include <string>
#include<algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

string start(){ //start begins the game with outputting the title bolded and in different colours and prints the blank lines. It also chooses the random word from the list I've created and returns the word back into the program. 
  cout << "\033[2J\033[0;0H"; //clears the program and prints out the title
  cout<<"\t   \e[1m\033[31mW\033[33mO\033[32mR\033[34mD\033[35mL\033[36mE\033[0m \e[0m"<<endl;
  int panama{};
  for (panama=0;panama<6;panama++){ //prints the blank lines
    cout<<"\t   _____\n";
  }
  string s="cross"; //test word
  string master[100]={ //list of 100 words
        "apple", "beach", "chair", "daisy", "early",
        "faith", "grape", "house", "igloo", "jelly",
        "kings", "lemon", "mango", "noble", "ocean",
        "piano", "quiet", "roast", "salty", "tiger",
        "unity", "vivid", "whale", "xenon", "yacht",
        "zebra", "abide", "brave", "chaos", "dough",
        "eager", "flame", "grace", "heart", "injury",
        "jumbo", "karma", "lucky", "mirth", "nymph",
        "oasis", "peace", "quest", "realm", "shiny",
        "tango", "upset", "vocal", "wreck", "young",
        "zealot", "afire", "blast", "chair", "deity",
        "eagle", "fable", "gloom", "haste", "inert",
        "joker", "knack", "latch", "merry", "novel",
        "ozone", "pride", "quake", "rider", "samba",
        "talon", "unify", "vibes", "waltz", "yield",
        "zesty", "alarm", "bliss", "chill", "dwarf",
        "evoke", "fancy", "grief", "humor", "inure",
        "jolly", "knead", "latch", "merry", "nylon",
        "overt", "prize", "query", "ripen", "satin",
        "table", "uncle", "verse", "watch", "youth"
    };
  srand(time(NULL)); //time makes sure it's randomized
  return master[rand()%100]; //returns the random word
  //return s;
}

string colour(string cheese, string large, string xbox){ //colour handles most of the "graphics" of the game. The purpose is to print out the correct colours in the user inputed word that corresponds to the word they are trying to guess (the master/real word per se). It also stores which letters are which colours and returns those values back into the program for further computation.
  cout<<"\033[A\33[2KT\r"<<"       "; //deletes the line so that I can print out each individual letter in its proper colour
  string master, grey, purple, green; //creates variables for the different colours and one master one. Will be important for the "keyboard" function
  int rock{}, soup{}, japan{}, pasta{}, one{5}, two{5}, three{5}, four{5}, five{5}; //variables for for loops
  for (rock=0; rock<cheese.size(); rock++){ //loop that checks each inputted letter
    if (large[rock]>=65&&large[rock]<=90){
      large[rock]+=32; //changes to lowercase if upercase
    }
    if (large[rock]==cheese[rock]){ //if the letter is equal to the letter in the real word
      cout<<"\x1b[32m"<<large[rock]<<"\x1b[0m"; //prints letter in green
      if (green.find(large[rock])==string::npos){ //if there isnt already the letter in the "green" list/string array then add that letter in
        green+=large[rock];
        for (japan=0; japan<xbox.size();japan++){ //goes through the copy of the real word and deletes the letter than has been printed in green. 
          if (xbox[japan]==large[rock]){
            xbox.erase(xbox.begin() + japan);
          }
        }
      }
      continue; // goes back to start of for loop
    }
    if (large[rock]!=cheese[rock]){ //if it doesnt match directly
      for (soup=0;soup<cheese.size();soup++){ //checks that inputted letter against every letter in the real word to see if it matches
        if (large[rock]==cheese[soup]&&xbox.find(cheese[soup])!=string::npos
          &&cheese[soup]!=large[soup]&&soup!=one&&soup!=two&&soup!=three&&soup!=four&&soup!=five){ //if there is a match, if the program finds the letter in the copy, meaning it hasnt already been checked/used up, if that letter in the real word and its corresponding letter in the inputted word dont match, and if we havent already checked and used up that instance in the checking process.
          cout<<"\x1b[35m"<<large[rock]<<"\x1b[0m"; //prints the letter in purple
          if (one==5){ //makes sure the program only checks that instance of the real word(letter) once if it is purple
            one=soup; //saves this instance 
          }
          else if (two==5){
            two=soup;
          }
          else if (three==5){
            three=soup;
          }
          else if (four==5){
            four=soup;
          }
          else if (five==5){
            five=soup;
          }
          if (purple.find(large[rock])==string::npos){ //if there isnt already the letter in the "purple" list/string array then add that letter in
            purple+=large[rock];
          }
          for (japan=0; japan<xbox.size();japan++){ //goes through the copy of the real word and deletes the letter than has been printed in purple. 
            if (xbox[japan]==large[rock]){
            xbox.erase(xbox.begin() + japan);
            goto Loop; //skips the default grey printout of the letter
            }
          }
        }
      }
    cout<<"\x1b[2m"<<large[rock]<<"\x1b[0m"; //prints the grey letter if nothing is found
    Loop:;
    }
  }
  for (pasta=0;pasta<cheese.size();pasta++){ //checks each letter in inputted 
    if (green.find(large[pasta])==string::npos&&purple.find(large[pasta])==string::npos&&grey.find(large[pasta])==string::npos){
      grey+=large[pasta]; //if it is not found in any other string then add it to the grey string variable
    }
  }
  cout<<endl;
  return grey+"."+purple+"."+green; //since I couldn't figure out how to return mutiple values I return all of the colour specific strings separated by periods so that it will be easier to put them into their proper variables back in the main program
}

void keyboard(string grey, string purple, string green){ //keyboard prints the "real time" updating keyboard that displays the keys/letters with their corresponding colours
  string alpha = "qwertyuiopasdfghjklzxcvbnm"; //creates the keys in the qwerty format order
  int i, k; //for loop variables
  for (i=0;i<alpha.size();i++){ //this loop goes through each letter in the string alpha
    for (k=0; k<grey.size();k++){ //each of these 3 nested for loops checks to see if that letter in alpha has a corresponding colour assigned to it from the grey, purple, green variables the function imports.
      if (alpha[i]==grey[k]){
        cout<<" \x1b[2m"<<alpha[i]<<"\x1b[0m";
        goto Loop; //makes sure that once it is printed in the correct colour, it skips the part of the code where it prints it in default white
      }
    }
    for (k=0; k<purple.size();k++){
      if (alpha[i]==purple[k]){
        cout<<" \x1b[35m"<<alpha[i]<<"\x1b[0m";
        goto Loop;
      }
    }
    for (k=0; k<green.size();k++){
      if (alpha[i]==green[k]){
        cout<<" \x1b[32m"<<alpha[i]<<"\x1b[0m";
        goto Loop;
      }
    }
    cout<<" "<<alpha[i];
    Loop:
    if (alpha[i]=='p'){ //if there is a p it will skip a line
      cout<<endl<<" ";
    }
    if (alpha[i]=='l'){ //if there is an l it will skip a line to keep with a regular/normal keyboard layout
      cout<<endl<<"  ";
    }
  }
  cout<<endl;
}