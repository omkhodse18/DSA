// https://www.codingninjas.com/studio/problems/value-equal-to-the-index-value_1115771?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0&leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
using namespace std;

vector<int> valueEqualToIndices(vector<int>& numArray, int n) {
	// Write your code here.
	vector<int> ans;

	for(int i=0;i<n;i++){
		if(i==numArray[i]){
			ans.push_back(i);
		}
	}

	if(ans.size()==0){
		return {-1};
	}

	return ans;
}