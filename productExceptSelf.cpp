/*Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].*/

#include<bits/stdc++.h>
using namespace std;

int product(vector<int> nums, int start, int end){
        int product=1;
        if(start<0 || end>nums.size()-1)
        {
            return product;
        }        

        for(int i=start; i<= end; i++)
            product*=nums[i];
        return product;
    }
    
    vector<int> productExceptSelf1(vector<int>& nums) {   //O(n^2) time limit exceeds
        vector<int> output(nums.size());
        for(int i=0; i<nums.size(); i++){
            output[i]=product(nums,0, i-1) * product(nums, i+1, nums.size()-1);
        }
        return output;
    } 

    vector<int> productExceptSelf2(vector<int>& nums){
    	int n= nums.size();
    	vector<int> output(n);

    	int L[n], R[n];

    	R[n-1]=1; 
    	for(int i= n-2;i>=0;i--){
    		R[i]= R[i+1]* nums[i+1];
    	}
    	
    	L[0]=1;
    	for(int i=1; i<n; i++){			
    		L[i]= L[i-1]* nums[i-1];	
    	}

    	for(int i=0; i<n; i++){
    		output[i]= L[i] * R[i];
    	}
    	return output;
    }

   int main(){
	int n,x;
	cin>>n;
	vector<int> nums,ans;
	for (int i = 0; i < n; i++)
	{
		cin>>x;
		nums.push_back(x);
	}

	ans=productExceptSelf1(nums);
	for(auto it:ans) cout<<it<<" ";
	cout<<endl;
	ans=productExceptSelf2(nums);
	for(auto it:ans) cout<<it<<" ";
	return 0;
}