/*
138. Copy List with Random Pointer
Link: https://leetcode.com/problems/copy-list-with-random-pointer/

------------------------------------------------------
Problem Summary:
You are given a linked list where each node has two pointers:  
1. `next` → the next node in the list  
2. `random` → a random node in the list (or null).  

Your task is to return a deep copy of this list.  
Each node in the new list should have the same value and random pointer structure as the original.

------------------------------------------------------
Brute Force Approach:
1. Use a hashmap to store mapping: `oldNode → newNode`.  
2. First pass: copy nodes and `next` pointers.  
3. Second pass: assign `random` pointers using the map.  

- Time Complexity: O(n)  
- Space Complexity: O(n) (hashmap for mapping).  

------------------------------------------------------
Optimal Approach (Interweaving Technique):
1. Insert copied nodes next to their originals.  
   Example: `A → B → C` becomes `A → A' → B → B' → C → C'`.  
2. Set `random` pointers of copied nodes: `A'.random = A.random->next`.  
3. Separate original and copied lists.  

- Time Complexity: O(n)  
- Space Complexity: O(1).  

------------------------------------------------------
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Create hashmap for old → new mapping
        unordered_map<Node*, Node*> mpp;
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        mpp[head] = newHead;

        // Step 2: Copy nodes and next pointers
        while (oldTemp != nullptr) {
            Node* newNode = new Node(oldTemp->val);
            mpp[oldTemp] = newNode;
            newTemp->next = newNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Step 3: Copy random pointers
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != nullptr) {
            newTemp->random = mpp[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
