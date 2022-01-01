#include<bits/stdc++.h>
using namespace std;
bool istriplet(int arr[], int n, int X){
	for(int i=0; i<n-2; i++){
		unordered_set<int> set;
		for(int j=i+1; j<n; j++){
			int x=X-arr[i]-arr[j];
			if(set.find(x)!=set.end())
				return true;
			set.insert(arr[j]);
		}
	}
	return false;
}

vector<vector<int>> istriplet2(int arr[], int n, int X){
	vector<vector<int>> ans;
	sort(arr,arr+n);
	for(int i=0; i<n-2; i++){
		int l=i+1, r=n-1;
		while(l<r){
			int x=arr[i]+arr[l]+arr[r];
			if(x==X){
				ans.push_back({arr[i], arr[l], arr[r]});
				r--;
				l++;
			}
			else if(x<X)
				l++;
			else
				r--;
		}
	}

	return ans;
}
int main(){
	int arr[]={1, 2, 4, 3, 6, 5};
	cout<<istriplet(arr, 6, 10)<<endl;
	vector<vector<int> > A;
	A=istriplet2(arr, 6, 10);
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < A[0].size(); ++j)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}