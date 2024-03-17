#include<iostream>
#include<vector>
#include <map>
using namespace std;
struct TireNode{
    bool isChild;
    map<char,TireNode*> children;
    TireNode():isChild(false){
    }
    
    
};
class Tire{
    TireNode* root;
    public:
    Tire(){
        root=new TireNode;
    }
    void insert(const string& s){
        TireNode* temp=root;
        for(char c:s){
            if(temp->children[c]==nullptr)temp->children[c]=new TireNode;
            temp=temp->children[c];
        }
        temp->isChild=true;
    }
    bool find(const string&s){
        TireNode* temp=root;
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
        Tire tire;
        for(auto str:substr){
            tire.insert(str);
        }
        for(auto str:wordDict){
            if(!tire.find(str)){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Tire tire;
        for(auto word:wordDict){
            tire.insert(word);
        }
        
    }
};
int main() {
   Solution(). 
    return 0;
}