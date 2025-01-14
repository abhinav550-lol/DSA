class TrieNode {
public:
  char data;
  TrieNode* children[26];
  bool isTerminal;
  int childCount;

  TrieNode(int x) : data(x) {
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    isTerminal = false;
    childCount = 0;
  }
};

class Trie {
public:
  TrieNode* root;

  Trie() {
    root = new TrieNode('\0');
  }

  void insert(string word) {
    insertUtil(root, word);
  }

private:
  void insertUtil(TrieNode* root, string word) {
    if (word.size() == 0) {
      root->isTerminal = true;
      return;
    }
    int index = word[0] - 'a';
    TrieNode* child;

    if (root->children[index]) {
      child = root->children[index];
    } else {
      root->childCount++;
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }
    insertUtil(child, word.substr(1));
  }
};

// Separate function to find Longest Common Prefix (LCP)
string longestCommonPrefix(Trie& trie, vector<string>& arr, int n) {
  string firstString = arr[0];
  string res = "";
  TrieNode* temp = trie.root;

  for (int i = 0; i < firstString.size(); i++) {
    char ch = firstString[i];
    if (temp->childCount == 1) {
      res.push_back(ch);
      int index = ch - 'a';
      temp = temp->children[index];
    } else {
      break;
    }
    if (temp->isTerminal) break;
  }

  return res;
}
