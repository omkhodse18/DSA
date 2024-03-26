// https://www.codingninjas.com/studio/problems/pair-difference-k_1089634?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0&leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

string isPairDifferenceK(vector<int>arr, int n, int k) {
    // Write your code here.
    int i = 0;
    int j = 1;

    while(i<n && j<n){
        int differnce = abs(arr[i]-arr[j]);

        if(differnce==k && i != j){
            return "Yes";
        }
        else if (differnce > k){
            i++;
        }
        else{
            j++;
        }
    }

    return "No";
}
