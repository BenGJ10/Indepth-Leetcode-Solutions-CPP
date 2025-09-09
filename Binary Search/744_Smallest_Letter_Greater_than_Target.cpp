/*
744. Find Smallest Letter Greater Than Target
Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

------------------------------------------------------
Problem Summary:
Given a sorted array of letters containing only lowercase English letters,  
and a target letter, return the smallest letter in the array that is strictly greater than the target.  

The array is circular, meaning if the target is greater than or equal to the last letter,  
the answer is the first letter in the array.

Brute Force Approach:
1. Traverse through the array from start.
2. Return the first letter strictly greater than target.
3. If no such letter exists, return the first element (wrap around).
- Time Complexity: O(n)
- Space Complexity: O(1)

------------------------------------------------------
Optimal Approach (Binary Search):
1. Perform binary search over the array.
2. If `letters[mid] > target`, store it as a potential answer and search left.
3. Otherwise, search right.
4. If no greater element found (wrap case), return `letters[0]`.

- Time Complexity: O(log n)
- Space Complexity: O(1)

------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];  // default to first element (wrap-around case)
        int start = 0, end = letters.size() - 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (letters[mid] > target) {
                ans = letters[mid];
                end = mid - 1;
            } 
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

