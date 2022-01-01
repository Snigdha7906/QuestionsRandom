#include<bits/stdc++.h>
//return indexes of the two elements whoose sum is equal to target
using namespace std;
vector<int> TwoSum(vector<int> arr,int target){
	vector<int> answer;
	unordered_map<int,int> hshmp;
	//a+b=target	target-b=a
	for(int i=0;i<arr.size();i++){
		if(hshmp.find(target-arr[i])!= hshmp.end()){ //found in hashmap
			answer.push_back(hshmp[target-arr[i]]);
			answer.push_back(i);
		}
		hshmp[arr[i]]= i;
	}
}

int main(){
	vector<int> v,ans;
	int n,target;
	cin>>n;

	for (int i = 1; i <= n; i++) 
        v.push_back(i); 
    cin>>target;
    ans=TwoSum(v,target);
    return 0;
}