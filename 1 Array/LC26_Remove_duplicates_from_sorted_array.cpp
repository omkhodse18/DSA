// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// Remove Duplicates from Sorted Array(In-place)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;

        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[i-1]){
                nums[j+1] = nums[i];
                j++;
            }
        }

        return j+1;
    }
};