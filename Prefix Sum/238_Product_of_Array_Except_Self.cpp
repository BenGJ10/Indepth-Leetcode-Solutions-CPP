/*
LeetCode: 238. Product of Array Except Self
Link: https://leetcode.com/problems/product-of-array-except-self/

Problem:
Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to
the product of all the elements of `nums` except `nums[i]`.

You must solve it **without division** and in **O(n)** time.

Approach:
- First pass: Build prefix product array (excluding the current index).
- Second pass (in reverse): Multiply each index with the suffix product (also excluding current).
- This avoids extra space by updating the result vector in-place.

Time Complexity: O(n)
Space Complexity: O(1) extra space (excluding output array)
*/

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size, 1);

        int prefix = 1;
        for(int i = 0; i < size; i++){
            ans[i] = prefix;
            prefix = prefix * nums[i];  
        }

        int suffix = 1;
        for(int i = size - 1; i >= 0; i--){
            ans[i] = ans[i] * suffix;
            suffix = suffix * nums[i]; 
        }
        return ans;
    }
};