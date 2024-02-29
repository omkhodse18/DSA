// https://leetcode.com/problems/unique-number-of-occurrences/description/

#include<bits/stdc++.h>
using namespace std;

/*
Approaches
(Also explained in the code)

Approach 1 (Without Sets and Maps)
- Sort the input array arr to group identical elements together.
- Traverse the sorted array, counting occurrences of each element.
- Store the counts in a separate vector v.
= Sort the vector v to make it easier to check for duplicates.
- Iterate through v and check if adjacent elements are equal. If so, return false.
- If the loop completes, it means all counts are unique, and the function returns true.

Complexity
Time complexity : O(nlogn)
Space complexity : O(n)
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> v;

        for(int i=0;i<arr.size();i++){
            int count = 0;

            while(i+1 < arr.size() && arr[i] == arr[i+1]){
                i++;
                count++;
            }

            count++;

            v.push_back(count);
        }

        sort(v.begin(),v.end());

        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]){
                return false;
            }
        }
        

        return true;

        
    }
};

/*
Approach 2 (With Sets and Maps)
- Create an unordered map freq to store the frequency of each element in the array.
- Iterate through each element of the input array (arr).
- Update the frequency count in the freq map.
- Create an unordered set s to store unique frequencies.
- Iterate through the entries in the freq map and insert the frequencies into the set s.
- Check if the size of the freq map is equal to the size of the set s. If they are equal, it means that the occurrences of frequencies are unique.

Complexity
Time complexity : O(n)
Space complexity : O(n)
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      unordered_map<int,int>freq;
      for(auto x: arr){
          freq[x]++;
      }  
      unordered_set<int>s;
      for(auto x: freq){
          s.insert(x.second);
      }
      return freq.size()==s.size();
    }
};


