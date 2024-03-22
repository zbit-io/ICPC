#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class MinStack {
    int arr[300000];
    int curr=0;
    stack<int>minS;
public:
    MinStack() {
        minS.push( std::numeric_limits<int>::max());
    }
    
    void push(int val) {
        arr[curr++]=val;
        if(val<=minS.top()){
            minS.push(val);
        }
    }
    
    void pop() {
        if(curr!=0){
            if(arr[curr-1]==minS.top()){
                minS.pop();
            }
            curr--;
        }
    }
    
    int top() {
        if(curr!=0){
            return arr[curr-1];
        }
        return 0;
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
//    Solution(). 
    return 0;
}
