// https://leetcode.com/problems/remove-nodes-from-linked-list/description/?envType=daily-question&envId=2024-05-06

/*
You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.

Example 1:
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

Example 2:
Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 
Constraints:
The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105
*/

#include<bits/stdc++.h>
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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        ListNode* curr = head;
        ListNode* prev = curr;

        int largest = curr->val;
        curr = curr->next;

        while(curr->next != NULL){
            if(curr->val >= largest){
                prev->next = curr;
                prev = prev->next;
                largest = curr->val;
            }

            curr = curr->next;
        }

        if(curr->val < largest){
            prev->next = NULL;
        }

        head = reverse(head);

        return head;
    }
};