/*
328. Odd Even Linked List
Link: https://leetcode.com/problems/odd-even-linked-list/

------------------------------------------------------
Problem Summary:
Given the head of a singly linked list, group all nodes with odd indices together followed by nodes with even indices.  
⚠️ Index here refers to the **position** in the list, not the value.  
The relative order of odd and even groups must be preserved.

------------------------------------------------------
Brute Force Approach:
1. Traverse the list and separate values based on index (odd vs even).  
2. Store them in two vectors.  
3. Rebuild the linked list by appending odd-indexed nodes first, then even-indexed nodes.  

- Time Complexity: O(n)  
- Space Complexity: O(n)  

------------------------------------------------------
Optimal Approach (Two Pointers):
1. Use two pointers:  
   - `odd` → for odd index nodes.  
   - `even` → for even index nodes.  
   - Save `evenHead` to later connect at the end.  
2. Rearrange pointers:  
   - Link odd nodes together (`odd->next = even->next`).  
   - Link even nodes together (`even->next = odd->next`).  
3. Finally, connect the last odd node to `evenHead`.  

- Time Complexity: O(n)  
- Space Complexity: O(1) → done in-place.  

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};
