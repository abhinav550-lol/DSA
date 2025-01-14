#include <iostream>
#include <vector>
using namespace std;
 
 vector<int> reverse(vector<int> v,int pos){
    int start=pos+1,end=v.size()-1;
    vector<int> reversed;
    while(start<=end){
     swap(v[start],v[end]);
     start++;
     end--;
    }
    return v;
 }
 void printVector(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
 }

int main(){
    vector <int> v={1,2,3,4,5,6};
    int pos;
    cin>>pos;
    vector<int> Reversed=reverse(v,pos);
    printVector(Reversed);
  return 0;
}