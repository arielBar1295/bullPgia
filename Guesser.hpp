#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>


typedef unsigned int uint;
using namespace std;

 namespace bullpgia{
    class Guesser{
        protected:
        int length;
        //variables for smatrGuess.
        string answer; //for knowing the result of the guess.
        int numIn=0;   //for knowing the times the function has been called.
        int numLen=0;  //for knowing number of guesses.
        string previous="";
     public:
     virtual std::string guess(){};
     void startNewGame(int len){
         if(numIn!=0) {
             cout << "you made it in " << numIn << " guesses!" << endl;
         }
         length=len;
         //every new game, put 0 into those variables.
         numLen=0;
         numIn=0;
         previous="";
     }
     void learn(string b){
         answer=b;
         if(answer=="4,0"){

         }
     }
    };
}
