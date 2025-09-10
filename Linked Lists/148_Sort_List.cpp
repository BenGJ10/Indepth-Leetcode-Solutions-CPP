/*
148. Sort List
Link: https://leetcode.com/problems/sort-list/

------------------------------------------------------
Problem Summary:
Given the head of a linked list, return the list after sorting it in ascending order.  

------------------------------------------------------
Brute Force Approach:
1. Traverse the linked list and store all values in an array/vector.  
2. Sort the array using `sort()`.  
3. Rebuild the linked list from the sorted values.  

- Time Complexity: O(n log n) (due to array sort).  
- Space Complexity: O(n) (for storing values).  

------------------------------------------------------
Optimal Approach (Merge Sort on Linked List):
1. Use **fast & slow pointers** to find the middle of the linked list.  
   - `slow` moves 1 step, `fast` moves 2 steps.  
   - When `fast` reaches end, `slow` will be at middle.  
2. Split the list into two halves.  
3. Recursively sort each half.  
4. Merge the two sorted halves using a helper function (`mergeLL`).  
   - Always pick the smaller node and attach to the result list.  

- Time Complexity: O(n log n) (log n splits, O(n) merging).  
- Space Complexity: O(log n) (recursion stack only, in-place otherwise).  

------------------------------------------------------
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Find middle of the linked list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted linked lists
    ListNode* mergeLL(ListNode* left, ListNode* right) {
        if (!left) return right;
        if (!right) return left;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (left && right) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if (left) temp->next = left;
        if (right) temp->next = right;

        return dummy->next;
    }

    // Main function to sort list
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* mid = findMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // Split the list

        left = sortList(left);
        right = sortList(right);

        return mergeLL(left, right);
    }
};
