/*
Biweekly Contest 165: Minimum Discards to Balance Inventory

Problem Summary:
We receive a sequence of arriving items:
- `arrivals[i]` = type of the item arriving on day (i+1).
- We may keep or discard each item **only on the day it arrives**.

For every day `i`, look at the **w-day sliding window**  
[max(1, i - w + 1), i].  
Within **every such window**, each item type can appear **at most m times** among the kept items.

Goal: Discard the minimum number of arrivals so that the constraint holds.

------------------------------------------------------
Optimal Approach (Sliding Window + Hash Map):
1. Use a queue to represent kept items (day, type) within the last w days.
2. Maintain a frequency map `freq` of types currently in the window.
3. For each day i:
   • Remove from the queue any kept items whose day < i - w + 1,
     decrementing their frequency.
   • If the current item’s type count is already m,
     discard this arrival and increment `discards`.
   • Otherwise, keep it: increment its frequency and push (day, type).

- Time Complexity:  O(n)  
  Each arrival is pushed and popped at most once.
- Space Complexity: O(n)  
  For the queue and hash map (worst case all unique).

------------------------------------------------------
*/

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        unordered_map<int, int> freq;            // type -> count in current window
        queue<pair<int,int>> q;                  // (day, type) of kept items
        int discards = 0;

        for (int i = 0; i < n; i++) {
            int day = i + 1;

            // Remove kept items outside the w-day window
            while (!q.empty() && q.front().first < day - w + 1) {
                auto [oldDay, oldType] = q.front();
                q.pop();
                if (--freq[oldType] == 0) freq.erase(oldType);
            }

            int type = arrivals[i];
            if (freq[type] >= m) {
                // Keeping would exceed limit → discard
                discards++;
            } else {
                // Keep the item
                freq[type]++;
                q.push({day, type});
            }
        }
        return discards;
    }
};
