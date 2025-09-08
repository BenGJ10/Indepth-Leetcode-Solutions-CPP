/*
23. Merge k Sorted Lists
Link: https://leetcode.com/problems/merge-k-sorted-lists/

------------------------------------------------------
Brute Force Approach:
1. Traverse all lists and put all values into an array.
2. Sort the array.
3. Build a new linked list from sorted values.
- Time Complexity: O(N log N) where N = total number of nodes.
- Space Complexity: O(N)

------------------------------------------------------
Approach 2: Min-Heap (Priority Queue)
1. Push the head of each list into a min-heap.
2. Repeatedly pop the smallest node, add it to the result,  
   and push its next node into the heap if it exists.
- Time Complexity: O(N log k), where k = number of lists.
- Space Complexity: O(k)

------------------------------------------------------
Optimal Approach (Divide & Conquer – Similar to Merge Sort):
1. Recursively split the `lists` array into two halves.
2. Merge the two halves using a standard merge of two sorted lists.
3. Continue until all lists are merged into one.

- Time Complexity: O(N log k) → merging log k levels, each processing N nodes.
- Space Complexity: O(1) extra (excluding recursion stack).

------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeRange(lists, 0, lists.size() - 1);
    }

private:
    ListNode* mergeRange(vector<ListNode*>& lists, int start, int end) {
        if (start == end) return lists[start];
        if (start + 1 == end) return merge(lists[start], lists[end]);

        int mid = start + (end - start) / 2;
        ListNode* left = mergeRange(lists, start, mid);
        ListNode* right = mergeRange(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = list1 != nullptr ? list1 : list2;
        return dummy->next;
    }
};


