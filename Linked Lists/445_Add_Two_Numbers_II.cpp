/*
445. Add Two Numbers II
Link: https://leetcode.com/problems/add-two-numbers-ii/

------------------------------------------------------
Problem Summary:
You are given two non-empty linked lists representing two non-negative integers.  
The most significant digit comes first and each of their nodes contains a single digit.  
Add the two numbers and return the sum as a linked list.

⚠️ Important difference from Problem 2:
- Digits are stored in *forward order*.
- You cannot modify input lists (i.e., cannot reverse them directly).

------------------------------------------------------
Brute Force Approach:
1. Reverse both lists.
2. Apply Problem 2 solution (digit-by-digit addition).
3. Reverse the result again.

- Time Complexity: O(m + n)  
- Space Complexity: O(1) (if we reverse in-place)

⚠️ But the problem statement *forbids modifying inputs* → can’t reverse directly.

------------------------------------------------------
Optimal Approach (Stacks):
1. Push all digits of l1 into stack s1.  
2. Push all digits of l2 into stack s2.  
3. While stacks are not empty or carry > 0:  
   - Pop values, add with carry.  
   - Create a new node for (sum % 10).  
   - Prepend it to the result list.  
   - Update carry = sum / 10.  
4. Return head of result list.  

- Time Complexity: O(m + n)  
- Space Complexity: O(m + n) (for stacks)

------------------------------------------------------
*/

#include <stack>
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
        stack<int> s1, s2;
        
        // Push all digits into stacks
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = nullptr;

        // Process stacks and carry
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;
            sum = sum % 10;

            // Prepend new node
            ListNode* newNode = new ListNode(sum);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};
