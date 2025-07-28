#include<iostream>

using namespace std;

class TrieNode{
    public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode(){
        isEnd = false;
        for(int i = 0 ; i < 26 ; i++){
            children[i] = NULL;
        }
    }
};

class Trie{
    private:
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;
        for(char C : word){
            int idx = C - 'A';
            if(node->children[idx] == NULL){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word){
        TrieNode* node = root;
        for(char C : word){
            int idx = C - 'A';
            if(node->children[idx] == NULL){
                return false;
            }
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(string word){
        TrieNode* node = root;
        for(char C : word){
            int idx = C - 'A';
            if(node->children[idx] == NULL){
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};

int main(){

    Trie* objTrie = new Trie();
    cout<<"Enter the word to be inserted in the Trie: ";
    string word;
    cin>>word;
    objTrie->insert(word);
    cout<<"Enter the to be searched in the Trie: ";
    cin>>word;
    bool found = objTrie->search(word);
    cout<<(found ? "Found!" : "Not Found!")<<endl;
    cout<<"Enter the word that starts with: ";
    cin>>word;
    found = objTrie->startsWith(word);
    cout<<"Word starts with it: "<<(found ? "Yes!" : "No!")<<endl;
    return 0;
}