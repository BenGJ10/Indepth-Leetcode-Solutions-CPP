/*
LeetCode: 207. Course Schedule
Link: https://leetcode.com/problems/course-schedule/

Problem:
Determine if it's possible to finish all courses given a list of prerequisite pairs.

Approach (BFS - Kahn's Algorithm):
- Build the graph and track the in-degree of each course.
- Start from all courses with 0 in-degree.
- Remove edges as you process nodes. If all courses are processed, return true.

Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int completedCourses = 0;

        while (!q.empty()) {
            int course = q.front(); q.pop();
            completedCourses++;

            for (auto neighbor : adj[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return completedCourses == numCourses;
    }
};

/*
Approach (DFS - Detect Cycles in Directed Graph):
- If a cycle is detected in the graph, it means some courses depend on each other circularly.
- Use a recursion stack (`currPath`) to detect cycles during DFS traversal.

Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> &currPath, vector<vector<int>> &adj) {
        vis[node] = 1;
        currPath[node] = 1;

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, vis, currPath, adj)) return true;
            } 
            else if (currPath[neighbor]) {
                return true; // cycle detected
            }
        }

        currPath[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
            adj[p[1]].push_back(p[0]);

        vector<int> vis(numCourses, 0);
        vector<int> currPath(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, currPath, adj)) return false;
            }
        }

        return true;
    }
};
