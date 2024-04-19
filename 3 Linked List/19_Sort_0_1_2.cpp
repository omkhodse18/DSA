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

// https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM

// TC = O(N) | SC = O(1)

Node* sortList(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* temp = head;

    while(temp!=NULL){
        if(temp->data==0){
            zeroTail->next = temp;
            zeroTail = zeroTail->next;
        }
        else if(temp->data == 1){
            oneTail->next = temp;
            oneTail = oneTail->next;
        }
        else{
            twoTail->next = temp;
            twoTail = twoTail->next;
        }

        temp = temp->next;
    }

    zeroTail->next = (oneHead->next != NULL) ? oneHead->next : twoHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    Node* newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}
