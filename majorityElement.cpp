/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Could you solve the problem in linear time and in O(1) space?
*/

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> nums){
	unordered_map<int,int> hshmp;

	for(int i=0; i<nums.size(); i++){
		if(hshmp.find(nums[i])!=hshmp.end()) //found in hashmap
			hshmp[nums[i]]++;
		else
			hshmp[nums[i]]=1;
	}

	int maxCount=INT_MIN, majorityElement=-1;

	for(auto it=hshmp.begin(); it!=hshmp.end(); it++){
		if(it->second > maxCount){
			maxCount= it-> second;
			majorityElement= it->first;
		}
	}

	return majorityElement;
}

int main(){
	int n, x;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	cout<<majorityElement(v);

	return 0;
}