/*Range Sum Query - Immutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int i, int j) Return the sum of the elements of the nums array in the range [i, j] inclusive (i.e., sum(nums[i], nums[i + 1], ... , nums[j]))

 */
#include<bits/stdc++.h>
using namespace std;

	vector<int> sum;

	void NumArr(vector<int>& nums){
		sum=nums;
		for(int i=1; i<nums.size(); i++){
			sum[i]=sum[i-1]+ sum[i];
		}
	}

	int sumRange(int i, int j){
		if(i==0)
			return sum[j];
		else
			return sum[j]- sum[i-1];
	}

int main(){
	int n,x,i,j;
	vector<int> v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	NumArr(v);
	cin>>i;
	cin>>j;
	cout<<sumRange(i,j);
}
