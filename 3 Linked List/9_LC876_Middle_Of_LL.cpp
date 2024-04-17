#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Node{

    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
};



// https://leetcode.com/problems/middle-of-the-linked-list/
// sol 1  | TC= O(N) | SC = O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

// https://www.naukri.com/code360/problems/middle-of-linked-list_973250?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM
// SOL-2 | TC= O(N) + O(N) | SC = O(1)
int length(Node* head){
    Node* temp=head;
    int count = 0;
    
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
}

Node *findMiddle(Node *head) {
    // Write your code here
    Node* temp=head;
    int len = length(head);
    int middleNode = ((len/2) + 1);

    while(temp!=NULL){
        middleNode = middleNode - 1;

        if(middleNode==0){
            break;
        }

        temp = temp->next;
    }

    return temp;
    
}
