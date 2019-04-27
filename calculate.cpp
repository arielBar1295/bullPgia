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
    char g[10];   //putting the guess and the choice into an array.
    char c[10];
    bool was[len];
    for(int i=0;i<len;i++){
        was[i]=false;
    }
    strcpy(g,guess.c_str());
    strcpy(c,choice.c_str());
     for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(choice[j]==guess[i]){
                if(was[j]==false){
               
                if(i==j){
                    b++;
                }
                else{
                    co++;
                }
                was[j]=true;
                 j=len;
            }
            }
        }
     }
     string s="";
     s+=std::to_string(b);
     s+=",";
     s+=std::to_string(co);
     cout<<s<<endl;
     return s;
 }