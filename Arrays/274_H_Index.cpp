/*
LeetCode: 274. H-Index
Link: https://leetcode.com/problems/h-index/

Problem:
Given an array of citations where citations[i] is the number of citations a researcher received for their ith paper,
return the researcher's h-index.

Approach:
- Sort the citations array in ascending order.
- Use binary search to find the maximum `h` such that the researcher has at least `h` papers with `h` or more citations.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int hIndex(vector<int> &citations){
        sort(citations.begin(), citations.end());
        int size = citations.size();
        int ans = 0;
        int start = 0, end = size - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(citations[mid] <= size - mid){
                ans = max(ans, size - mid);
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};