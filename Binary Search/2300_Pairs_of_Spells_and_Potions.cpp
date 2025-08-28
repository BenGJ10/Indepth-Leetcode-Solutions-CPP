/*
2300. Successful Pairs of Spells and Potions
Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

Problem Summary:
Given two arrays `spells` and `potions` and an integer `success`,  
count for each spell how many potions can pair with it such that 
spell[i] * potion[j] >= success.

Brute Force Intuition:
- Check every pair (spell[i], potion[j]) and count if product >= success.
- Time complexity: O(n * m), can be very slow for large arrays.

Optimal Approach Intuition (Binary Search):
- Sort the potions array.
- For each spell, use binary search on potions to find the first potion 
  where spell * potion >= success.
- The number of valid pairs = total potions - index found.
- This reduces time complexity significantly.

Complexity:
- Brute Force: O(n * m) time, O(1) extra space.
- Optimal (Binary Search): O(n * log m) time, O(1) extra space (excluding output).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> pairs(n, 0);
        
        for(int i = 0; i < n; i++){
            int spell = spells[i];
            
            int left = 0, right = m - 1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                long long product = (long long)spell * (long long)potions[mid];
                if(product >= success){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            pairs[i] = m - left;
        }
        return pairs;
    }
};
