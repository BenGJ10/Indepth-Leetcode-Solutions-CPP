/*
LeetCode: 229. Majority Element II
Link: https://leetcode.com/problems/majority-element-ii/

Problem:
Given an integer array `nums`, return all the elements that appear more than ⌊ n/3 ⌋ times.
You may return the answer in any order.

Approach:
- There can be at most two elements with frequency > n/3.
- Use the extended Boyer-Moore Voting Algorithm to find potential candidates.
- Do a second pass to verify actual counts.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int elem1, elem2;

        for(int i = 0; i < nums.size(); i++){
            if(count1 == 0 && nums[i] != elem2){
                count1++;
                elem1 = nums[i];
            }
            else if(count2 == 0 && nums[i] != elem1){
                count2++;
                elem2 = nums[i];
            }
            else if(nums[i] == elem1)   count1++;
            else if(nums[i] == elem2)   count2++;
            else{
                count1--;   count2--;
            }
        }

        vector<int> ans;
        count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == elem1)    count1++;
            if(nums[i] == elem2)    count2++;
        }
        int threshold = nums.size() / 3;
        if(count1 > threshold)    ans.push_back(elem1);
        if(count2 > threshold && elem1 != elem2)    ans.push_back(elem2);
        return ans;
    }
};