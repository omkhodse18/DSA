// https://www.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int arr1[], int arr2[], int n) {
        // code here 
        
        int m1=-1, m2=-1;
        int i=0,j=0;
            
        for(int count=0;count<=n;count++){
            if(i==n){
                m1 = m2;
                m2 = arr2[0];
                break;
            }
            else if(j==n){
                m1 = m2;
                m2 = arr1[0];
                break;
            }
            
            if(arr1[i] <= arr2[j]){
                m1 = m2;
                m2 = arr1[i];
                i++;
            }
            else{
                m1=m2;
                m2 = arr2[j];
                j++;
            }
        }
        
        return m1+m2;
            
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends