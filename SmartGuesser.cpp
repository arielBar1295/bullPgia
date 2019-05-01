#include "SmartGuesser.hpp"
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <iostream>
#include <cstddef>
#include <time.h>
#include <stddef.h>
#include <sstream>
#include "calculate.hpp"
#include <set>
#include <list>
#include <iterator>
#include<cstdlib>
#include<ctime>
//General idea:keeping in a list called possibleAns which holds all possible answers ,starting eliminating the list
//bu using calculateBullAndPgia.
//using 5 guesses algorithm by knuth.

std::string SmartGuesser::guess() {
    numIn++;
    if(numIn==1) {
        //create a randomize first guess.
//         srand(time(0));
//         string first = "";
//         for (int i = 0; i < length; i++) {
//             int r = rand() % 10;
//             first += to_string(r);
//         }
//         previous = first;
//         return first;
         if(length==1){
            first="1";
            
        }
        if(length==2){
            first="12";

        }
        if(length==3){
            first="112";

        }
        if(length==4){
            first="1122";

        }
        
        previous = first;
        return first;
    }
    if(this->length==1){
        numLen++;
        //building the possibleAnswers only once!
        if(numLen==1) {
            
            for (int d1 = 0; d1 < 10; d1++)
                    possibleAns.push_back(to_string(d1));
        }
        //eliminating
        for (list<string>::iterator i = possibleAns.begin(); i != possibleAns.end(); i++) {
            string token = *i;
            if (calculateBullAndPgia(token, previous) != answer) {
                possibleAns.remove(*i--);
            }
        }
        //choose randomly from what is left in possibleAns
        srand( time(0) );
        int maxRand=possibleAns.size();
        int r = rand()%maxRand;
        std::list<string>::iterator it = possibleAns.begin();
        std::advance(it,r);
        stringstream ss;
        ss << *it;
        string str = ss.str();
        previous=str;
        return previous;

    }
    if(this->length==2) {
        numLen++;
        if(numLen==1) {
            
            for (int d1 = 0; d1 < 10; d1++) {
                for (int d2 = 0; d2 < 10; d2++) {
                        possibleAns.push_back(to_string(d1) + to_string(d2));
                    }
            }
        }
        for (list<string>::iterator i = possibleAns.begin(); i != possibleAns.end(); i++)
        {
            string token =*i;
            if (calculateBullAndPgia(token,previous) != answer) {
                possibleAns.remove(*i--);
            }
        }
        srand( time(0) );
        int maxRand=possibleAns.size();
        int nextGuess=rand()%maxRand ;
        std::list<string>::iterator it = possibleAns.begin();
        std::advance(it,nextGuess);
        stringstream ss;
        ss << *it;
        string str = ss.str();
        previous=str;
        return previous;

    }
    if(this->length==3) {
        numLen++;

        if(numLen==1) {
            
            for (int d1 = 0; d1 < 10; d1++) {
                for (int d2 = 0; d2 < 10; d2++) {
                    for (int d3 = 0; d3 < 10; d3++) {
                        possibleAns.push_back(to_string(d1) + to_string(d2) +
                                              to_string(d3));
                    }
                }
            }
        }

        for (list<string>::iterator i = possibleAns.begin(); i != possibleAns.end(); i++)
        {
            string token =*i;
            if (calculateBullAndPgia(token,previous) != answer) {
                possibleAns.remove(*i--);
            }
        }
        srand( time(0) );
        int maxRand=possibleAns.size();
        int nextGuess=rand()%maxRand ;
        std::list<string>::iterator it = possibleAns.begin();
        std::advance(it,nextGuess);
        stringstream ss;
        ss << *it;
        string str = ss.str();
        previous=str;
        return previous;

    }
    if(this->length==4 ) {
        numLen++;

  if(numLen==1) {
      
      for (int d1 = 0; d1 < 10; d1++) {
          for (int d2 = 0; d2 < 10; d2++) {
              for (int d3 = 0; d3 < 10; d3++) {
                  for (int d4 = 0; d4 < 10; d4++) {
                      possibleAns.push_back(to_string(d1) + to_string(d2) +
                                       to_string(d3) + to_string(d4));
                  }
              }
          }
      }
  }

        for (list<string>::iterator i = possibleAns.begin(); i != possibleAns.end(); i++)
        {
            string token =*i;
            if (calculateBullAndPgia(token,previous) != answer) {
                 possibleAns.remove(*i--);
            }
        }
        srand( time(0) );
        int maxRand=possibleAns.size();
        int nextGuess=rand()%maxRand ;
        std::list<string>::iterator it = possibleAns.begin();
        std::advance(it,nextGuess);
        stringstream ss;
     ss << *it;
        string str = ss.str();
        previous=str;
        return previous;

    }
}
