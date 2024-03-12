#include<bits/stdc++.h>
using namespace std;

class Trie {
    struct TireNode{
        unordered_map<char,TireNode*> children;
        bool isEnd;
        TireNode():isEnd(false){};
        ~TireNode(){
            for(auto& pair:children){
                delete pair.second;
            }
        }
    
    };
    TireNode* root;
public:
    
    Trie() {
        root=new TireNode();
    }

    void insert(string word) {
        TireNode* backup=root;
        for(auto& c:word){
            if(!backup->children[c]){
                backup->children[c]=new TireNode;
            }
            backup=backup->children[c];
        }
        backup->isEnd=true;


    }
    
    bool search(string word) {
        TireNode* backup=root;
        for(const auto& c:word){
            if(!backup->children[c]){
               return false;
            }
            backup=backup->children[c];
        }
        return backup->isEnd;
    }
    
    bool startsWith(string prefix) {
        TireNode* backup=root;
        for(const auto& c:prefix){
            if(!backup->children[c]){
               return false;
            }
            backup=backup->children[c];
        }
        return true;
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
    Trie* obj = new Trie();
    obj->insert("apple");
    cout<<obj->search("app");
    cout<<obj->startsWith("app");
    return 0;
}