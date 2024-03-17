// https://www.codingninjas.com/studio/problems/make-it-palindrome_3189160?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=1 

#include <bits/stdc++.h> 
using namespace std;

int palindrome(vector<int> arr)
{
	// Write your code here.
	int count = 0;
	int n = arr.size();

	int left = 0;
	int right = n-1;

	long long A[n]; 
	for(int i=0;i<n;i++){  
		A[i]=arr[i]; 
	}   

	while(left<right){
		if(A[left] == A[right]){
			left++;
			right--;
		}
		else if(A[left] > A[right]){
			right--;
			A[right] = A[right] +A[right+1];
			count++;
		}
		else{
			left++;
			A[left] = A[left] + A[left-1];
			count++;
		}
	}

	return count;
	
}