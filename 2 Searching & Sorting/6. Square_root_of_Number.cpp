// https://leetcode.com/problems/sqrtx/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1){
            return x;
        }

        int low = 1;
        int high = x/2;  // Here x/2, because square root is always smaller than half of square i.e 25 half 12 (12.5) and answer always lies between 1 to 12.  
        int ans = 0;

        while(low <= high){
            long long int mid = low + (high-low)/2;
            long long int pro = mid * mid;

            if(pro <= x){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }

        }

        return ans;    
    }
};