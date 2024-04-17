// https://leetcode.com/problems/reverse-nodes-in-k-group/description/


#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// code
class Solution {
public:
    int length(ListNode* head){
        int len = 0;
        ListNode* temp = head;

        while(temp != NULL){
            len++;
            temp = temp->next;
        }

        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }

        int len = length(head);

        if(len < k){
            return head;
        }

        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        int count = 0;

        while(curr!=NULL && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next != NULL){
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};