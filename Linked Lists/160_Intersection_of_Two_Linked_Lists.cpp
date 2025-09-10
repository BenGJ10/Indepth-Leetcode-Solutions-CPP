/*
160. Intersection of Two Linked Lists
Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

------------------------------------------------------
Problem Summary:
Given the heads of two singly linked lists `headA` and `headB`, return the node at which they intersect.  
If the two linked lists have no intersection, return `nullptr`.

⚠️ Intersection is based on **reference**, not value.  
That means two nodes are the same if they point to the same memory address.

------------------------------------------------------
Brute Force Approach:
1. For each node in listA, traverse listB fully to check if they intersect.  
2. If yes, return intersection node.  
3. Else, return null.  

- Time Complexity: O(m * n)  
- Space Complexity: O(1)  

------------------------------------------------------
Optimal Approach (Two Pointers):
1. Use two pointers `pA` and `pB` starting at `headA` and `headB`.  
2. Traverse both lists:  
   - When `pA` reaches the end, move it to `headB`.  
   - When `pB` reaches the end, move it to `headA`.  
3. They will either meet at the intersection node or both reach `nullptr`.  

Reasoning: Both traverse exactly `lenA + lenB` steps.  
If there’s an intersection, they meet there; else both end at null.

- Time Complexity: O(m + n)  
- Space Complexity: O(1)  

------------------------------------------------------
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;

        while(pA != pB){
            pA = pA->next;
            pB = pB->next;

            if(pA == pB)    return pA;

            if(pA == nullptr)   pA = headB;
            if(pB == nullptr)   pB = headA;
        }
        return pA;
    }
};

