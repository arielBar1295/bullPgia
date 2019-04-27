#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>
//#include "calculate.hpp"
//#include "bullCows.hpp"
using namespace std;
 namespace bullpgia{
    class Guesser{
        protected:
        int length;
     public:
     virtual std::string guess(){};
     void startNewGame(int len){
         length=len;
     }
     void learn(string b){
         cout<<"bulls and cows by order : "<<b<<endl;
     }
    };
}