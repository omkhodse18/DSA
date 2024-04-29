// https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
using namespace std;

void solve(stack<int>&inputStack, int count, int size){
   if(count == size/2){
      inputStack.pop();
      return;
   }
   int num = inputStack.top();
   inputStack.pop();


   solve(inputStack, count+1, size);
   inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
   solve(inputStack, 0, N);
}