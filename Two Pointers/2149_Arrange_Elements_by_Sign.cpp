/*
LeetCode: 2149. Rearrange Array Elements by Sign
Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/

Problem:
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive 
and negative integers.
You should return the array of length n where the positives and negatives are placed alternately, 
starting with a positive number.

Constraints:
- nums.length is even
- Equal count of positive and negative numbers

-------------------------------------------------------
Approach 1:
- Create an answer vector of size n.
- Maintain two pointers:
    - pos = 0 → to place positive numbers at even indices
    - neg = 1 → to place negative numbers at odd indices
- Traverse through nums:
    - If nums[i] > 0, place at ans[pos], pos += 2
    - Else, place at ans[neg], neg += 2

Time Complexity: O(n)  
Space Complexity: O(n) (for result vector)

Approach 2:
- Use two queues/vectors:
  - Store all positives in one array.
  - Store all negatives in another array.
- Then merge them alternately.
- Time Complexity: O(n)
- Space Complexity: O(n) (extra arrays)

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int pos = 0, neg = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};
