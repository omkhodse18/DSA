// https://leetcode.com/problems/jump-game-ii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }

        int maxReach = nums[0];
        int steps = nums[0];
        int jumps = 1;
        int n = nums.size();

        for(int i=1;i<nums.size();i++){
            if(i == n-1){
                return jumps;
            }

            maxReach = max(maxReach, nums[i]+i);
            steps--;

            if(steps == 0){
                jumps++;
                steps = maxReach - i;
            }
        }

        return -1;
    }
};