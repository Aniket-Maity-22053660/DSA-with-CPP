#include<iostream>
#include<vector>

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
    TrieNode* root;

    public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        for(char C : word){
            int idx = C - 'a';
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
            int idx = C - 'a';
            if(node->children[idx] == NULL){
                return false;
            }
            node = node->children[idx];
        }
        return node->isEnd;
    }
    bool startsWith(string prefix){
        TrieNode* node = root;
        for(char C : prefix){
            int idx = C - 'a';
            if(node->children[idx] == NULL){
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
    void remove(string word){
        TrieNode* node = root;
        bool ans = removeUtil(node, word, 0);
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
            return !hasChildren(root);
        }
        int idx = word[depth] - 'a';
        bool ans = removeUtil(root->children[idx], word, depth + 1);
        if(ans){
            delete root->children[idx];
            root->children[idx] = NULL;
            return !root->isEnd && !hasChildren(root);
        }
        return false;
    }
    bool hasChildren(TrieNode* root){
        for(int i = 0 ; i < 26 ; i++){
            if(root->children[i] != NULL){
                return true;
            }
        }
        return false;
    }
    void checkSuggestions(){
        TrieNode* node = root;
        string prefix;
        cout<<"Enter the prefix to find the suggestions: ";
        cin>>prefix;
        vector<string> result;
        for(char C : prefix){
            int idx = C - 'a';
            if(node->children[idx] == NULL){
                cout<<"No suggestions were found!"<<endl;
                return;
            }
            node = node->children[idx];
        }
        checkUtil(node, prefix, result);
        if(result.empty()){
            cout<<"No suggestions were found!"<<endl;
        }else{
            cout<<"Given word: "<<prefix<<endl;
            cout<<"Suggestions:-"<<endl;
            for(string str : result){
                cout<<str<<'\n';
            }
        }
    }
    void checkUtil(TrieNode* node, string prefix, vector<string> &result){
        if(node->isEnd){
            result.push_back(prefix);
        }
        for(int i = 0 ; i < 26 ; i++){
            if(node->children[i] != NULL){
                char c = 'a' + i;
                checkUtil(node->children[i], prefix + c, result);
            }
        }
        return;
    }
};

int main(){
    Trie* obj1 = new Trie();
    obj1->insert("aniket");
    obj1->insert("aniketking");
    obj1->insert("aniketkingstar");
    cout<<"Enter the word to be searched: ";
    string word;
    cin>>word;
    bool found = obj1->search(word);
    obj1->remove("aniketkingstar");
    if(found){
        cout<<word<<" was found in the directory!"<<endl;
    }else{
        cout<<word<<" was not found in the directory!"<<endl;
    }
    obj1->checkSuggestions();

    return 0;
}