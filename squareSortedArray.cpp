/*Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?*/

#include<bits/stdc++.h>
using namespace std;

vector<int> square_sorted_array1(vector<int>& nums){
	for(int i=0; i<nums.size(); i++){
		nums[i]*=nums[i];
	}

	sort(nums.begin(), nums.end());

	return nums;
}

//two pointer approach
vector<int> square_sorted_array2(vector<int>& nums){
	vector<int> ans(nums.size());
		int i = 0;
		int j = nums.size()-1;
		for(int k=nums.size()-1; k>=0; k--)
        {
            if(abs(nums[i]) > abs(nums[j]))
            {
                ans[k] = nums[i]*nums[i];
                i++;
            }

				else
                {
                    ans[k] = nums[j] * nums[j];
                    j--;
                }

			}

			return ans;
}

int main(){
	
	int n,x;
	cin>>n;
	vector<int> v,a;
	for(int i=0; i<n; i++){
		cin>>x;
		v.push_back(x);
	}

	a=square_sorted_array1(v);
	for(auto it:a) cout<<it<<" ";
	cout<<endl;
	a=square_sorted_array2(v);
	for(auto it:a) cout<<it<<" ";

	return 0;
}