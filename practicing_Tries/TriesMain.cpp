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

    void remove(string word){
        TrieNode* node = root;
        removeUtil(node, word, 0);
    }

    bool removeUtil(TrieNode* root, string word, int depth){
        if(!root){
            return false;
        }
        if(depth == word.size()){
            if(!root->isEnd){
                return false;
            }
            root->isEnd = false;
            if(hasChildren(root)){
                return false;
            }
            return true;
        }
        int idx = word[depth] - 'A';
        if(removeUtil(root->children[idx], word, depth + 1)){
            delete root->children[idx];
            root->children[idx] = NULL;
            return !root->isEnd && hasChildren(root);
        }
        return false;
    }

    bool hasChildren(TrieNode* root){
        for(int i = 0 ; i < 26 ; i++){
            if(root->children[i] != NULL){
                return false;
            }
        }
        return true;
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