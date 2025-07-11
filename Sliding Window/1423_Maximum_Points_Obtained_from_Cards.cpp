/*
LeetCode: 1423. Maximum Points You Can Obtain from Cards  
Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

Problem:
You have an array of cardPoints and an integer k. 
You can take exactly k cards from the front or back of the array.
Return the maximum score you can obtain.

Approach:
- Initially, take the first k cards from the front and compute their sum (leftSum).
- Then slide a window: for each step, remove one card from the left and take one from the right.
- Keep track of the maximum score obtained in this process.

Time Complexity: O(k)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0, rightSum = 0, maxScore = 0;

        for(int i = 0; i < k; i++){
            leftSum += cardPoints[i];
        }

        maxScore = leftSum;
        int right = cardPoints.size() - 1;

        for(int j = k - 1; j >= 0; j--){
            leftSum -= cardPoints[j];
            rightSum += cardPoints[right--];
            maxScore = max(maxScore, leftSum + rightSum);
        }

        return maxScore;
    }
};
