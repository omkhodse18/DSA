// https://leetcode.com/problems/product-of-array-except-self/description/

#include<bits/stdc++.h>
using namespace std;

// Better Solution | TC = O(n) + O(n) + O(n) = 3n | SC = O(n) + O(n) = 2n
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);

        int pro = 1;
        for(int i=0;i<n;i++){
            pro = pro * nums[i];
            left[i] = pro;
        }

        pro = 1;
        for(int i=n-1;i>=0;i--){
            pro = pro * nums[i];
            right[i] = pro;
        }

        nums[0] = right[1];

        for(int i=1;i<n-1;i++){
            nums[i] = left[i-1] * right[i+1];
        }

        nums[n-1] = left[n-2];

        return nums;
    }
};


// Optimized Solution | TC = O(n) + O(n) = 2n | SC = O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
    
        int pro = 1;
        for(int i=0;i<n;i++){
            pro = pro * nums[i];
            output.push_back(pro);
        }

        pro = 1;
        for(int i=n-1;i>0;i--){
            output[i] = pro * output[i-1];
            pro = pro * nums[i];
        }

        output[0] = pro;

        return output;
    }
};