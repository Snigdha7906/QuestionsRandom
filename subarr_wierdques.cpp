#include<bits/stdc++.h>
using namespace std;

int solve(int N, long long K, vector<int>A){
	int ans=0;
	for(int i=0; i<N; i++){
		long long p=0;
		for(int j=i+1; j<N; j++){
			if(p<=K){
				if(A[i]==A[j]){
					ans++;
					p++;
				}
			}
			else break;

		}
	}

	return ans;
}

int main(){
	
	vector<int> v;
	int n=5;
	long long k=2;

	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	

	cout<<solve(n,k,v);
}