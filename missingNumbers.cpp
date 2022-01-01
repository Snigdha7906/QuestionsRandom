/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?*/

#include<bits/stdc++.h>
using namespace std;

// int missingNumber1(vector<int> nums)
// {
// 	int mn;
//     sort(nums.begin(),nums.end());
// 	for(int i=0; i<nums.size(); i++)
// 	{
//         if(nums[0]!=0)
// 		{
// 			mn= 0;
//             break;
// 		}
// 		else if( nums[i+1]!= nums[i]+1 )
// 		{
// 			mn=nums[i]+1;
// 			break;
// 		}
//         else{
//             mn=nums[nums.size() -1] +1;        
//         }
		
// 	}
// 	return mn;
// }

int missingNumber1(vector<int> nums) //O(nlogn)
{
	sort(nums.begin(),nums.end());
	int i;
	for(i=0;i<nums.size();i++)
	{
		if(nums[i]!= i)
			return i;
	}

	return i;
}
int missingNumber2(vector<int> nums) //sum approach  O(n)
{
	int sum=0;   // 0 5 2 1 3  sum= 0 
	for(int i=0;i<nums.size();i++){
		sum=sum+i;							//0 1   -4+2   -4+3   -2+4
		sum=sum-nums[i]	;					//0 -4	-2-2	-1-1	2-3 =-1
	}
	sum=sum+nums.size();								//sum=sum+nums.size()   -1+5=4
	return sum;
}
int main()
{
	int x,n;
	cin>>n;
	vector<int> nums;
	for(int i=0;i<n;i++){
		cin>>x;
		nums.push_back(x);
	}
	cout<<"Missing number: "<<missingNumber1(nums)<<endl;
	cout<<"Missing number: "<<missingNumber2(nums)<<endl;
	return 0;	
}