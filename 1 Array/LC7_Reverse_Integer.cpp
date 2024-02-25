// https://leetcode.com/problems/reverse-integer/description/
/*
    Example 1:
    Input: x = 123
    Output: 321

    Example 2:
    Input: x = -123
    Output: -321

    Example 3:
    Input: x = 120
    Output: 21

*/

#include<bits/stdc++.h>
using namespace std;
//C++
class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        int remainder = 0;

        while(x != 0){
            remainder = x % 10;
            ans = ans * 10 + remainder;

            if(ans > INT_MAX || ans<INT_MIN){
                return 0;
            }

            x = x/10;
        }
  
        return ans;
    }
};