/*
875. Koko Eating Bananas
Link: https://leetcode.com/problems/koko-eating-bananas/

Problem Summary:
Koko loves to eat bananas. There are `n` piles of bananas, and each pile has a certain number of bananas. 
Given `h` hours, find the minimum integer eating speed `k` such that Koko can eat all bananas within `h` hours.

Brute Force Intuition:
- Try all possible eating speeds from 1 to max(pile).
- For each speed, calculate total hours required to eat all bananas.
- The smallest speed that allows completion in ≤ h hours is the answer.
- Time complexity is very high (O(n * max(pile))).

Optimal Approach Intuition (Binary Search):
- Search space of speed = [1, max(pile)].
- For each mid speed, calculate total hours.
- If hours ≤ h → valid, try smaller speeds (move left).
- If hours > h → too slow, increase speed (move right).
- This ensures logarithmic reduction of search space.

Complexity:
- Brute Force: O(n * max(pile)) time, O(1) space.
- Optimal (Binary Search): O(n * log(max(pile))) time, O(1) space.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int findMaximum(vector<int> &piles){
        int maximum = -1;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > maximum){
                maximum = piles[i];
            }
        }
        return maximum;
    }

    bool canEatAll(vector<int> &piles, int h, int k){
        long long hours = 0;
        for(int i = 0; i < piles.size(); i++){
            hours += ceil((double)piles[i] / k);
        } 
        return (hours <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = findMaximum(piles);
        int k = right;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(canEatAll(piles, h, mid)){
                k = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return k;
    }
};
