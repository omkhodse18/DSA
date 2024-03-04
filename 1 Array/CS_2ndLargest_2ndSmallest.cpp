// https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

int getSecondLargest(int n, vector<int> a){
    int largest = INT_MIN;
    int secondLargest = -1;

    for(int i=0;i<n;i++){
        if(a[i] > largest){
            secondLargest = largest;
            largest = a[i];
        }
        else if(a[i] > secondLargest && a[i]!=largest){
            secondLargest = a[i];
        }
    }

    return secondLargest;
}

int getSecondSmallest(int n, vector<int> a){
    int smallest = INT_MAX;
    int secondSmallest = -1;

    for(int i=0;i<n;i++){
        if(a[i] < smallest){
            secondSmallest = smallest;
            smallest = a[i];
        }
        else if(a[i] < secondSmallest && a[i]!=smallest){
            secondSmallest = a[i];
        }
    }

    return secondSmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int secondLargest = getSecondLargest(n, a);    
    int secondSmallest = getSecondSmallest(n, a);    
    return {secondLargest, secondSmallest};
}
