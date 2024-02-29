// https://leetcode.com/problems/single-number/description/

// Better

#include<bits/stdc++.h>
#include <unordered_map> 
using namespace std;

int findUnique(int *arr, int size)
{
    //Write your code here
    unordered_map<int,int> mp;
    int ans = -1;

    for(int i=0;i<size;i++){
        mp[arr[i]] += 1;
    }

    for(auto x:mp){
        if(x.second ==1){
            ans = x.first;
        }
    }

    return ans;
}

// Optimal
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            ans = ans ^ nums[i];
        }

        return ans;
    }
};

