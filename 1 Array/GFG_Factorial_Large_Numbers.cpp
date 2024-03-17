// https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1 

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void multiply(vector<int>& arr, int digit){
        int carry = 0;

        for(int i=0;i<arr.size();i++){
            int pro = arr[i] * digit + carry;
            arr[i] = pro % 10;
            carry = pro/10;
        }   
        
        while(carry){
            int num = carry % 10;
            arr.push_back(num);
            carry = carry/10;
        }
        
    }
    
    vector<int> factorial(int N){
        // code here
        vector<int> ans;
        ans.push_back(1);
        
        for(int i=2;i<=N;i++){
            multiply(ans,i);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends