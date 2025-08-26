/*
LeetCode: 442. Find All Duplicates in an Array
Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

Problem:
Given an integer array nums of length n where each element is in the range [1, n] and appears once or twice. 
Return an array of all the integers that appear twice.

-------------------------------------------------------
Approach 1: Brute Force
- For each element, scan the rest of the array to check for duplicates.
- Time Complexity: O(n^2), too slow for large inputs.
- Space Complexity: O(1).

Approach 2: HashMap / Frequency Count
- Use a hash map (or unordered_map) to count occurrences of each number.
- Collect numbers that appear exactly twice.
- Time Complexity: O(n), Space Complexity: O(n).

Approach 3: Sign Marking (Optimal O(n), O(1) space)
- Since numbers are in [1, n], use the index as a marker.
- For each number `elem`, go to index `elem-1`:
    - If the value at that index is negative, `elem` is a duplicate.
    - Otherwise, multiply it by -1 to mark it visited.
- This works in-place without extra space.

Time Complexity: O(n)  
Space Complexity: O(1) (ignoring output vector).
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            int elem = abs(nums[i]);

            if(nums[elem - 1] < 0){
                ans.push_back(elem);
            }
            else{
                nums[elem - 1] *= -1;
            }
        }
        return ans;
    }
};
