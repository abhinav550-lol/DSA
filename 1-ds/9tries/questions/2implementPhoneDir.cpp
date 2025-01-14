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
    void insertUtil(TrieNode* root, const string &word, int index) {
        if (index == word.size()) {
            root->isTerminal = true;
            return;
        }

        int childIndex = word[index] - 'a';
        TrieNode* child;

        if (root->children[childIndex] != NULL) {
            child = root->children[childIndex];
        } else {
            child = new TrieNode(word[index]);
            root->children[childIndex] = child;
        }
        insertUtil(root->children[childIndex], word, index + 1);
    }

    void printSuggestions(string prefix, vector<string> &suggestions, TrieNode* curr) {
        if (curr->isTerminal) {
            suggestions.push_back(prefix);
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];
            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(prefix, suggestions, next);
                prefix.pop_back();
            }
        }
    }

public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(const string &word) {
        insertUtil(root, word, 0);
    }

    vector<vector<string>> getAllSuggestions(const string &queryString) {
        vector<vector<string>> res;
        TrieNode* prev = root;
        string prefix = "";

        for (int i = 0; i < queryString.size(); i++) {
            char lastCh = queryString[i];
            prefix.push_back(lastCh);

            TrieNode* curr = prev->children[lastCh - 'a'];
            if (curr == NULL) {
                break;
            }

            vector<string> suggestions;
            printSuggestions(prefix, suggestions, curr);
            res.push_back(suggestions);
            prev = curr;
        }
        return res;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, const string &queryStr) {
    Trie t;

    for (const string &contact : contactList) {
        t.insertWord(contact);
    }

    return t.getAllSuggestions(queryStr);
}