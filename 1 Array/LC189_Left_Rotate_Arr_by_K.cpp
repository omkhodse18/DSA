// https://leetcode.com/problems/rotate-array/description/
#include<bits/stdc++.h>
using namespace std;

//Codestudio solution
void reverseArray(vector<int> &arr, int start, int end){
    int s = start;
    int e = end-1;

    while(s<e){
        swap(arr[s++],arr[e--]);
    }
}

vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    int n = arr.size();

    reverseArray(arr, 0, k);
    reverseArray(arr, k, n);
    reverseArray(arr, 0, n);

    return arr;
}
/*-------------------------------------------------------------------------------*/
//Leetcode solution
class Solution {
public:
    void rotate(vector<int>& nums, int k){
        vector<int> temp(nums.size());
        for(int i=0;i<nums.size();i++){
            temp[(i+k)%nums.size()] = nums[i];
        }
        nums = temp;
    }
};