/*Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Input: nums = [3,4,2,3]
Output: false
*/

#include<bits/stdc++.h>
using namespace std;

bool checkPossibility(vector<int>& nums) {
        
        int pos=-1, n=nums.size();   
        
        for(int i=0; i<n-1; i++){
            
            if(nums[i]>nums[i+1]){
                if(pos!=-1)     //second increasing has occured
                    return false;
                pos=i;          //set to i when first increasing occurs
            } 
        }
        cout<<pos;
        /* cases: valid if
        eg 3,4,2,3      pos=1
           0 1 2 3 
           1.  nums[pos-1]<= nums[pos+1]    nums[0]>nums[2]  3>2 therefore false
           2.  nums[pos]<= nums[pos+2];     nums[1]>nums[3]  4>3 therefore false
           3.  pos==0 ie first element                  pos=1  false
           4.  pos= n-2  ie second last element         pos=1  false
           5.  pos==-1   ie all are non decreasing      pos=1  false
           
        */
        bool x= (pos==-1 || pos==0 || pos==n-2 || nums[pos-1]<=nums[pos+1] || nums[pos]<=nums[pos+2]);
        return x;
    }

int main(){
	int n,x,y;
	
	cout<<"Enter no of elements"<<endl;
	cin>>n;
	cout<<"Enter elements:"<<endl;
	vector<int> v;

	for(int i=0; i<n; i++){
		cin>>x;
		v.push_back(x);
	}

	cout<<"Array is non decreasing : "<< checkPossibility(v);
}

/*
4

3 4 2 3
Expected Output: false
*/