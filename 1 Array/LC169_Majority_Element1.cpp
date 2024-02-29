// https://leetcode.com/problems/majority-element/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0;
        int n = nums.size();
        int count = 0;

        for(int i=0;i<n;i++){
            if(count == 0){
                ele = nums[i];
                count = 1;
            }
            else if(ele != nums[i]){
                count--;
            }
            else{
                count++;
            }
        }

        return ele;
    }
};