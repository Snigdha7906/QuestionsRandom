/*Given an array arr of N integers. Find the contiguous sub-array with maximum sum.*/


#include<bits/stdc++.h>
using namespace std;

// kadane algo that works with negative numbers as well
int maxsubarraySum(vector<int> nums)
{
	int currsum=0, maxsum=0;
	bool allneg=true;

	for(int i=0;i<nums.size();i++){

		if(nums[i]>0){
			allneg=false;
		}

		currsum+=nums[i];

		if(currsum<0)
			currsum=0;
		maxsum= currsum>maxsum? currsum:maxsum;
	}

	if(allneg==true)
		return *max_element(nums.begin(), nums.end());
	else
		return maxsum;
}

int main(){
	int n, x, k;
	vector<int> v;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		v.push_back(x);
	}
	int maxsum= maxsubarraySum(v);
	cout<<maxsum;
	return 0;
}