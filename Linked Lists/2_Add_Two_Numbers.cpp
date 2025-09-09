/*
2. Add Two Numbers
Link: https://leetcode.com/problems/add-two-numbers/

------------------------------------------------------
Problem Summary:
You are given two non-empty linked lists representing two non-negative integers.  
The digits are stored in reverse order, and each node contains a single digit.  
Add the two numbers and return the sum as a linked list.

------------------------------------------------------
Brute Force Approach:
1. Traverse both lists, store digits in arrays/vectors.
2. Convert vectors to integers, add them, then create a new list from the sum.
⚠️ But this fails for very large numbers (overflow).

- Time Complexity: O(max(m, n))  
- Space Complexity: O(m + n)  

------------------------------------------------------
Optimal Approach (Digit-by-Digit Addition):
1. Use a dummy node to build result list.  
2. Traverse both lists simultaneously:  
   - Add corresponding digits + carry.  
   - Store `(sum % 10)` in new node.  
   - Update carry as `(sum / 10)`.  
3. Continue until both lists and carry are processed.  
4. Return `dummy->next`.

- Time Complexity: O(max(m, n))  
- Space Complexity: O(1) (excluding output list).

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        // Process both lists until all digits and carry are done
        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // New digit node
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            // Update carry
            carry = sum / 10;
        }

        return dummy->next;
    }
};

