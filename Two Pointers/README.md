# Two Pointers – Complete Patterns

The Two Pointers technique is a powerful method for solving problems involving arrays or linked lists. It involves using two pointers to traverse the data structure, often leading to efficient solutions with linear time complexity.
It is particularly useful for problems that require finding pairs, subarrays, or specific conditions within a sequence.

- **Idea**: Use two indices (or iterators) moving through the data structure at varying rates or directions to achieve O(n) complexity instead of O(n²).

- **Common Uses**:

    - Searching pairs/triplets

    - Reversing arrays/strings

    - Partitioning elements

    - Detecting cycles in linked lists

    - Merging sorted lists

---

## Patterns in Stacks & Queues

### 1. Opposite Ends (Converging Pointers)

This pattern involves two pointers starting from opposite ends of a data structure and moving towards each other. It is useful for problems that require comparing or processing elements from both ends.
Used when the problem involves sorted arrays or requires checking combinations from both ends.

#### Idea and Approach
- Start one pointer at the beginning and another at the end.

- Move pointers inward based on the condition.

- Works best with sorted input.

#### Algorithm
1. Initialize left = 0, right = n - 1.

2. While left < right:

3. Check if the current pair meets the condition.

4. Adjust pointers accordingly.

5. Return result.

#### C++ Example: Two Sum II (Sorted Array)
```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
        int sum = numbers[l] + numbers[r];
        if (sum == target) return {l + 1, r + 1};
        else if (sum < target) l++;
        else r--;
    }
    return {};
}
```

#### Important Problems

[167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

[11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/)

[42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

[125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)

--- 

### 2. Fast & Slow Pointers (Cycle Detection)

This pattern uses two pointers moving at different speeds to solve problems related to cycles or linked lists. It is particularly useful for detecting cycles in linked lists or finding the middle element. Also known as the `Tortoise and Hare` algorithm.

#### Idea and Approach
- Move slow pointer one step at a time.

- Move fast pointer two steps at a time.

- If they meet, a cycle exists; if fast reaches the end, no cycle.

#### Algorithm
1. Initialize slow and fast to head.

2. While fast and fast->next are not null:

3. Move slow by 1 step.

4. Move fast by 2 steps.

4. If slow == fast, cycle found.

5. Return result.

#### C++ Example: Linked List Cycle
```cpp
bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

#### Important Problems

[141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

[142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

[287. Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)

[876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)

--- 

### 3. Same Direction (Sliding Window Variant)

This pattern involves two pointers moving in the same direction, often used to maintain a window of elements that satisfy a certain condition. It is particularly useful for problems involving subarrays or substrings.

#### Idea and Approach
- Expand right pointer to include elements.

- Move left pointer to shrink window when condition fails.

- Used for subarray/substring problems.

#### Algorithm
1. Initialize left = 0.

2. Expand right in a loop.

3. If condition breaks, increment left until valid again.

4. Track max/min result.

#### C++ Example: Longest Substring Without Repeating Characters
```cpp
int lengthOfLongestSubstring(string s) {
    vector<int> freq(256, 0);
    int left = 0, res = 0;
    for (int right = 0; right < s.size(); right++) {
        freq[s[right]]++;
        while (freq[s[right]] > 1) {
            freq[s[left]]--;
            left++;
        }
        res = max(res, right - left + 1);
    }
    return res;
}
```

#### Important Problems

[3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

[424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)

[76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)

---
 
### 4. Partitioning Array

This pattern involves partitioning an array into two parts based on a condition, often used in problems that require rearranging elements or finding specific partitions. Partition elements based on a pivot or condition in-place using two pointers.

#### Idea and Approach
- One pointer scans from start, another from end.

- Swap elements when they are on the wrong side.

- Common in quicksort partitioning, Dutch National Flag problem.

#### Algorithm
1. Initialize i = 0, j = n - 1.

2. While i < j:

3. Move i forward until condition fails.

4. Move j backward until condition fails.

5. Swap and move both.

#### C++ Example: Dutch National Flag Problem
```cpp
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1) mid++;
        else swap(nums[mid], nums[high--]);
    }
}
``` 

#### Important Problems

[75. Sort Colors](https://leetcode.com/problems/sort-colors/)

[283. Move Zeroes](https://leetcode.com/problems/move-zeroes/)

[905. Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/)

--- 