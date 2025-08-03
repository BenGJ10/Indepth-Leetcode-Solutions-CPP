# When to Think of Prefix Sum

## 1. Range Sum Queries
### When to use:
- When the problem involves multiple queries asking for the sum of subarrays.
- When recomputing sums each time would be inefficient.
- Typically when the array is immutable (no updates).

### Typical indicators:
- "Sum of elements between L and R."
- Multiple queries on the same array.
- Preprocessing allowed to answer queries faster.

### Key problems:
- [303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)  
- [304. Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/)  

---

## 2. Subarray Sum Equals a Target (HashMap + Prefix Sum)
### When to use:
- When you need to count or find subarrays whose sum equals K.
- When array elements can be positive, negative, or zero.
- When sliding window (positive-only) won't work.

### Typical indicators:
- "Count subarrays with sum K."
- "Check if a subarray with sum K exists."
- The presence of negative numbers invalidating sliding window.

### Key problems:
- [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)  
- [930. Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/)  

---

## 3. Longest Subarray Problems (Transformations + Prefix)
### When to use:
- When asked for the longest subarray satisfying a balance condition.
- Often involves converting elements (e.g., `0 → -1`) to reduce to "sum=0".

### Typical indicators:
- "Equal number of 0s and 1s."
- "Longest well-performing interval."
- "Subarray with balanced conditions."

### Key problems:
- [525. Contiguous Array](https://leetcode.com/problems/contiguous-array/)  
- [1124. Longest Well-Performing Interval](https://leetcode.com/problems/longest-well-performing-interval/)  

---

## 4. Modulo-Based Prefix Sum (Divisibility and Remainder)
### When to use:
- When subarray sums must satisfy modulo or divisibility conditions.
- Uses the property:  
  `(prefix[j] - prefix[i]) % k == 0 ⇔ prefix[j] % k == prefix[i] % k`.

### Typical indicators:
- "Sum divisible by K."
- Questions with modulo arithmetic or remainders.

### Key problems:
- [974. Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/)  
- [523. Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/)  

---

## 5. Difference Array (Reverse Prefix Sum)
### When to use:
- When applying multiple range updates efficiently.
- Update ranges first (difference array), then compute prefix sum for final result.

### Typical indicators:
- "Apply updates to a range [L, R]."
- "Flight booking, rainfall, or interval updates."

### Key problems:
- [1109. Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/)  
- [370. Range Addition](https://leetcode.com/problems/range-addition/)  

---

## 6. 2D Prefix Sum
### When to use:
- For sum queries on submatrices in a grid.
- Extends prefix sum to two dimensions.

### Typical indicators:
- "Sum of elements in a submatrix."
- Multiple sum queries on a static grid.

### Key problems:
- [304. Range Sum Query 2D](https://leetcode.com/problems/range-sum-query-2d-immutable/)  
- [1314. Matrix Block Sum](https://leetcode.com/problems/matrix-block-sum/)  

---

## 7. Variants (XOR, Bitmask, Weighted Prefix)
### When to use:
- XOR version: when dealing with bitwise XOR queries.
- Bitmask prefix: parity checks for digits or characters.

### Key problems:
- [1310. XOR Queries of a Subarray](https://leetcode.com/problems/xor-queries-of-a-subarray/)  
- [1371. Longest Substring Containing Vowels in Even Counts](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)  
- [1542. Longest Awesome Substring](https://leetcode.com/problems/longest-awesome-substring/)  

---

## Key Patterns and Tips
- Equality conditions (sum=K): Prefix sum + hashmap.
- Divisibility/modulo: Track prefix sum remainders.
- Balanced subarrays: Transform values (e.g., `0 → -1`) then sum=0.
- Inequality (<, >): Prefer sliding window.
- Multiple range updates: Difference array + prefix reconstruction.
