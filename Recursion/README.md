# Recursion and Backtracking – Complete Patterns

Recursion and backtracking are powerful techniques used to systematically explore all possibilities in problems involving **permutations, combinations, subsets, partitions, and constraints**.  
The key idea is to build a solution step by step, and whenever the current path becomes invalid or complete, backtrack to explore alternatives.

---

## 1. Generating Subsets (Power Set)

Generate all possible subsets of a set of numbers (with or without duplicates).

### Idea and Approach
- At each step, you can either **include** or **exclude** the current element.

- Use recursion to explore both choices.

- For duplicates, sort the array first and skip identical elements when necessary.

### C++ Example
```cpp
void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
    res.push_back(path);
    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i-1]) continue; // skip duplicates
        path.push_back(nums[i]);
        backtrack(nums, i+1, path, res);
        path.pop_back(); // backtrack
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> path;
    backtrack(nums, 0, path, res);
    return res;
}
```

### Important Problems

- [78.Subsets](https://leetcode.com/problems/subsets/)

- [90.Subsets II](https://leetcode.com/problems/subsets-ii/)

---

## 2. 2. Generating Combinations

Generate all k-sized combinations out of n numbers.

### Idea and Approach

- Build the current combination step by step.

- Stop recursion when the combination reaches size k.

### C++ Example

```cpp
void backtrack(int n, int k, int start, vector<int>& path, vector<vector<int>>& res) {
    if (path.size() == k) {
        res.push_back(path);
        return;
    }
    for (int i = start; i <= n; i++) {
        path.push_back(i);
        backtrack(n, k, i+1, path, res);
        path.pop_back(); // backtrack
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> path;
    backtrack(n, k, 1, path, res);
    return res;
}
```

### Important Problems

- [77.Combinations](https://leetcode.com/problems/combinations/)

- [39.Combination Sum](https://leetcode.com/problems/combination-sum/)

- [40.Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)

---

## 3. Generating Permutations

Generate all permutations of numbers.

### Idea and Approach

- At each level, pick an unused number and recurse.

- Use a visited array or swap elements in-place.

### C++ Example

```cpp
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(0, nums, result);
    return result;
}

void backtrack(int index, vector<int> &nums, vector<vector<int>> &res){
    if(index == nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i = index; i < nums.size(); i++){
        swap(nums[i], nums[index]);
        backtrack(index + 1, nums, res);
        swap(nums[i], nums[index]);
    }
}
```

### Important Problems

- [46.Permutations](https://leetcode.com/problems/permutations/)

- [47.Permutations II](https://leetcode.com/problems/permutations-ii/)

---

## 4. Partitioning Problems

Partition an array or string into groups under constraints.

### Example: Palindrome Partitioning

- Explore partitions recursively.

- Check if substring is a palindrome before recursing further.

### C++ Example

```cpp
bool isPalindrome(string& s, int l, int r) {
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}

void backtrack(string& s, int start, vector<string>& path, vector<vector<string>>& res) {
    if (start == s.size()) {
        res.push_back(path);
        return;
    }
    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            path.push_back(s.substr(start, end-start+1));
            backtrack(s, end+1, path, res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    backtrack(s, 0, path, res);
    return res;
}
```

### Important Problems

- [131.Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)

- [93.Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/)

---

## 5. Constraint-Based Backtracking

Typical in puzzles or board problems.

### Examples

- N-Queens: place queens row by row, backtrack if conflict.

- Sudoku Solver: fill empty cells, backtrack if invalid.

### Important Problems

- [51.N-Queens](https://leetcode.com/problems/n-queens/)

- [52.N-Queens II](https://leetcode.com/problems/n-queens-ii/)

- [37.Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)

---

## Key Takeaways

- Subsets → Include/Exclude pattern.

- Combinations → Controlled recursion depth (k elements).

- Permutations → Use visited array or in-place swapping.

- Partitions → Recurse on prefixes, backtrack if invalid.

- Constraints (N-Queens, Sudoku) → Check validity before recursion.