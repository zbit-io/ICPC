#include <bits/stdc++.h>
using namespace std;
class MaxQueue {
public:
    deque<int> mq;
    deque<int> nums;
    
    

    MaxQueue() {
    }
    
    int max_value() {
        if(mq.size()==0)return -1;
        return mq.front();
    }
    
    void push_back(int value) {
        while(!mq.empty()&&mq.back()<value){
            mq.pop_back();
        }
        mq.push_back(value);
        nums.push_back(value);
    }
    
    int pop_front() {
        if(mq.size()==0){
            return -1;
        }
        int value=nums.front();
        nums.pop_front();
        if(mq.front()==value)mq.pop_front();
        return value;
    }
};