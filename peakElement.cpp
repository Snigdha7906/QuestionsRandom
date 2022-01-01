/*A peak element in an array is the one that is not smaller than its neighbours.
Given an array of size N, find the index of any one of its peak elements.
 */

#include<bits/stdc++.h>
using namespace std;

    int peakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        if(n==2){
            return nums[0]>nums[1]? 0:1;
        }
        
        if(nums[0]>nums[1])
            return 0;
        
        for(int i=1; i<n-1; i++){
            
            if(nums[i]> nums[i-1] && nums[i]> nums[i+1]){
                return i;
            }
        }
        
       return n-1;
    }

int main(){
	int n, x;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	cout<<"Index:"<<peakElement(v);

	return 0;
}