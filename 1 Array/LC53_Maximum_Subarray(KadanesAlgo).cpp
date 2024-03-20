// https://leetcode.com/problems/maximum-subarray/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
       
        for(int i=0;i<nums.size();i++){
            sum += nums[i];

            if(maxi < sum){
                maxi = sum;
            }

            if(sum < 0){
                sum = 0;
            }
        } 

        return maxi;
    }
};


/*
    Follow up question - Print the maximum subarray
*/

class Solution {
public:
    void printArray(vector<int>& nums,int i,int n){
        for(;i<=n;i++){
            cout<<nums[i]<<" ";
        }
    }

    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        int start = -1;
        int end = -1;

        for(int i=0;i<nums.size();i++){
            if(sum == 0){
                start = i;
            }

            sum += nums[i];

            if(maxi < sum){
                maxi = sum;
                end = i;
            }

            if(sum < 0){
                sum = 0;
            }
        } 

        printArray(nums,start,end);

        return maxi;
    }
};