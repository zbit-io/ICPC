#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
       /**
       *@Time:2023-09-05 18:00:33
       *@Approach:用两个嵌套的循环，先遍历第一个股票价格，然后再遍历后续的股票价格，计算每一对股票价格之间的差值，找到最大的差值作为最大利润。最后，如果计算出的最大利润小于0，则返回0，否则返回最大利润
       *@Complexity Analysis:
            时间复杂度： 这段代码中有两个嵌套的循环。外层循环的次数是数组 prices 的大小，内层循环的次数是数组 prices 的大小减去外层循环的次数减一。因此，内外两层循环的总次数是 (n-1) + (n-2) + ... + 1 = n*(n-1)/2。因此，此代码的时间复杂度为 O(n^2)，其中 n 是数组 prices 的大小。
            空间复杂度： 此代码只使用了常数级别的额外空间，因此空间复杂度为 O(1)。
       *@Example usage:
            [7,1,5,3,6,4]
            [7,6,4,3,1]
       **/
    int maxProfit = -1e9;
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[j] - prices[i] > maxProfit) {
                maxProfit = prices[j] - prices[i];
            }
        }
    }
    return maxProfit < 0 ? 0 : maxProfit;
}
};
class BadSolution {
    /**
    *@Time:2023-09-08 10:24:37
    *@Approach:我想用单调队列来做，找出最大值和最小值，然后每次用最大值-最小值，考虑是否最小值的下标在最大值前，在就输出，但是实际上是存在[2,4,1]这种情况没有考虑到
    *@Complexity Analysis:
    *@Example usage:
    **/
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=n-1;
        deque<int>monotonicQueueMax;
        deque<int>monotonicQueueMin;
        vector<int>resultMax;
        vector<int>resultMin;
        while(i>=0){
            while(!monotonicQueueMax.empty()&&prices[monotonicQueueMax.back()]<prices[i]){
                monotonicQueueMax.pop_back();
            }
            while(!monotonicQueueMin.empty()&&prices[monotonicQueueMin.back()]>prices[i]){
                monotonicQueueMin.pop_back();
            }
            monotonicQueueMax.push_back(i);
            monotonicQueueMin.push_back(i);
            resultMax.push_back(monotonicQueueMax.front());
            resultMin.push_back(monotonicQueueMin.front());
            i--;
        }
        // for(auto i:resultMax){
        //     cout<<prices[i]<<" ";
        // }
        // cout<<" ss"<<resultMax[4]<<"ss";
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(resultMax[j]>resultMin[i]){
                    return prices[resultMax[j]]-prices[resultMin[i]];
                }

            }
        }
        
        return 0;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=1e9;
        int maxProfit=-1e9;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
            if(maxProfit<prices[i]-minPrice){
                maxProfit=prices[i]-minPrice;
            }
        }
        return maxProfit;
    }
    
};
int main() {
    vector<int>prices{5,4,3,2,1};
    cout<<Solution().maxProfit( prices);
    return 0;
    
}