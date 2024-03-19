// https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int badCount = 0;
        int goodCount = 0;
        
        for(int i=0;i<n;i++){
            if(arr[i] <= k){
                goodCount++;
            }
        }
        
        for(int i=0;i<goodCount;i++){
            if(arr[i] > k){
                badCount++;
            }
        }
        
        int ans = badCount;
        
        cout<<"Good Count : "<<goodCount<<endl;
        cout<<"Bad Count : "<<badCount<<endl;
        cout<<"Initial ans : "<<ans<<endl;

        for(int i=0,j=goodCount;j<n;i++,j++){
            if(arr[i] > k){
                badCount--;
            }
            
            if(arr[j] > k){
                badCount++;
            }
            
            cout<<"I : "<<i<<endl;
            cout<<"J : "<<j<<endl;
            cout<<"Good Count : "<<goodCount<<endl;
            cout<<"Bad Count : "<<badCount<<endl;
            cout<<"Initial ans : "<<ans<<endl;

            ans = min(ans,badCount);
        }
        
        
        return ans;
    }
};



// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
