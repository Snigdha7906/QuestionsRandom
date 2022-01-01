/* Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space? */

#include<bits/stdc++.h>
using namespace std;

void rotate1(vector<int>& nums, int k) {
    
    k=k%nums.size();
    for(int i=0; i<k; i++){
 	int x=nums[nums.size()-1];
 	for(int j=nums.size()-1; j>0; j--){
 		nums[j]= nums[j-1];
 	}
 		nums[0]=x;
 	}

 	for (int i = 0; i < nums.size(); i++)
 	{
 		cout<<nums[i];
 	}
 	cout<<endl;
}

    
    
void rotate2(vector<int>& nums, int k){
    int x=nums.size()-k%nums.size();
    for(int i=0; i<x; i++){
        nums.push_back(nums[i]);
    }
        nums.erase(nums.begin(), nums.begin()+x);

    for (int i = 0; i < nums.size(); i++)
 	{
 		cout<<nums[i];
 	}
 	cout<<endl;
}

void reverse(vector<int>& nums, int start, int end)
{
    while(start<end)
    {
        int temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;
    }
}

void rotate3(vector<int>& nums, int k)
{
    k=k%nums.size();
    reverse(nums,0, nums.size()-1);
    reverse(nums,0,k-1);
    reverse(nums,k, nums.size()-1);


    for (int i = 0; i < nums.size(); i++)
 	{
 		cout<<nums[i];
 	}
 	cout<<endl;
}



int main(){

	vector<int> nums;
	int k,size,x;
	cin>>k;
	cin>>size;
	for (int i = 0; i < size; i++)
	{
		cin>>x;
		nums.push_back(x);
	}
	rotate1(nums, k);
	rotate2(nums, k);
	rotate3(nums, k);
	return 0;
}