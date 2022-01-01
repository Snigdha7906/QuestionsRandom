#include "bits/stdc++.h"
using namespace std;

int majority_elm(int arr[], int n){
	unordered_map<int,int> mp;
	for (int i = 0; i < n; ++i)
	{
		if (mp.find(arr[i])!=mp.end())
		{
			mp[arr[i]]++;
		}
		else
			mp[arr[i]]=1;
	}

	for (auto i:mp)
	{
		if(i.second>n/2)
			return i.first;
	}
	return -1;
	
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
    	cin>>arr[i];
    }
    cout<<"majority_elment is: "<<majority_elm(arr,n);

return 0;
}