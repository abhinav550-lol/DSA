#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
   map<string , int> orderedMap;
   unordered_map<string , int> unorderedMap;

    //insertion 
    orderedMap["LOL"] = 3;
    orderedMap.insert(make_pair("ROFL" , 4));

    unorderedMap["LOL"] = 3;
    unorderedMap.insert(make_pair("ROFL" , 4));

    //deletion 
    orderedMap.erase("LOL");
    unorderedMap.erase("LOL");
    cout << orderedMap.size() << endl;

    //searching and iterating
    cout << orderedMap.count("LOL") << endl;
    cout << orderedMap.at("ROFL")<< endl;
    cout<< orderedMap["NOOOO"];

    cout << orderedMap.size() << endl;
    cout << unorderedMap.size() << endl;

    for(auto i : orderedMap) cout << i.first <<' ' << i.second<<endl;
    for(auto i : unorderedMap) cout << i.first <<' ' << i.second<<endl;

    cout << endl;

    map<string , int> :: iterator it = orderedMap.begin();
    while(it != orderedMap.end()){
        cout << it->first << ' ' << it->second <<endl;
        it++;
    }


  return 0;
}