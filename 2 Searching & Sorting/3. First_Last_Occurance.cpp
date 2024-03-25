// https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0&leftPanelTabValue=SUBMISSION

#include<bits/stdc++.h>
using namespace std;

int firstPos(vector<int>& arr, int n, int k){
    int start = 0;
    int end = n - 1;
    int idx = -1;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] == k){
            idx = mid;
            end = mid - 1;
        }
        else if(arr[mid] > k){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return idx;
}

int secondPos(vector<int>& arr, int n, int k){
    int start = 0;
    int end = n - 1;
    int idx = -1;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] == k){
            idx = mid;
            start = mid + 1;
        }
        else if(arr[mid] > k){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return idx;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair<int, int> ans;
    ans.first = firstPos(arr,n,k);
    ans.second = secondPos(arr,n,k);

    return ans;
}
