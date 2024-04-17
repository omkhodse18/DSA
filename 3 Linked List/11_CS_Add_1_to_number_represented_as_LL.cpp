// https://www.naukri.com/code360/problems/add-one-to-a-number-represented-as-linked-list_920557?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries

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

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}


// ++++++++++++++++++++++++++++>> ITEREATIVE APPROACH <<++++++++++++++++++++++++++++++++++++
Node* iterativeApp(Node *head){
    head = reverse(head);
        
    Node* temp = head;
    int carry = 1;
        
    while(temp!=NULL){
        temp->data = temp->data + carry;
        
        if(temp->data < 10){
            carry = 0;
            break;
        }
        else{
            carry = 1;
            temp->data = 0;
        }
        
        temp = temp->next;
    }
    
    if(carry == 1){
        Node* newNode = new Node(carry);
        head = reverse(head);
        newNode->next = head;
        head = newNode;
        
        return head;
    }
    
    head = reverse(head);
    
    return head;
}

// ++++++++++++++++++++++++++++>> RECURSIVE APPROACH <<++++++++++++++++++++++++++++++++++
int helper(Node* temp){
    if(temp == NULL){
        return 1; 
    }

    int carry = helper(temp->next);

    temp->data = temp->data + carry;

    if(temp->data < 10){
        return 0;       //Returning carry - 0
    }

    temp->data = 0; 
    return 1;           //Returning carry - 1
}

Node* recursiveApp(Node *head){
    int carry = helper(head);

    if(carry == 1){
        Node* newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
        return head;
    }

    return head;
}

Node *addOne(Node *head)
{
    // head = iterativeApp(head);
    head = recursiveApp(head);

    return head; 
}

