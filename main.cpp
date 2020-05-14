#include <iostream>
#include <unordered_map>

using namespace std;

class Node{
public:
    char alp;
    unordered_map<char, Node*> child;
    bool isWord;

    Node(char c):alp(c), isWord(false){}
};

class Trie {
public:
    /** Initialize your data structure here. */
    unordered_map<char, Node *> trieNode;

    Trie() {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        if (trieNode.find(word[0]) == trieNode.end())
            trieNode[word[0]] = new Node(word[0]);

        insert(word, 0, trieNode[word[0]]);
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (trieNode.find(word[0]) == trieNode.end())
            return false;

        return search(word, 0, trieNode[word[0]]);

    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (trieNode.find(prefix[0]) == trieNode.end())
            return false;

        return search(prefix, 0, trieNode[prefix[0]], true);
    }

    /** Delete the elemet if Found*/
    void deleteWord(string word)
    {
        if (trieNode.find(word[0]) == trieNode.end())
            return;
        if (deleteWord(word, 0, trieNode[word[0]]))
            trieNode.erase(word[0]);

    }

private:
    void insert(string word, int index, Node* node)
    {
        if (index < word.length() - 1){
            if((node->child).find(word[index+1]) == (node->child).end())
            {
                (node->child)[word[index+1]] = new Node(word[index+1]);
            }
            insert(word, index+1, (node->child)[word[index+1]]);
        }
        if (index == word.length() - 1)
            node->isWord = true;
    }
    bool search(string word, int index, Node* node, bool isPrefix = false)
    {
        if (index == word.length()-1)
            return node->isWord || isPrefix;
        else if ((node->child).find(word[index+1]) == (node->child).end())
            return false;
        else
            return search(word, index+1, (node->child)[word[index+1]], isPrefix);

    }
    bool deleteWord(string word, int index, Node* node)
    {
        if (index == word.length() - 1)
        {
            node->isWord = false;
            if (node->child.empty()) {
                delete node;
                return true;
            }
            else
                return false;
        }
        else if (node->child.find(word[index+1]) == node->child.end())
            return false;
        else{
            bool del = deleteWord(word, index+1, node->child[word[index+1]]);
            if (del && node->child.size() == 1)
            {
                delete node;
                return true;
            } else
                return false;
        }
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    Trie* obj = new Trie();
    string word = "Apple";
    string prefix = "App";
    obj->insert(word);
    bool param_2 = obj->search(word);
    bool param_3 = obj->startsWith(prefix);
    string result = param_2 ? "True":"False";
    cout<<result<<endl;
    result = param_3 ? "True":"False";
    cout<<result<<endl;

    obj->insert("Applze");
    param_3 = obj->search("Applze");
    result = param_3 ? "True":"False";
    cout<<result<<endl;

    obj->deleteWord("Apple");

    param_3 = obj->search("Apple");
    result = param_3 ? "True":"False";
    cout<<result<<endl;

    param_3 = obj->startsWith("App");
    result = param_3 ? "True":"False";
    cout<<result<<endl;

    param_3 = obj->search("App");
    result = param_3 ? "True":"False";
    cout<<result<<endl;

    obj->insert("App");
    param_3 = obj->search("App");
    result = param_3 ? "True":"False";
    cout<<result<<endl;

    obj->deleteWord("Applze");
    param_3 = obj->search("Applze");
    result = param_3 ? "True":"False";
    cout<<result<<endl;
    param_3 = obj->search("App");
    result = param_3 ? "True":"False";
    cout<<result<<endl;
    return 0;
}
