#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach 1 | TC = O(N) | SC = O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;

        ListNode * fast = head;
        ListNode * slow = head;

        while(fast != NULL){
            values.push_back(slow->val);
            
            if(fast->next == NULL){
                break;
            }
            fast = fast->next->next;

            slow = slow->next;
            
        }

        while (slow != NULL) {
            if(slow->val != values[values.size()-1]){
                return false;
            }
            values.pop_back();
            slow = slow->next;
        }

        return true;
    }
};

// OPTIMIZED SOL | TC = O(2N) | SC = O(1)
class Solution {
public:
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;

    }

    bool isPalindrome(ListNode* head) {
        ListNode* curr1 = head;
        ListNode* midNode = middle(curr1);
        midNode->next = reverse(midNode->next);

        ListNode* curr2 = midNode->next;

        while(curr2 != NULL){
            if(curr1->val != curr2->val){
                return false;
            }

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return true;
        
    }
};