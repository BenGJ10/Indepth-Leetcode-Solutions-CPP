/*
86. Partition List
Link: https://leetcode.com/problems/partition-list/

------------------------------------------------------
Problem Summary:
Given the head of a linked list and an integer `x`,  
partition it so that all nodes with values < `x` come before nodes with values >= `x`.  
The relative order of nodes in each partition must be preserved.  

------------------------------------------------------
Brute Force Approach:
1. Traverse the linked list.  
2. Store nodes < x in one vector and nodes >= x in another.  
3. Rebuild the list by appending both vectors in order.  

- Time Complexity: O(n)  
- Space Complexity: O(n)  

------------------------------------------------------
Optimal Approach (Two Dummy Lists):
1. Create two dummy lists:  
   - `lesser` → holds nodes with values < x.  
   - `greater` → holds nodes with values >= x.  
2. Traverse original list:  
   - If node < x, append to `lesser`.  
   - Else, append to `greater`.  
3. Connect end of `lesser` list to start of `greater` list.  
4. Terminate `greater` list with `nullptr`.  
5. Return merged list starting from `lesserHead->next`.  

- Time Complexity: O(n)  
- Space Complexity: O(1) (reuses nodes in-place).  

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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        
        ListNode* lesserHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);

        ListNode* left = lesserHead;
        ListNode* right = greaterHead;
        
        while (head != nullptr) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            } else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        
        left->next = greaterHead->next;
        right->next = nullptr;
        
        return lesserHead->next;
    }
};
