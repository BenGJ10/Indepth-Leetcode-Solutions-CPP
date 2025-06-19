/*
Approach: BFS
We use a queue to explore all pixels of the same color from the starting pixel and change them to the new color.

Time Complexity: O(n * m) – each pixel is visited once
Space Complexity: O(n * m) – worst-case queue size
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size(), cols = image[0].size();
        int initialColor = image[sr][sc];
        if (initialColor == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dirRow[] = {-1, 0, 1, 0};
        int dirCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = r + dirRow[i];
                int newCol = c + dirCol[i];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                    image[newRow][newCol] == initialColor) {
                    image[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }

        return image;
    }
};

/*
Approach: DFS
We recursively visit all 4-connected neighbors and change their color if they match the starting pixel.

Time Complexity: O(n * m)
Space Complexity: O(n * m) recursion stack (worst-case)
*/

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int initial, int color) {
        int n = image.size(), m = image[0].size();
        if (sr < 0 || sr >= n || sc < 0 || sc >= m || image[sr][sc] != initial || image[sr][sc] == color)
            return;

        image[sr][sc] = color;

        dfs(image, sr + 1, sc, initial, color);
        dfs(image, sr - 1, sc, initial, color);
        dfs(image, sr, sc + 1, initial, color);
        dfs(image, sr, sc - 1, initial, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        if (initial != color)
            dfs(image, sr, sc, initial, color);
        return image;
    }
};
