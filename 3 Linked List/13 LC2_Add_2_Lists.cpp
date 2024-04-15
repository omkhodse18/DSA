#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// https://leetcode.com/problems/add-two-numbers/description/
// Similar to Q12, Only, dont reverse the list
class Solution {
public:
    void addNode(ListNode* &head, ListNode* &tail, int data){
        ListNode* newNode = new ListNode(data);

        if(head == NULL){
            head = newNode;
            tail = head;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }

    }

    ListNode* addLists(ListNode* l1, ListNode* l2){
        int val1 = 0, val2 = 0, carry = 0;

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* newListHead = NULL;
        ListNode* newListTail = newListHead;

        while(curr1!=NULL || curr2!=NULL || carry!=0){
            val1 = 0, val2 = 0;

            if(curr1 != NULL){
                val1 = curr1->val;
            }

            if(curr2 != NULL){
                val2 = curr2->val;
            }

            int sum = val1 + val2 + carry;

            int digit = sum % 10;
            carry = sum/10;

            addNode(newListHead, newListTail, digit);

            if(curr1 != NULL){
                curr1 = curr1->next;
            }

            if(curr2 != NULL){
                curr2 = curr2->next;
            }
        }
        
        return newListHead;

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* addedList = addLists(l1,l2);
        return addedList;
    }
};