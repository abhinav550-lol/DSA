#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char x) {
        data = x;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    bool isEmpty(TrieNode* root){
        for(int i = 0 ; i<26 ; i++){
            if(root -> children[i]){
                return false;
            }
        }
        return true;
    }
    bool searchUtil(TrieNode* root, string word) {
        if (word.size() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';

        if (root->children[index] != NULL) {
            return searchUtil(root->children[index], word.substr(1));
        } else {
            return false;
        }
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(root->children[index], word.substr(1));
    }

    void removeUtil(TrieNode* &root , string word){
        if(word.size() == 0){
            root -> isTerminal = false;
            return ;
        }
        int index = word[0] - 'A';
        TrieNode* child;
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }else{
            return ;
        }
        removeUtil(child , word.substr(1));
    }
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }
    void removeWord(string word){
        removeUtil(root , word);
    }
};

int main() {
    Trie* t = new Trie();
    t->insertWord("ABCD");
    cout << t->searchWord("ABCD") << endl; 
    t->removeWord("ABCD");
    cout << t->searchWord("ABCD") << endl; 
    return 0;
}
