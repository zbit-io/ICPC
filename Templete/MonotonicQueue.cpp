#include <iostream>

#include <deque>

#include <vector>

  

std::vector<int> maxInSlidingWindow(const std::vector<int>& nums, int k) {

	int n = nums.size();
	
	std::vector<int> result; // 用于存储每个滑动窗口的最大值
	
	std::deque<int> dq; // 单调队列，存储元素在 nums 中的索引
	
	  
	
	for (int i = 0; i < n; i++) {
	
	// 删除队列中不属于当前窗口的元素
	
	while (!dq.empty() && dq.front() <= i - k) {
	    dq.pop_front();
    }

  

// 删除队列中比当前元素小的元素，以确保队列单调递增 
    while (!dq.empty() && nums[dq.back()] < nums[i]) {
        dq.pop_back();
    }

    dq.push_back(i); // 将当前元素的索引加入队尾


    // 当窗口完全覆盖时，记录当前窗口的最大值

    if (i >= k - 1) {

    result.push_back(nums[dq.front()]);

    }

}

  

return result;

}

  

int main() {

std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

int k = 3;

std::vector<int> result = maxInSlidingWindow(nums, k);

  

// 输出结果

for (int i = 0; i < result.size(); i++) {

std::cout << result[i] << " ";

}

std::cout << std::endl;

  

return 0;

}