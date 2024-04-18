#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// APPROACH | TC = O(2N) | SC = O(1)

class Solution {
public:
    int length(ListNode* head){
        int len = 0;
        ListNode* curr = head;
        
        while(curr!=NULL){
            len++;
            curr = curr->next;
        }

        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        int diff = len - n;
        
        if(head->next==NULL && n == 1){
            return NULL;
        }

        if(diff == 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* prev = NULL;
        ListNode* temp = head;

        while(diff--){
            prev = temp;
            cout<<temp->val<<" ";
            temp = temp->next;
        }

        ListNode* dummy = temp;
        prev->next = temp->next;
        delete dummy;
       
        return head;
    }
};