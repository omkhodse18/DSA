// https://leetcode.com/problems/minimum-size-subarray-sum/

/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
 "whose sum is greater than or equal to target". If there is no such subarray, return 0 instead.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int n = nums.size();
        int sum = nums[0];

        while(right < n){

            while(left<= right && sum >= target){
                minLen = min(minLen, right - left + 1);
                sum = sum - nums[left];
                left++;
            }

            right++;
            if(right < n){
                sum = sum + nums[right];
            }
        }

        return (minLen==INT_MAX) ? 0 : minLen;
        
    }
};