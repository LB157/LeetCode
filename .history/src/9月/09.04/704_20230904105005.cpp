/**
 * @file 704.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2023-09-04
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            int num = nums[mid];
            if (num == target) {
                return mid;
            } else if (num > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

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
