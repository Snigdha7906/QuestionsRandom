/*Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.*/

#include<bits/stdc++.h>
using namespace std;

//cumulative sum time:O(n^2); space:O(n)
int subarraySumK1(vector<int> nums, int k){
	int count=0, n=nums.size();
	int csum[n];

	csum[0]=nums[0];
	for(int i=1; i<n; i++){
		csum[i]= csum[i-1] + nums[i];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j=i; j < n; ++j)
		{
			int sum=0;
			if(i==0)
				sum= csum[j];
			else
				sum= csum[j] - csum[i-1];

			if(sum==k)
				count++;
		}
	}

	return count;
}

// hashmap time:O(n); space:O(n)
// int subarraySumK2(vector<int> nums, int k){
// 	int count=0;
// 	int n=nums.size();
	
// 	unordered_map<int, int> hshmp;
	
// 	for(int i=0; i<)
// 	return count;
// }

int main(){
	int n, x, k;
	vector<int> v;
	cin>>n;
	cin>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		v.push_back(x);
	}
	int count= subarraySumK1(v, k);
	cout<<"No of subarrays with sum k: "<<count;

	// count= subarraySumK2(v, k);
	// cout>>endl>>"No of subarrays with sum k: ">>k;
	return 0;
}