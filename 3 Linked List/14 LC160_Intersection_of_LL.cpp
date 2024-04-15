#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// https://leetcode.com/problems/intersection-of-two-linked-lists/

// SOl 1 (Optimized) |  TC = O(2*max(length of list1,length of list2)) | SC = O(1) 
class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){
            return NULL;
        }

        ListNode* curr1 = headA;
        ListNode* curr2 = headB;

        while(curr1 != curr2){
            // curr1 = curr1->next;
            // curr2 = curr2->next;

            // if(curr1==curr2){
            //     return curr1;
            // }

            // if(curr1==NULL){
            //     curr1 = headB;
            // }

            // if(curr2 == NULL){
            //     curr2 = headA;
            // }
            curr1 = (curr1) ? curr1->next : headA;
            curr2 = (curr2) ? curr2->next : headB;
        }

        return curr1;
    }
};

//APPROACH 2 | TC = O(max(N,M)) | SC = O(1)

int length(ListNode* curr){
    int len = 0;

    while(curr!=NULL){
        len++;
        curr = curr->next;
    }

    return len;
}

ListNode* findIntersection(ListNode *firstHead, ListNode *secondHead)
{
    //Write your code here
    int len1 = length(firstHead);           // O(N)
    int len2 = length(secondHead);          // O(M)
    int diff = abs(len1-len2);             

    ListNode* curr1 = firstHead;
    ListNode* curr2 = secondHead;

     // O(N-M)
    if(len1 > len2){
        for(int i=0;i<diff;i++){
            curr1 = curr1->next;
        }
    }
    else{
        for(int i=0;i<diff;i++){
            curr2 = curr2->next;
        }
    }
    
    // O(N)
    while(curr1 != curr2){
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return curr1;
}
