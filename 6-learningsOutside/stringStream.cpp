//divides a string into a stream of words to operate on 
/*
class Solution {
public:
    int isPrefixOfWord(string s, string t) {
        stringstream ss(s);
        string word;
        int index = 1;

        while(ss >> word){
            if(word.find(t) == 0){
                return index;
            }
            index++;
        }
        return -1;
    }
};
*/

/*
A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin). To use stringstream, we need to include sstream header file. The stringstream class is extremely useful in parsing input. 

Basic methods are:

clear()- To clear the stream.
str()- To get and set string object whose content is present in the stream. 
operator <<- Add a string to the stringstream object. 
operator >>- Read something from the stringstream object.
stringstream is a versatile class for manipulating strings in memory. The C++ Course explains how to use stringstream for input and output operations, enhancing your string handling skills.
*/

// C++ program to count words in  
// a string using stringstream.
#include <iostream>
#include <sstream>
#include<string>
using namespace std;

int countWords(string str)
{
    // Breaking input into word 
    // using string stream
  
    // Used for breaking words
    stringstream s(str); 
  
    // To store individual words
    string word; 

    int count = 0;
    while (s >> word)
        count++;
    return count;
}

// Driver code
int main()
{
    string s = "geeks for geeks geeks "
               "contribution placements";
    cout << " Number of words are: " << countWords(s);
    return 0;
}