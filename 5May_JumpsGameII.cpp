/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Input: nums = [2,3,1,1,4]
Output: 2

Input: nums = [2,3,0,1,4]
Output: 2

*/
#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1 || nums[0]==0)  return 0;
        
        int curr_end= nums[0] , farthest=nums[0];
        int jumps=1;
        
        for(int i=1; i<n; i++){
            if(i==n-1)
                return jumps;
            
            farthest=max(farthest, i+ nums[i]);  
            
            if(i==curr_end){
                jumps++;
                curr_end=farthest;
            }
        }
        return jumps;
    }
/*
    greedy approach
    // 2,3,1,1,4
           f
       curr_end=nums[0]=2  farthest=nums[0]=2 i=0
       i!= 4    farthest= max(farthest, i+nums[i])= max(2, 0+2) ie max it can jump
       if i== curr_end,  jump++ curr_end=farthest  all jumps considered, make the jump, current end becomes farthest
*/

int main(){
    int n,x;
    
    cout<<"Enter no of elements"<<endl;
    cin>>n;
    cout<<"Enter max jumps possible at each element:"<<endl;
    vector<int> v;

    for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }

    cout<<"Minimum jumps to reach end is : "<< jump(v);
}

/*
    5
    2 3 1 1 4
    expected output: 2 (from index 0 to index 1, from index 1 to index 4)
*/