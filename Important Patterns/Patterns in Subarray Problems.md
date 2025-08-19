# Common Patterns in Subarray Problems

This guide summarizes key problem-solving techniques used in subarray-related questions. These approaches frequently appear in coding interviews and competitive programming.

---

## 1. Sliding Window (Fixed / Variable)

### When to Use
- Problem involves **subarrays** (continuous elements), not subsequences.
- You need to find or count subarrays satisfying conditions (sum, distinct elements, product, etc.).
- The condition can be maintained as the window **expands or shrinks**.

### Fixed Window
- Window size `k` is given.
- Move the window left to right while maintaining the sum/statistics.
- **Example**: [Maximum Sum Subarray of Size K](https://leetcode.com/problems/maximum-average-subarray-i/).

### Variable Window
- Expand the window until a condition is violated, then shrink from the left.
- Works when the condition has a **monotonic property**.
- **Examples**:
  - [Longest Subarray with Sum ≤ K](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/).
  - [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/).

### Pitfalls
- Sliding window works best when numbers are **non-negative** (sum grows predictably).
- With negative numbers, monotonicity breaks. Use **prefix sum + hashmap** instead.

---

## 2. Prefix Sum

### When to Use
- Problem asks for subarray sums, divisibility, or “how many subarrays sum to X”.
- Works for both positive and negative numbers.
- Enables `O(1)` subarray sum queries:  
  `sum(i, j) = prefix[j] - prefix[i-1]`.

### Typical Patterns
- **Subarray sum equals K**: Use hashmap to store prefix sums.  
  [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/).
- **Subarray sum divisible by K**: Store `(prefixSum % k)` in hashmap.  
  [Subarrays Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/).
- **Exactly K subarrays**:  
  `exactly(k) = atMost(k) - atMost(k-1)`.
  [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/).

### Pitfalls
- Always initialize hashmap with `{0: 1}` to handle subarrays starting at index `0`.
- Watch for **negative modulo** values. Normalize as:  
  `mod = ((prefixSum % k) + k) % k`.

---

## 3. Two Pointers

### When to Use
- Input is sorted (arrays or strings).
- Looking for pairs or triplets satisfying a condition (sum, difference, etc.).
- Efficient replacement for nested loops.

### Examples
- [Two Sum II – Input Array is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/).
- [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/).

---

## 4. AtMost vs Exactly vs LessThan

A powerful trick for counting subarrays.

### AtMost
- Count subarrays where condition ≤ `k`.
- Expand window, shrink only when condition > `k`.
- **Example**: Count subarrays with at most `k` odd numbers.

### Exactly
- Hard to compute directly. Use the transformation:
    `exactly(k) = atMost(k) - atMost(k-1)`
- Example: [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/).

### LessThan
- Equivalent to `atMost(k-1)`.
- Example: Count subarrays with `sum < k`

### Pitfalls
- With negative numbers, sliding window doesn’t work reliably.
- Switch to **prefix sum + hashmap**.

---

## Decision Guide

When solving a subarray problem, ask these questions in order:

1. **Subarray or subsequence?**  
 - Subarray → Sliding Window or Prefix Sum.  
 - Subsequence → Usually Dynamic Programming.

2. **Constraint on subarray size?**  
 - Fixed size → Sliding Window (Fixed).  
 - Variable, monotonic (non-negatives) → Sliding Window (Variable).  
 - Non-monotonic (negatives allowed) → Prefix Sum + Hashmap.

3. **Condition type?**  
 - `Sum ≤ K` → Sliding Window.  
 - `Sum == K` → Prefix Sum.  
 - `Count = K` (e.g., odds/distinct) → AtMost Trick.  
 - `Product < K` → Sliding Window.  
 - Pairs/Triplets in sorted input → Two Pointers.

---

## Rule of Thumb

- **Non-negatives + inequality** → Sliding Window.  
- **Negatives or exact sum/divisibility** → Prefix Sum + Hashmap.  
- **Exactly-K** → `AtMost(k) - AtMost(k-1)`.  
- **Sorted pairs/triplets** → Two Pointers.