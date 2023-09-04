/**
 * @file 704.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2023-09-04
 */
#include <bits/stdc++.h>

using namespace std;

# lower_bound 返回最小的满足 nums[i] >= target 的 i
# 如果数组为空，或者所有数都 < target，则返回 len(nums)
# 要求 nums 是非递减的，即 nums[i] <= nums[i + 1]

# 闭区间写法
def lower_bound(nums: List[int], target: int) -> int:
    left, right = 0, len(nums) - 1  # 闭区间 [left, right]
    while left <= right:  # 区间不为空
        # 循环不变量：
        # nums[left-1] < target
        # nums[right+1] >= target
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1  # 范围缩小到 [mid+1, right]
        else:
            right = mid - 1  # 范围缩小到 [left, mid-1]
    return left  # 或者 right+1

# 左闭右开区间写法
def lower_bound2(nums: List[int], target: int) -> int:
    left, right = 0, len(nums)  # 左闭右开区间 [left, right)
    while left < right:  # 区间不为空
        # 循环不变量：
        # nums[left-1] < target
        # nums[right] >= target
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1  # 范围缩小到 [mid+1, right)
        else:
            right = mid  # 范围缩小到 [left, mid)
    return left  # 或者 right

# 开区间写法
def lower_bound3(nums: List[int], target: int) -> int:
    left, right = -1, len(nums)  # 开区间 (left, right)
    while left + 1 < right:  # 区间不为空
        mid = (left + right) // 2
        # 循环不变量：
        # nums[left] < target
        # nums[right] >= target
        if nums[mid] < target:
            left = mid  # 范围缩小到 (mid, right)
        else:
            right = mid  # 范围缩小到 (left, mid)
    return right  # 或者 left+1

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i = lower_bound(nums, target)  # 选择其中一种写法即可
        return i if i < len(nums) and nums[i] == target else -1

int main(int argc, char const *argv[]) {
    string s = string(PROJECT_PATH).append("/src/9月/09.04/704.txt");
    char buf[MAX_LINE_SIZE];
    ifstream in(s, ios::binary | ios::in);
    while (in.getline(buf, MAX_LINE_SIZE)) {
        Solution sol;
        
        auto ans = sol;
        std::cout << ans << std::endl;
    }
    return 0;
}
