// https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
using namespace std;

void insertAtBottom(stack<int> &stack, int x){
    if(stack.empty()){
        stack.push(x);
        return;
    }

    int topElement = stack.top();
    stack.pop();
    insertAtBottom(stack,x);
    stack.push(topElement);
}

void solve(stack<int> &stack){
    if(stack.empty()){
        return;
    }    

    int topElement = stack.top();
    stack.pop();
    solve(stack);
    insertAtBottom(stack,topElement);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    solve(stack);
}