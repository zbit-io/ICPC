#include<bits/stdc++.h>
using namespace std;
class Solution1 {
    /**
    *@Time:2023-09-24 20:01:06
    *@Status:AC
    *@Approach:横向搜索
    *@Complexity Analysis:
    *@Example usage:
    **/
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return ""; // If the input vector is empty, return an empty string.
        }

        // Find the minimum length among all strings
        int minLen = INT_MAX;
        for (const string& s : strs) {
            minLen = min(minLen, (int)s.length());
        }

        // Compare characters at each position for all strings
        for (int i = 0; i < minLen; ++i) {
            char currentChar = strs[0][i]; // Character at the current position
            for (const string& s : strs) {
                if (s[i] != currentChar) {
                    return s.substr(0, i); // Return the common prefix found so far
                }
            }
        }

        return strs[0].substr(0, minLen); // If all strings match, return the common prefix of the minimum length
    }
};
class Trie{
   
    struct TrieNode{
        bool isEnd;
        TrieNode* children[130];
        // unordered_map<char,TrieNode*>children;
        TrieNode():isEnd(false){
            for (int i = 0; i < 130; ++i) {
            children[i] = nullptr; // 初始化所有子节点为nullptr
        }
        };
    };
    TrieNode* root;
    public:
    Trie():root(new TrieNode()){}
    void insert(const string& s){
        TrieNode* backup=root;
      
        for(const char& c:s){

            if(!backup->children[c]){
        
                backup->children[c]=new TrieNode;
            }
            backup=backup->children[c];
            
        }
        backup->isEnd=true;
        
        // cout<<"maxPe:"<<t.size()<<endl;
    }
    string getLongestPrefix(){
        TrieNode* backup=root;
        string ans="";
        while(backup){
            // TireNode* c=backup->children;
            int t=0;
            char c;
            for(int i=0;i<130;i++){
                if(backup->children[i]!=nullptr){
                    t++;
                    c=i;
                    
                }   
            }
            if(t==1&&!backup->isEnd){
                ans.push_back(c);
                backup=backup->children[c];
            }
            else break;
            
            
        }
        return ans;
    }
    

};
class Solution {
    Trie trie;
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)return strs[0];
        for(const auto& i:strs){
            if(i=="")return "";
            trie.insert(i);
        }
        return trie.getLongestPrefix();
    }
};

int main() {
    vector<string>arr{"flower","flow","flight"};
    cout<<Solution(). longestCommonPrefix(arr);
    return 0;
}