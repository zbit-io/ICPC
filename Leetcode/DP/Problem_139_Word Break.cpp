#include<iostream>
#include <unordered_map>
#include<vector>
#include <map>
using namespace std;
struct TrieNode{
    bool isChild;
    unordered_map<char,TrieNode*> children;
    TrieNode():isChild(false){
    }
    
    
};
class Trie{
    TrieNode* root;
    public:
    Trie(){
        root=new TrieNode;
    }
    void insert(const string& s){
        TrieNode* temp=root;
        for(char c:s){
            if(temp->children[c]==nullptr)temp->children[c]=new TrieNode;
            temp=temp->children[c];
        }
        temp->isChild=true;
    }
    bool find(const string&s){
        TrieNode* temp=root;
        for(int i=0;i<s.size();i++){
            if(temp->children[s[i]]==nullptr){
                return false;
            }
            temp=temp->children[s[i]];
        }
        return temp->isChild?true:false;
    }
};
class WASolution {
public:
    void calculateSubStr(vector<string>& substr,string s){
        int n=s.size();
        for(int i=0;i<n;i++){
            string t="";
            for(int j=i;j<n;j++){
                t=t+s[j];
                substr.push_back(t);
            }
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<string> substr;
        calculateSubStr(substr, s);
        Trie Trie;
        for(auto str:substr){
            Trie.insert(str);
        }
        for(auto str:wordDict){
            if(!Trie.find(str)){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie Trie;
        for(auto word:wordDict){
            Trie.insert(word);
        }
        const int m=wordDict.size();
        const int n=s.size();
        vector<int>dp(n,false);
        dp[0]=true;
        for(int i=1;i<n;i++){
            bool isFind=false;
            for(int k=0;k<i;k++){
                if(dp[k]==0)continue;//如果dp[i]为false则不必要检查
                string t1;
                for(int j=k;j<i;j++){
                    t1+=dp[j];
                }
                isFind=Trie.find(t1);
                if(isFind)break;//找到了一个就可以结束了
            }
            dp[i]=isFind;
        }
        return dp[n-1];

        
    }
};
int main() {
    
    Solution(). 
    return 0;
}