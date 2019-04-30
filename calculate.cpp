#include "calculate.hpp"
#include<stdlib.h>
#include<iostream>
using namespace std;
#include<string>
#include<string.h>
#include<stdio.h>
string calculateBullAndPgia(string choice,string guess){
    if(choice.length()!=guess.length()){
        throw "Error";
    }
    int len=guess.length();
    int b=0;
    int co=0;
    char g[10]; //for holding the guess.
    char c[10]; //for holding the choice.
    bool was[len];  //an array in order to know whether the specific number is already been checked.
 //initializing the array .
    for(int i=0;i<len;i++){
        was[i]=false;
    }
    //removing the guess and choice to arrays.
    strcpy(g,guess.c_str());
    strcpy(c,choice.c_str());
     for(int i=0;i<len;i++){
         bool secIn=false;
         int index=0;
        for(int j=0;j<len;j++){
            if(choice[j]==guess[i]) {
                //for checking if exists another same number in the choice .
                for (int k = j + 1; k < len; k++) {
                    if (choice[k] == guess[i] && k == i && was[k] == false) {
                        secIn = true;
                        index = k;
                        was[k] == true;
                    }

                }
                if (secIn) {
                    b++;
                    j = len;
                }
                else{
                    if (was[j] == false) {

                    if (i == j) {
                        b++;
                    } else {
                        co++;
                    }
                    was[j] = true;
                    j = len;
                }
            }

            }
        }
     }
     string s="";
     s+=std::to_string(b);
     s+=",";
     s+=std::to_string(co);
     return s;
 }
