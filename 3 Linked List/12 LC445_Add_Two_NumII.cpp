#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// https://leetcode.com/problems/add-two-numbers-ii/description/

// TC = max(m,n) | SC = max(m,n);

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

    ListNode* addLists(ListNode* curr1, ListNode* curr2){
        int val1 = 0, val2 = 0, carry = 0;

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
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* addedList = addLists(l1,l2);
        addedList = reverse(addedList);
        return addedList;
    }
};


// Stack Approach | TC = O(N+M) | SC = O(N+M)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stack1, stack2;
        
        // Push digits of l1 into stack1
        while (l1 != nullptr) {
            stack1.push(l1->val);
            l1 = l1->next;
        }
        
        // Push digits of l2 into stack2
        while (l2 != nullptr) {
            stack2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        ListNode* result = nullptr;
        
        // Perform addition using stacks
        while (!stack1.empty() || !stack2.empty() || carry != 0) {
            int sum = carry;
            if (!stack1.empty()) {
                sum += stack1.top();
                stack1.pop();
            }
            if (!stack2.empty()) {
                sum += stack2.top();
                stack2.pop();
            }
            carry = sum / 10;
            sum %= 10;
            
            // Create new node for the current digit and link it to the result
            ListNode* newNode = new ListNode(sum);
            newNode->next = result;
            result = newNode;
        }
        
        return result;
    }
};