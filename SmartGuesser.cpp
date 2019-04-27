#include "SmartGuesser.hpp"
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
//#include "play.hpp"
int n,a[10],b[10],c[10],d[10],B[10],C[10],b1,c1,i,j;
int numIn=0; //for following the number of guesses.
string previous ;


std::string SmartGuesser::guess() {
    numIn++;
    //first guesse is always a random one.
    if(numIn==1){
        string r="";
        int a1=(rand()%10);
        char cc='0' + a1;
        a[0]=a1;
        r+=cc;
         int b1=(rand()%10);
        char c1='0' + b1;
        b[0]=b1;
        r+=c1;
         int c11=(rand()%10);
        char c2='0' + c11;
        c[0]=c11;
        r+=c2;
         int d1=(rand()%10);
        char c3='0' + d1;
        d[0]=d1;
        r+=c3;
   
	return r;
    }
    // else{
    //  //need to know the result of the previous answer.
    // }
    else return "1234";

    
   

}