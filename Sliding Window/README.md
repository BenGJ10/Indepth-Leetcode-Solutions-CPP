# When to Think of Sliding Window

### 1. Contiguous Subarrays/Substrings

If the problem says:

- “subarray” (not subsequence),

- “substring” (not subsequence),

- dealing with windowed conditions like sum, length, count...

Think sliding window.

### 2. You Need to Find a Window That Satisfies a Condition

For example:

- Smallest or longest subarray where sum ≥ target

- Longest substring with at most k distinct characters

- Maximum sum of subarray of size k

- Count of subarrays with a fixed sum

### 3. All Elements Are Positive (or Have Special Structure)
Many sliding window problems (like minSubArrayLen) assume:

- No negatives → sum can only increase → easy to shrink window

- This helps with shrinking logic (while (sum >= target))