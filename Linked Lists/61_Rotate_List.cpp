/*
61. Rotate List
Link: https://leetcode.com/problems/rotate-list/

------------------------------------------------------
Problem Summary:
Given the head of a linked list, rotate the list to the right by `k` places.  

Brute Force Approach:
1. For each rotation (repeat k times):  
   - Traverse to the last node.  
   - Detach it and move it to the front.  
2. Return the new head after k rotations.  

- Time Complexity: O(n * k)  
- Space Complexity: O(1)  

------------------------------------------------------
Optimal Approach (Length + Modulo):
1. Find the length of the list.  
2. Update `k = k % length` (rotation repeats every `length` steps).  
   - If `k == 0`, return original head.  
3. Connect the tail to the head (make it circular).  
4. Find the `(length - k)`-th node → this becomes the new tail.  
5. The next node (`newTail->next`) becomes the new head.  
6. Break the circular link by setting `newTail->next = nullptr`.  

- Time Complexity: O(n) (single pass to get length + another to find new head).  
- Space Complexity: O(1).  

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
    ListNode* findKthNode(ListNode* head, int k) {
        int count = 1;
        ListNode* temp = head;
        while (count < k) {
            temp = temp->next;
            count++;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;

        // Step 1: Find length and tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // Step 2: Adjust k
        k = k % length;
        if (k == 0) return head;

        // Step 3: Make list circular
        tail->next = head;

        // Step 4: Find new tail at (length - k)
        ListNode* newTail = findKthNode(head, length - k);

        // Step 5: Break the cycle and set new head
        head = newTail->next;
        newTail->next = nullptr;

        return head;
    }
};
