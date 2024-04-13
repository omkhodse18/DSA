#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

class mySolution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* curr = head;

        while(curr->next!=NULL){
            if(curr->next->val != curr->val){
                curr = curr->next;
            }
            else{
                ListNode* temp = curr->next->next;
                curr->next = temp;
            }
        }

        return head;
    }
};


//2nd one
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;

        while(temp != NULL && temp->next != NULL){
            if(temp->val == temp->next->val){
                ListNode* nextNode = temp->next;
                ListNode* afterNode = temp->next->next;
                temp->next = afterNode;
                delete nextNode;
            }
            else{
                temp = temp->next;
            }
        }

        return head;
    }
};