#include <iostream>
using namespace std;

int main()
{
   int rows;
   cin>>rows;
   
  for(int i=1;i<=rows*2-1;i++){
    if(rows>=i){
    for(int j=1;j<=i;j++){
      cout<<"*";
    }
    }
    if(rows<i){
     for( int j=rows-1;j>=i-rows;j--){
      cout<<"*";
     }
    }
    
    cout<<endl;
  }
  

    return 0;
}




    // int rows;
    // cin >> rows;
   
    // for(int i=1;i<=rows;i++){
    //         for(int k=1;k<=rows-i;k++){
    //             cout<<" ";
    //         }
    //     for(int j=1;j<=i;j++){
    //       cout<<"*";
    //     }
    //     cout<<endl;
    // }

// for(int i=0;i<rows;i++){
//  for(int j=0;j<rows;j++){
//      printf("*");
//    }
//      printf("\n");
//    }

    //     int count=1;
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < rows; j++)
    //     {
    //         cout<<count;
    //         count++;

    //     }
    //     cout<<endl;
    // }





    /*
    LIST OF QUESTION THAT I COULDNT DO
    1.

    1
    21
    321
    4321
   
    2.
    D
    CD
    BCD
    ABCD




   DID IT BUT NOT SATISFIED
    1. 
    ABC
    BCD
    CDE
     




    */