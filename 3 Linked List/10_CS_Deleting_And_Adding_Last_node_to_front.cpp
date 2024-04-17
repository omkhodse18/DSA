// https://www.naukri.com/code360/problems/deleting-and-adding-the-last-node_1170051?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM

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


Node *delAddLastNode(Node *head){
	// Write your code here.
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    temp->next = head;
    head = temp;

    return head;
}


