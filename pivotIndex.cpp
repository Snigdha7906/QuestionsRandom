/*Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.*/

#include<bits/stdc++.h>
using namespace std;

int calcSum(vector<int> nums, int start, int end){
	int sum=0;
	for(int i=start; i<=end;i++)
		sum+=nums[i];
	return sum;
}

int pivotIndex1(vector<int>& nums){  //bruteforce O(n^2)

	for (int i = 0; i < nums.size(); ++i)
	{
		int ls=calcSum(nums,0,i-1);
		int rs=calcSum(nums,i+1, nums.size()-1);
		if(ls==rs)
			return i;
	}
	return -1;
}

int pivotIndex2(vector<int>& nums){
	int sum=0, ls=0;
	for(int i=0;i<nums.size(); i++)
		sum+=nums[i];

	for(int i=0; i<nums.size(); i++){
		if(ls==(sum-ls-nums[i]))   // rs= nums- ls - nums[i]
			return i;
		ls+= nums[i];
	}
	return -1;
}
int main(){
	int n,x;
	cin>>n;
	vector<int> nums;
	for (int i = 0; i < n; i++)
	{
		cin>>x;
		nums.push_back(x);
	}

	cout<<pivotIndex1(nums)<<endl<<pivotIndex2(nums);
	return 0;
}