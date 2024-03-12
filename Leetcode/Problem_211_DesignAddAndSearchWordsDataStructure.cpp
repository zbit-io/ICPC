#include<bits/stdc++.h>
using namespace std;
class Trie{
    struct TrieNode{
        unordered_map<char,TrieNode*> chilren;
        bool isEnd;
        TrieNode():isEnd(false){};
    };
    
    public:
    TrieNode* root;
    Trie():root(new TrieNode){};
    void insert(string s){
        TrieNode* temp=root;
        for(const char& c:s){
            if(temp->chilren[c]==nullptr){
                temp->chilren[c]=new TrieNode;

            }
            temp=temp->chilren[c];
        }
        temp->isEnd=true;
    }
    bool search(TrieNode*node,const string& word)const{
         TrieNode* temp=node;
       
        for(int i=0;i<word.size();i++){
            char c=word[i];
            if(c=='.'){
                for(const auto& pair:temp->chilren){
                    if(search(pair.second,word.substr(i+1))){
                        return true;
                    }
                }
                return false;
            }
            // if(!temp->chilren[c]){
            //     return false;
            // }
            //Tricky的地方。。。。
            if(temp->chilren.find(c)==temp->chilren.end()){
                return false;
            }
            temp=temp->chilren[c];
        }
        return temp->isEnd?true:false;
    }
    


};
class WordDictionary {
    Trie trie;
public:
    WordDictionary():trie(){
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.search(trie.root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main() {

    WordDictionary wordDictionary =  WordDictionary();
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout<<wordDictionary.search("pad")<<endl; // return False
    cout<<wordDictionary.search("bad")<<endl;; // return True
    cout<<wordDictionary.search(".ad")<<endl; // return True
    cout<<wordDictionary.search("b..")<<endl; // return True

    return 0;
}