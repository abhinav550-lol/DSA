// max and min in array
#include <iostream>
using namespace std;
 
int main(){
   int num[5]={1,22,3,4,-100000};
   int max=num[0],min=num[0];
   for(int i=0;i<5;i++){
    if(num[i]>max){
        max=num[i];
    }
   }
   cout<<max<<endl;
   for(int i=0;i<5;i++){
    if(num[i]<min){
        min=num[i];
    }
   }
   cout<<min<<endl;

  return 0;
}