# Binary Search – Complete Patterns

Binary Search is a powerful algorithm for efficiently searching in **sorted arrays** or **monotonic conditions**. The main idea is to reduce the search space by half at every step. Binary Search is widely used not just for searching, but also in optimization problems where the solution space is monotonic.

The key idea:  
- Maintain a `low` and `high` pointer to define the search space.  
- Repeatedly check the middle element (`mid`) and move pointers based on the condition.  
- Works on sorted arrays or any problem that can be converted into a **monotonic check**.  

---

## Patterns in Binary Search

### 1. Classic Binary Search (Exact Element Search)

Find the index of a target element in a sorted array.

#### Idea and Approach
- Compare the middle element with the target.  

- Move `low` or `high` to shrink the search space.  

- Return the index if found, else return -1.  

#### Algorithm
1. Initialize `low = 0` and `high = n-1`.  
2. While `low <= high`:  
   - Compute `mid = low + (high-low)/2`.  
   - If `nums[mid] == target`, return `mid`.  
   - If `nums[mid] < target`, move `low = mid+1`.  
   - Else, move `high = mid-1`.  
3. Return -1 if not found.  

#### C++ Example
```cpp
int binarySearch(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

#### Important Problems

- [704. Binary Search](https://leetcode.com/problems/binary-search/)

- [35. Search Insert Position](https://leetcode.com/problems/search-insert-position/)

---

### 2. Lower Bound / Upper Bound (First / Last Occurrence)

Find the first or last occurrence of a target in a sorted array (useful for duplicates).

#### Idea and Approach

- Lower Bound → First index i where nums[i] >= target.

- Upper Bound → First index i where nums[i] > target.

- Can be implemented with modified binary search.

#### C++ Example
```cpp
int lowerBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target) low = mid + 1;
        else high = mid;
    }
    return low;
}

int upperBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target) low = mid + 1;
        else high = mid;
    }
    return low;
}
```

#### Important Problems

- [34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

- [69. Sqrt(x)](https://leetcode.com/problems/sqrtx/)

- [278. First Bad Version](https://leetcode.com/problems/first-bad-version/)

---

### 3. Binary Search on Answer (Search in Monotonic Space)

Use binary search to find the minimum or maximum value satisfying a condition.

#### Idea and Approach

- Convert problem to YES/NO check.

- Define search space over possible answers.

- Binary search on the answer until the optimal value is found.

#### Example

- Problem: Minimum largest sum to split an array into m subarrays.

- Check if a candidate mid sum is feasible.

#### C++ Example
```cpp
bool canSplit(vector<int>& nums, int m, int maxSum) {
    int count = 1, curr = 0;
    for (int num : nums) {
        if (curr + num > maxSum) {
            curr = num;
            count++;
        } else curr += num;
    }
    return count <= m;
}

int splitArray(vector<int>& nums, int m) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canSplit(nums, m, mid)) high = mid;
        else low = mid + 1;
    }
    return low;
}
```

#### Important Problems

[410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)

[875. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

[1011. Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

---

### 4. Search in Rotated Sorted Array

Find an element in a rotated sorted array (array rotated at some pivot).

#### Idea and Approach

- Compare nums[mid] with nums[low] to determine which half is sorted.

- Narrow down search based on sorted half and target.

#### C++ Example
```cpp
int searchRotated(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) high = mid - 1;
            else low = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}
```

#### Important Problems

- [33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

- [81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

- [153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

- [154. Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)

---

### 5. Search for Peak / Maximum Element (Bitonic Array)

Find peak element in mountain array or array with increasing then decreasing elements.

#### Idea and Approach

- Use binary search comparing mid with mid+1.

- If nums[mid] < nums[mid+1], peak lies right; else, left.

#### C++ Example

```cpp
int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[mid+1]) low = mid + 1;
        else high = mid;
    }
    return low;
}
```

#### Important Problems

- [162. Find Peak Element](https://leetcode.com/problems/find-peak-element/)

- [852. Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

---

### More Important Binary Search Problems

Here’s a list of additional must-practice problems that apply Binary Search patterns in different ways:


- [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)  
- [34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)  
- [300. Longest Increasing Subsequence (Binary Search + DP)](https://leetcode.com/problems/longest-increasing-subsequence/)  
- [540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)  
- [658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/)  
- [744. Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)  
- [852. Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)  
- [1011. Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)  
- [1060. Missing Element in Sorted Array](https://leetcode.com/problems/missing-element-in-sorted-array/)  
- [1095. Find in Mountain Array](https://leetcode.com/problems/find-in-mountain-array/)  
- [2089. Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/)  

---
