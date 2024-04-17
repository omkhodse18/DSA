// https://www.naukri.com/code360/problems/reverse-linked-list_920513?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

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

void reverse(Node* &head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }

    reverse(head, curr->next, curr);
    curr->next = prev;
}


Node* reverseLinkedList(Node *head)
{
    // Write your code here
    Node* curr = head;
    Node* prev = NULL;

    reverse(head, curr, prev);

    return head;
}
