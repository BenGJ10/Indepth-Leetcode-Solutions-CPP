/*
1482. Minimum Number of Days to Make m Bouquets
Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

Problem Summary:
We are given an array bloomDay[] where bloomDay[i] is the day the i-th flower blooms.
We need to make `m` bouquets, each requiring `k` adjacent flowers.
Find the minimum day when it is possible to make all bouquets, or return -1 if impossible.

Brute Force Intuition:
- Try every possible day from min(bloomDay) to max(bloomDay).
- For each day, simulate and check if m bouquets can be made.
- Stop when the first valid day is found.
- Very slow because the day range can be huge.

Optimal Approach Intuition (Binary Search):
- Search space = [min(bloomDay), max(bloomDay)].
- For each mid day, check if it's possible to make m bouquets.
- If possible, move left (try smaller days).
- If not possible, move right (need more days).
- Binary search efficiently finds the minimum valid day.

Complexity:
- Brute Force: O(n * (max - min)) time, O(1) space.
- Optimal (Binary Search): O(n * log(max - min)) time, O(1) space.
*/

#include <iostream>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int> &bloomDay, int day, int m, int k){
        int count = 0, bouquets = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
            }
            else{
                bouquets += count / k;
                count = 0;
            }
        }
        bouquets += count / k;
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long)m * k > bloomDay.size())   return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isPossible(bloomDay, mid, m, k)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
