# When to Think of String Patterns

## 1. Two-Pointer and Sliding Window  
### When to use:
- When dealing with contiguous substrings or sections of a string.
- When asked to find the longest/shortest substring meeting a condition.
- When the problem involves dynamically expanding or shrinking a window while processing.
- Frequently used when input size is large and O(n²) is too slow.

### Typical indicators:
- Words like "substring" (not subsequence).
- Conditions such as "longest/shortest substring," "at most k characters," or "window of length k."
- Problems that can be solved by tracking start and end pointers efficiently.

### Key problems:
- [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)  
- [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)  
- [443. String Compression](https://leetcode.com/problems/string-compression/)  
- [680. Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/)  
- [186. Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii/)  

---

## 2. Hashing, Frequency Maps, and Character Mapping  
### When to use:
- When you need to track character occurrences, compare patterns, or identify anagrams.
- When mapping relationships between characters or validating bijections.
- When dealing with problems involving counts of characters or transformations.

### Typical indicators:
- Questions mentioning "anagram," "pattern matching," or "frequency."
- The need to determine equivalence based on structure rather than exact content.
- Problems where each character must map uniquely to another.

### Key problems:
- [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/)  
- [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/)  
- [451. Sort Characters by Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)  
- [205. Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)  
- [890. Find and Replace Pattern](https://leetcode.com/problems/find-and-replace-pattern/)  
- [187. Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/)  

---

## 3. Prefix/Suffix and String Construction  
### When to use:
- When building strings iteratively or analyzing repeated patterns.
- When asked to compute prefixes or identify repetitions.
- Useful when strings must be transformed or constructed step-by-step.

### Typical indicators:
- Problems involving prefix comparisons or generating a derived string form.
- Questions involving repeated substrings or reconstruction logic.

### Key problems:
- [28. Implement strStr()](https://leetcode.com/problems/implement-strstr/)  
- [38. Count and Say](https://leetcode.com/problems/count-and-say/)  
- [6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)  
- [68. Text Justification](https://leetcode.com/problems/text-justification/)  
- [459. Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern/)  

---

## 4. Dynamic Programming on Strings  
### When to use:
- When the problem involves subsequences, edits, or transformations with optimal substructure.
- Palindromic subsequences or transformations requiring minimum operations.
- Counting distinct ways or alignments between two strings.

### Typical indicators:
- Problems asking "minimum operations," "subsequence count," or "longest subsequence."
- Questions with constraints suggesting overlapping subproblems and optimal substructure.

### Key problems:
- [516. Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)  
- [72. Edit Distance](https://leetcode.com/problems/edit-distance/)  
- [1312. Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)  
- [115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)  
- [392. Is Subsequence](https://leetcode.com/problems/is-subsequence/)  
- [97. Interleaving String](https://leetcode.com/problems/interleaving-string/)  

---

## 5. Advanced Search (KMP, Z-Algorithm, Rolling Hash)  
### When to use:
- When substring search must be optimized beyond brute force.
- When dealing with repeated patterns efficiently or very long strings.
- For competitive programming or advanced interview settings.

### Typical indicators:
- Problems like "implement strStr()" where naive O(n*m) is too slow.
- Constraints involving very long strings needing linear or near-linear solutions.

### Key problems:
- [28. Implement strStr() (KMP version)](https://leetcode.com/problems/implement-strstr/)  
- Rabin-Karp (rolling hash implementation)  
- Z-Algorithm (Z-function for substring matching)  
- [214. Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/)  

---

## 6. Mixed or Combined String Problems  
### When to use:
- Problems requiring multiple techniques (hashing + window, stack + parsing).
- Complex parsing tasks or problems blending string and other data structures.

### Typical indicators:
- Nested or hierarchical parsing (e.g., decoding strings).
- String problems with arithmetic, stacks, or combined logic.

### Key problems:
- [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)  
- [30. Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)  
- [227. Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/)  
- [394. Decode String](https://leetcode.com/problems/decode-string/)  
- [32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)  
