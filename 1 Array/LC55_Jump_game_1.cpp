// https://leetcode.com/problems/jump-game/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        int n = nums.size();
        
        if(n==1){
        return true;
        }

        if(nums[start] == 0){
            return false;
        }

        int maxReach = nums[start]+start;
        int jumps = 1;
        int steps = nums[0];

        for(int i=1;i<n;i++){
            if(i == n-1){
                return true;
            }

            maxReach = max(maxReach,nums[i]+i);

            steps--;

            if(steps==0){
                jumps++;

                if(i >= maxReach){
                    return false;
                }
                
                steps = maxReach - i;
            }

        }

        return false;
    }
};

