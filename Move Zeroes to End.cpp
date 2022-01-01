#include<bits/stdc++.h>
using namespace std;

void move_zeroes(vector<int>& nums){
     
    int count=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]!=0){
            nums[count]=nums[i];
        	count++;
        }
    }
    for(int i=count; i<nums.size(); i++){
            nums[i]=0;
    }
}
int main() {
	vector<int> v;
    int n,x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }
    move_zeroes(v);
    for(auto i:v)
        cout<<i<<" ";
	return 0;
}