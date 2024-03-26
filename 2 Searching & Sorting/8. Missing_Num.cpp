// https://leetcode.com/problems/missing-number/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalSum = 0;
        int actualSum = 0;
        int j=0;

        for(int i=1;i<=nums.size();i++){
            totalSum += i;
            actualSum += nums[j++];
        }

        return (totalSum-actualSum);
    }
};