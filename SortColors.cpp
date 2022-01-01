/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.*/

#include<bits/stdc++.h>
using namespace std;

// void SortColors(vector<int>& nums){
// 	sort(nums.begin(), nums.end());
// }

void SortColors(vector<int>& nums){
	int red=0, white=0, blue=0;

	for(int i=0; i<nums.size(); i++){
		if(nums[i]==0) red++;
		else if(nums[i]==1) white++;
		else blue++;
	}

	nums.clear();

	for(int i=0; i<red; i++)
	nums.push_back(0);
	for(int i=0; i<white; i++)
	nums.push_back(1);
	for(int i=0; i<blue; i++)
	nums.push_back(2);

}

int main(){
	int n, x;
	cin>>n;
	vector<int> v;
	for(int i=0; i<n; i++){
		cin>>x;
		v.push_back(x);
	}

	SortColors(v);
	for(auto it:v) cout<<it;
}