// 2441. Largest Positive Integer That Exists With Its Negative
// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size(), l=0, r=n-1;
        sort(nums.begin(), nums.end());
        while(l<r && nums[l]!=-nums[r]){
            if (-nums[l]>nums[r]) l++;
            else r--;

        }
        return (l<r) ?nums[r]:-1;
          
    }
};