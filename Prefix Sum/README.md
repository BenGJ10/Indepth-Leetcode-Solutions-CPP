# Prefix Sum – Complete Patterns

The Prefix Sum technique is a powerful method for efficiently calculating the sum of elements in a range of an array. It involves preprocessing the array to create a prefix sum array, which allows for quick sum queries.
This technique is particularly useful when dealing with multiple queries on the same array, as it reduces the time complexity of range sum queries from O(n) to O(1) after an initial preprocessing step

The key idea:  
- Precompute an array `prefix[i]` that stores the sum (or other cumulative property) of elements from the start up to index `i`.
- Once built, you can answer many queries in **O(1)** time instead of recomputing sums in **O(n)**.

---

## Patterns in Prefix Sum

### 1. Range Sum Queries (Immutable Arrays)

Efficiently answer multiple queries asking for the sum of elements in a subarray.

#### Idea and Approach
- Precompute `prefix[i] = nums[0] + nums[1] + ... + nums[i]`.
- To get the sum from `L` to `R`:
  - `sum = prefix[R] - prefix[L-1]` (handle `L = 0` separately).
- Works best when the array does not change (immutable).

#### Algorithm
1. Precompute prefix sums in O(n).
2. For each query, subtract the prefix sums to get the range sum in O(1).

#### C++ Example
```cpp
class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            prefix[i+1] = prefix[i] + nums[i];
    }
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};
```

#### Important Problems

[303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)

[304. Range Sum Query 2D - Mutable](https://leetcode.com/problems/range-sum-query-2d-mutable/)

---

### 2. Subarray Sum Equals a Target (HashMap + Prefix Sum)

Find the number of continuous subarrays that sum to a given target.

#### Idea and Approach
- Use a running sum (currSum) and a hashmap storing counts of prefix sums.

- If currSum - K exists in the hashmap, it means there’s a subarray ending at the current index with sum K.

- Works even when the array has negative numbers (sliding window fails here).

#### Algorithm
1. Initialize map[0] = 1 to handle subarrays starting from index 0.

2. Iterate over array, adding to currSum.

3. If (currSum - K) is in map, add its count to the answer.

4. Increment map[currSum].

#### C++ Example
```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    mp[0] = 1;
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        if (mp.count(sum - k)) count += mp[sum - k];
        mp[sum]++;
    }
    return count;
}
```

#### Important Problems

[560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)

[523. Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/)

[930. Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/)

---

### 3. Longest Subarray with Balanced or Special Conditions

Convert problem into a prefix sum = target problem.

#### Idea and Approach
- Transform elements so that the condition becomes a sum problem.

  - Example: For equal number of 0s and 1s, convert 0 → -1 and find longest subarray with sum=0.

- Use a hashmap to store the first occurrence of each prefix sum.

- Maximize the distance between two indices with same prefix sum.

#### C++ Example
```cpp
int findMaxLength(vector<int>& nums) {
    unordered_map<int,int> firstIndex;
    firstIndex[0] = -1;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += (nums[i] == 1 ? 1 : -1);
        if (firstIndex.count(sum))
            maxLen = max(maxLen, i - firstIndex[sum]);
        else
            firstIndex[sum] = i;
    }
    return maxLen;
}
```

#### Important Problems

[525. Contiguous Array](https://leetcode.com/problems/contiguous-array/)

[1124. Longest Well-Performing Interval](https://leetcode.com/problems/longest-well-performing-interval/)

--- 

### 4. Modulo-Based Prefix Sum

Use prefix sums with modulo to find subarrays with specific properties, such as divisibility.

#### Idea and Approach
- (prefix[j] - prefix[i]) % k == 0 ⇒ prefix[j] % k == prefix[i] % k.

- Store first occurrence of each remainder in a hashmap.

#### C++ Example
```cpp
bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    mp[0] = -1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int rem = k ? sum % k : sum;
        if (mp.count(rem)) {
            if (i - mp[rem] > 1) return true;
        } else {
            mp[rem] = i;
        }
    }
    return false;
}
```

### Important Problems

[974. Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

[523. Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/)

---

### 5. 2D Prefix Sum

Calculate sums over submatrices efficiently using a 2D prefix sum array.

#### Idea and Approach
- prefix[i][j] stores the sum of elements in rectangle (0,0) to (i,j).

- For query (r1,c1) to (r2,c2), use inclusion-exclusion:

```
sum = pre[r2][c2]
      - pre[r1-1][c2]
      - pre[r2][c1-1]
      + pre[r1-1][c1-1]
```

#### C++ Example
```cpp
class NumMatrix {
    vector<vector<int>> pre;
public:
    NumMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        pre.assign(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
    }
    int sumRegion(int r1, int c1, int r2, int c2) {
        return pre[r2+1][c2+1] - pre[r1][c2+1] - pre[r2+1][c1] + pre[r1][c1];
    }
};
```

#### Important Problems

[304. Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/)

[1314. Matrix Block Sum](https://leetcode.com/problems/matrix-block-sum/)

--- 