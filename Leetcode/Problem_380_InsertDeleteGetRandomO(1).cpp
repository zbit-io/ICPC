#include<bits/stdc++.h>
using namespace std;
class RandomizedSet {
    unordered_map<int,bool>map;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto p=map.find(val);
        if(p==map.end()){
            map[val]=true;
        }else{
            return false;
        }
        return true;
    }
    
    bool remove(int val) {
        auto p=map.find(val);
        if(p==map.end()){
            return false;
        }else{
            map.erase(p);
            return true;
        }
    }
    
    int getRandom() {
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<int> uniform_dist(0, map.size()-1);
        int random_number = uniform_dist(rng);
        auto p=map.begin();
        advance(p,random_number);
        return p->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main() {
    vector<bool>a(2e31);
    return 0;
}