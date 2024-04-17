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

// https://www.naukri.com/code360/problems/split-a-circular-linked-list_1071003?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

/*
1. Initialize **`fast`** and **`slow`** pointers at the head.
2. Advance **`fast`** by two steps and **`slow`** by one step until **`fast`** reaches the head or the node before it.
3. Set **`newHead1`** as the original head and **`newHead2`** as the node after **`slow`**.
4. Make **`slow`** point back to **`newHead1`**, splitting the list.
5. Find the last node of the second list using **`temp`**.
6. Connect the last node to **`newHead2`**, completing the split.
*/

void splitCircularList(Node *head)
{
    Node* fast = head->next;
    Node* slow = head;
    
    while(fast!=head && fast->next!=head){
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* newHead1 = head;
    Node* newHead2 = slow->next;
    slow->next = head;

    Node* temp = newHead2;
    while(temp->next != head){
        temp = temp->next;
    }
    
    temp->next = newHead2;
}