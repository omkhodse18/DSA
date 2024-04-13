// https://www.naukri.com/code360/problems/remove-duplicates-from-unsorted-linked-list_1069331?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM

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


// Brute force | SC = O(N^2) | TC = O(1)
Node *removeDuplicates(Node *head){
    // Write your code here
    Node* current = head;

    while (current != nullptr) {
        Node* runner = current;
        
        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            } else {
                runner = runner->next;
            }
        }
        
        current = current->next;
    }
    return head;
}


// Optimized one | TC = O(N) | SC = O(N)

Node *removeDuplicates(Node *head){
    unordered_map<int,int> mp;
    Node* curr = head;
    Node* prev = NULL;

    while(curr!=NULL){
        if(mp[curr->data] == 1){
            prev->next = curr->next;
            delete curr;
        }
        else{
            prev = curr;
            mp[curr->data] = 1;
        }

        curr = curr->next;
    }

    return head;
}
