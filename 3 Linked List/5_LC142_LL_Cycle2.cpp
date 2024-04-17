// Brute sol = https://www.naukri.com/code360/problems/linked-list-cycle-ii_1112628?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

// Optimized sol = https://leetcode.com/problems/linked-list-cycle-ii/description/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Brute | TC = O(N) | SC = O(N)
ListNode *hasCycle(ListNode *head)
{
    //    Write your code here.
    unordered_set<ListNode*> st;

    ListNode* temp = head;

    while(temp != NULL){
        if(st.find(temp) == st.end()){
            st.insert(temp);
        }
        else{
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

//Optimized | TC = O(n) | SC = O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){
                break;
            }
        }

        if(fast == NULL || fast->next == NULL){
            return NULL;
        }

        fast = head;

        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};