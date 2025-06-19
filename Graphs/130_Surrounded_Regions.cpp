/*
LeetCode: 130. Surrounded Regions
Link: https://leetcode.com/problems/surrounded-regions/

Problem:
Capture all regions that are completely surrounded by 'X'.
Any 'O' connected to the border (directly or indirectly) should *not* be flipped.

Approach: DFS from border 'O's
1. Traverse all border cells (first/last row and column).
2. For every 'O' on the border, run DFS and mark connected 'O's as '#' temporarily.
3. After traversal:
   - Convert all remaining 'O's to 'X' (they are truly surrounded).
   - Convert '#' back to 'O' (they were border-connected).

Time Complexity: O(n * m)
Space Complexity: O(n * m) in worst case for recursion stack
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<char>>& board, int i, int j) {
        int n = board.size(), m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') return;

        board[i][j] = '#'; // Temporarily marking as visited
        DFS(board, i + 1, j);
        DFS(board, i - 1, j);
        DFS(board, i, j + 1);
        DFS(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // Traversing first and last column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') DFS(board, i, 0);
            if (board[i][m - 1] == 'O') DFS(board, i, m - 1);
        }

        // Traversing first and last row
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') DFS(board, 0, j);
            if (board[n - 1][j] == 'O') DFS(board, n - 1, j);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') 
                    board[i][j] = 'X';
                
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};