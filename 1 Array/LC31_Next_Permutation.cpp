// https://leetcode.com/problems/next-permutation/description/

// For Intuition - https://www.codingninjas.com/studio/problems/893046?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=PROBLEM


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1 = -1;
        int n = nums.size();

        for(int i = n-1;i>=0;i--){
            if(i<n-1 && nums[i] < nums[i+1]){
                idx1 = i;
                break;
            }
        }

        if(idx1 == -1){
            reverse(nums.begin(), nums.end());
        }
        else{
            int idx2 = -1;

            for(int i=n-1;i>idx1;i--){
                if(nums[i] > nums[idx1]){
                    idx2 = i;
                    break;
                }
            }

            swap(nums[idx1],nums[idx2]);

            reverse(nums.begin()+idx1+1, nums.end());
        }
    }
};