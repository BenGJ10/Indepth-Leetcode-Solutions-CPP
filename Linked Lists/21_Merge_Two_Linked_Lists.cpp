/*
LeetCode: 21. Merge Two Sorted Lists  
Link: https://leetcode.com/problems/merge-two-sorted-lists/

Problem:
Given two sorted linked lists, merge them into a single sorted linked list and return it.

Approach:
- Use a dummy node to simplify merging.
- Use two pointers and compare node values to build the result list.
- Attach remaining nodes after one list is exhausted.

Time Complexity: O(n + m)  
Space Complexity: O(1)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)    return list2;
        if(list2 == nullptr)    return list1;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if(list1 != nullptr){
            temp->next = list1;
        }
        if(list2 != nullptr){
            temp->next = list2;
        }
        return dummy->next;
    }
};