// https://leetcode.com/problems/two-sum/description/

/*
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.

    Example 1:

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    Example 2:

    Input: nums = [3,2,4], target = 6
    Output: [1,2]
    Example 3:

    Input: nums = [3,3], target = 6
    Output: [0,1]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> pairs;
        vector<int> ans;
        int n = nums.size();

        for(int i=0;i<n;i++){
            pairs.push_back({nums[i],i});
        }

        sort(pairs.begin(),pairs.end());

        int i=0,j=n-1;

        while(i<j){
            int sum = pairs[i].first + pairs[j].first;

            if(sum == target){
                ans.push_back(pairs[i].second);
                ans.push_back(pairs[j].second);
                break;
            }
            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};