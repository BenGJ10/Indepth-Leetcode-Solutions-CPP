/*
LeetCode: 128. Longest Consecutive Sequence
Link: https://leetcode.com/problems/longest-consecutive-sequence/

Problem:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

-------------------------------------------------------
Approach 1: Brute Force
- For each element, check if the next elements exist (i+1, i+2, …) using linear search.
- Time Complexity: O(n^2), too slow for large inputs.

Approach 2: Sorting + Linear Scan
- Sort the array first.
- Then, iterate through the sorted array and count consecutive elements.
- Time Complexity: O(n log n) due to sorting, followed by O(n) for the linear scan.

Approach 3: HashSet (Optimal O(n))
- Insert all elements into an unordered_set for O(1) lookup.
- For each element, check if it's the start of a sequence (i.e., elem-1 not in set).
- If yes, keep extending the sequence by checking elem+1, elem+2, … until the sequence ends.
- Track the maximum length.

Time Complexity: O(n)  
- Each element is processed at most twice (insert + extend sequence).  
Space Complexity: O(n) for the hash set.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int longestSeq = 0;

        for (int elem : st) {
            // only start counting if elem is the beginning of a sequence
            if (st.find(elem - 1) == st.end()) {
                int x = elem;
                int currSeq = 1;
                while (st.find(x + 1) != st.end()) {
                    currSeq++;
                    x++;
                }
                longestSeq = max(longestSeq, currSeq);
            }
        }
        return longestSeq;
    }
};
