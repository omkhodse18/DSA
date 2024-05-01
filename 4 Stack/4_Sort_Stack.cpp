// https://www.naukri.com/code360/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
using namespace std;

void sortstk(int x,stack<int>& stack){
	if(stack.empty() || stack.top() < x){
		stack.push(x);
	}
	else{
		int y = stack.top();
		stack.pop();
		sortstk(x,stack);
		stack.push(y);
	}
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return;
	}
	int x = stack.top();
	stack.pop();
	sortStack(stack);
	sortstk(x,stack);
	
}