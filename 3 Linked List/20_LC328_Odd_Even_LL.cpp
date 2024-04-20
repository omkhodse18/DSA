/********
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

https://leetcode.com/problems/odd-even-linked-list/
Time complexity: O(n)
Space complexity: O(1
********/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* evenHead = new ListNode(-1);
        ListNode* evenTail = evenHead;
        ListNode* oddHead = new ListNode(-1);
        ListNode* oddTail = oddHead;
        ListNode* temp = head;
        int count = 0;

        while(temp!=NULL){
            if(count % 2 == 0 || count==0){
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
            else{
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
            count++;
            temp = temp->next;
        }

        evenTail->next = oddHead->next;
        oddTail->next = NULL;
        ListNode* newHead = evenHead->next;

        delete evenHead;
        delete oddHead;

        return newHead;
    }
};