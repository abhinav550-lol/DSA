#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct petrolPump{
    int distance;
    int petrol; 
};

int circularTour(petrolPump p[],int N){
    int start = 0;
    int deficiet = 0;
    int balance = 0;
    for(int i=0;i<N;i++){
        balance += p[i].petrol - p[i].distance; 
        if(balance < 0){
            deficiet += balance;
            start = i+1;
            balance = 0;
        }
    }
    if(deficiet + balance >=0){
        return start;
    }else{
        return -1;
    }
}

int main(){
   
  return 0;
}