#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//APPRAOCH - 2 (USING ARRAYS)
template <typename T>
class STACK
{
   public:
   //Properties
   T* stackArr;
   int stackIndex;
   int stackSize;
   STACK(int intialSize = 5): stackSize(intialSize) , stackIndex(-1){
    stackArr = new T[stackSize];
   }
   ~STACK(){
    delete []stackArr;
   }
   //Methods
    bool isEmpty()const{
        return stackIndex<0;
    }
    void push(T val){
        if(stackSize>stackIndex){
            stackIndex++;
            stackArr[stackIndex] = val;
        }else{
            throw out_of_range("STACK_OVERFLOW");
        }
    }
    T top() const {
        if(!isEmpty()){
            return stackArr[stackIndex];
        }
        throw out_of_range("STACK_UNDERFLOW");
    }
    void pop(){
        if(!isEmpty()){
            stackIndex --;
        }else{
        throw out_of_range("STACK_UNDERFLOW");
        }
    }
    int size(){
        if(!isEmpty()){
        return stackIndex+1;
        }
         else{
            return 0;
        }
    }
};

int main()
{
    STACK<int> s;
    s.push(5);
    s.push(4);
    s.push(4);
    cout << s.isEmpty() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top();
    s.push(5);


    /* <-------- Operations ---- >
    stack <int> s;
    s.push(5);
    s.push(4);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size();
    */
    return 0;
}

/* APPROACH - 1 <CHEATING>
template<typename T>
class STACK{
public:
    vector<T> data;

    void push(T val){
        data.push_back(val);
    }
    bool empty(){
       return data.size()==0 ?true : false;
    }
    void pop(){
        data.erase(data.end()-1);
    }
    int size(){
        return data.size();
    }
    int top(){
        if(!data.empty()){
            return data.at(data.size()-1);
        }else{
            cout<<"Stack is Empty";
        }
    }
};
*/