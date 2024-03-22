// https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?leftPanelTabValue=SUBMISSION&customSource=studio_nav

#include <bits/stdc++.h> 
using namespace std;
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int largest = INT_MIN;

    for(int i = 0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }

    return largest;
}
