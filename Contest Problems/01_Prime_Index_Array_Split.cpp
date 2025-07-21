/*
Biweekly Contest 162: Prime Index Array Split

Problem:  
Given an array `nums`, split elements at **prime indices** and **non-prime indices**.  
Return the absolute difference between the sum of elements at prime indices (`sumA`) and those at non-prime indices (`sumB`).

Approach: Sieve of Eratosthenes + Index-based Partitioning
- Use Sieve of Eratosthenes to mark prime indices in the array.
- Iterate through array, compute sum of elements at prime indices and non-prime indices.
- Return |sumA - sumB|.

Time Complexity: O(n log log n) (Sieve) + O(n)  
Space Complexity: O(n)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> isPrime(size, 1);
        if(size > 0) isPrime[0] = 0;
        if(size > 1) isPrime[1] = 0;

        for(int i = 2; i * i < size; i++){
            if(isPrime[i] == 1){
                for(int j = i * i; j < size; j += i){
                    isPrime[j] = 0;
                }
            }
        }

        long long sumA = 0, sumB = 0;
        for(int i = 0; i < size; i++){
            if(isPrime[i] == 1){
                sumA += nums[i];
            }
            else{
                sumB += nums[i];
            }
        }

        return abs(sumA - sumB);
    }
};
