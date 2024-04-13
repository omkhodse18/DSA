// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* prev = dummy;

        while(curr!=NULL && curr->next!=NULL){
            if((curr->next!=NULL) && (curr->val == curr->next->val) ){
                while( (curr->next!=NULL) && (curr->val == curr->next->val) ){
                    curr = curr->next;
                }
                prev->next = curr->next;
                // curr = curr->next;
            }
            else{
                prev = curr;
                // curr = curr->next;
            }
            
            curr = curr->next;
        
        }

        head = dummy->next;
        return head;
    }
};