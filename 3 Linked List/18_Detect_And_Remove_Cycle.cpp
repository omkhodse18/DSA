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

//APP - TC = O(2N) | SC = O(1)

Node* startOfLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            break;
        }
    }

    if(fast==NULL || fast->next==NULL){
        return NULL;
    }

    fast = head;

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

Node *removeLoop(Node *head){
    Node* startNode = startOfLoop(head);

    if(startNode == NULL){
        return head;
    }

    Node* temp = startNode->next;

    while(temp->next != startNode){
        temp = temp->next;
    }

    temp->next = NULL;

    return head;
}

// APP-2 | HASHING | TC = O(N) | SC = O(N)

void removeLoop2(Node* head){
    unordered_map<Node*, int> mp;
    Node* prev = NULL;
    Node* temp = head;
    
    while(temp!=NULL){
        if(mp.find(temp) == mp.end()){
            mp[temp] += 1;
            prev = temp;
            temp = temp->next;
        }
        else{
            prev->next = NULL;
            break;
        }
    }
}