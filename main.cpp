#include <iostream>
#include <unordered_map>

using namespace std;

class Trie
{
    public:
    unordered_map<char, Trie*> ele;
    bool isWord;
    void insert(string word)
    {
        Trie* node = this;
        for(int i = 0; i < word.length(); ++i)
        {
            if(node->ele.find(word[i]) == node->ele.end())
                node->ele[word[i]] = new Trie();
            node = node->ele[word[i]];   
        }
        node->isWord = true;
    }
    
    bool search(string word)
    {
        Trie* node = this;
        for(int i = 0; i < word.length(); ++i)
        {
            if(word[i] != '.'){
                if(node->ele.find(word[i]) == node->ele.end())
                   return false;
                node = node->ele[word[i]];
            }
            else
            {
                for(auto [k, v] : node->ele)
                {
                    if(v->search(word.substr(i + 1)))
                        return true;
                }
                return false;
            }
            
        }
        return node->isWord;
    }
};
class WordDictionary {
public:
    Trie* trie;
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main() {

    return 0;
}
