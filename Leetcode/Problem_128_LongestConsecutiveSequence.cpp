#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>
/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/
using namespace std;
class Solution1{
    /*哈希法，
    用unordered_set去重，遍历所有元素，判断i-1是否在集合中，如果在，那么i开始的序列不可能是
    最长子序列，跳过，直到i-1不存在，则查找i+1，直到不存在，记录最长length。
    时间复杂度：O(n)
    空间复杂度：O(n)
    */
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> _sets;
        for(auto i:nums){
            _sets.insert(i);
        }
        int _max_length=0;
        for(auto i:_sets){
            if(_sets.find(i-1)==_sets.end()){
                int _target=i+1;
                int _length=1;
                while(_sets.find(_target)!=end(_sets)){
                    _length++;
                    _target++;
                }
                _max_length=max(_max_length,_length);
    
            };
            i++;
        }


        return _max_length;
    }
};

class Solution2 {
public:
    struct UniFind{
        map<int,int> _map;
        UniFind(const map<int,int> _map):_map(_map){
        }
        // int find(const int& _target){
        //     return  _map[_target]=_map[_target]==_target?_target:find(_map[_target]);
        // }
        int find(const int& _target){
            int ans=_map[_target];
            while(_target!=ans){
                ans=find(ans);
            }
            _map[_target]=ans;
            return ans;
        }
        //好奇怪，上面这种A不了
        //   int find(const int& _target) {
        //     int ans = _target;
        //     while (_map[ans] != ans) {
        //         ans = find(_map[ans]);
        //     }
        //     _map[_target] = ans;
        //     return ans;
        // }
        void merge(const int& num1,const int& num2){
            _map[num2]=num1;
        }
        

    };
    int longestConsecutive(vector<int>& nums) {
        map<int,int> _map;
        for(int i=0;i<nums.size();i++){
            _map.insert(make_pair(i,i));
        }
        UniFind uf(_map);
        for(auto i:nums){
            if(uf._map.find(i-1)!=uf._map.end()){
                uf.merge(i-1,i);
            }
        }
        int _max_length=0;
        for(auto j:nums){
            int i=uf.find(j);
            _max_length=max(_max_length,j-i+1);

        }

        return _max_length;
    }
};
int main(){
    Solution2 solution;
    vector<int> nums{0,3,7,2,5,8,4,6,0,1};

    cout<<solution.longestConsecutive(nums);
    cout<<"hello";
}
