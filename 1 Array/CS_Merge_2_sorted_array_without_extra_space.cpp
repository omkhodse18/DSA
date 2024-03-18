// https://www.codingninjas.com/studio/problems/merge-two-sorted-arrays-without-extra-space_6898839?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

// Optimal Approach 1
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int m = a.size();
	int n = b.size();

	int left = m - 1;
	int right = 0;

	while(left>=0 && right<n){
		if(a[left] > b[right]){
			swap(a[left], b[right]);
			left--;
			right++;
		}
		else{
			break;
		}
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
}

// Optimal Approach 2 = GAP Method

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &arr1, vector<long long> &arr2){
	// Write your code here.
	int n = arr1.size();
	int m = arr2.size();

    // code here 
    int gap = ceil((float)(n+m)/2);
    
    while(gap>0){
        int i = 0;
        int j = gap;
        
        while(j<(n+m)){
			//Both are in 1st
            if(j<n && arr1[i]>arr1[j]){
                swap(arr1[i],arr1[j]);
            }
			// Both are in 1st and 2nd
            else if(j>=n && i<n && arr1[i] > arr2[j-n]){
                swap(arr1[i],arr2[j-n]);
            }
			// Both are in 2nd
            else if(j>=n && i>=n && arr2[i-n] > arr2[j-n]){
                swap(arr2[i-n],arr2[j-n]);
            }
            
            i++;
            j++;
        }
        
        if(gap==1){
            gap = 0;
        }
        else{
            gap = ceil((float)gap/2);
        }
    }       
}