#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &nums) {
    sort(nums.begin(), nums.end());
   
    int ans=1, curr=1;
    for(int i=1; i<nums.size(); i++){
        if(nums[i]==nums[i-1])
            continue;
        if(nums[i]==nums[i-1]+1)
            curr++;
        else
            curr=1;
        ans=max(ans,curr);
    }
    return ans;
}

int lengthOfLongestConsecutiveSequencehsmap(vector<int> nums){
    
}
int main(){
    vector<int> v;
    v.push_back(20);
    v.push_back(33);
    v.push_back(35);
    v.push_back(11);
    v.push_back(34);
    cout<<lengthOfLongestConsecutiveSequence(v)<<endl;
    cout<<lengthOfLongestConsecutiveSequencehsmap(v);
}