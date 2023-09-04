/**
 * @file 704.cpp
 * @brief
 * @author 
 * @version 1.0
 * @date 2023-09-04
 */
#include <bits/stdc++.h>
#include <linux/limits.h>
#include <vector>

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
    std::vector<int> numbers; 
    int i=0;
    ifstream in(s, ios::binary | ios::in);
    while (in.getline(buf, MAX_LINE_SIZE)) {
        std::stringstream ss(buf); 
             int num;  
        while (ss >> num) {  
            numbers.push_back(num);  
        } 
        // cout<<<<endl;
        if (ss.rdbuf()->in_avail() != 0) {  
            std::cerr << "Error: Unexpected characters found after numbers." << std::endl;  
        }  
        // 输出结果到控制台  
        for (const auto &num : numbers) {  
            std::cout << num << " ";  
        }
    // while(in>>buf[i]){
    //     i++;
    // std::cout<< buf[i] <<std::endl;
    }
    // int arr[size(buf)];
    // std::copy(buf.begin(), buf.end(), arr);
    Solution sol;
    auto ans = sol.search(numbers,3 );
    std::cout << endl<<ans << std::endl;
    
    return 0;
}
