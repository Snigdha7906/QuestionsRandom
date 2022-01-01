/*Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]). Return the running sum of nums.
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
*/

#include<bits/stdc++.h>
using namespace std;

/*void*/ vector<int> runningSum(vector<int>/*&*/ nums){
	for(int i=1; i<nums.size(); i++){
		nums[i]=nums[i-1]+nums[i];
	}
	return nums;
}

int main(){
	int  n,x;
	vector<int> v;
	cout<<"Enter no of elements: ";
	cin>>n;
	cout<<"Enter elements: ";
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}

	cout<<"Running sum vector: "<<endl;
	v=runningSum(v); //runningSum(v);
	for(auto i:v){
		cout<<i<<" ";
	}
	return 0;
}

/*
5
3 1 2 10 1
Expected Output: [3,4,6,16,17]
*/