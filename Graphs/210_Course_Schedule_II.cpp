/*
LeetCode: 210. Course Schedule II
Link: https://leetcode.com/problems/course-schedule-ii/

Problem:
Return a possible order of courses you should take to finish all. If not possible, return an empty array.

Approach (Kahn's Algorithm - BFS):
- Build adjacency list and in-degree array.
- Start from courses with 0 in-degree.
- Push courses in queue and process neighbors by reducing in-degree.
- If all nodes are added to the result, return it. Otherwise, return {} (cycle exists).

Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto &p: prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int elem = q.front();
            q.pop();
            ans.push_back(elem);

            for(auto neighbor: adj[elem]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        if (ans.size() == numCourses) return ans;
        return {};
    }
};