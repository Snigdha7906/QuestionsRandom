#include<bits/stdc++.h>
using namespace std;	

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n,x;
		int o=0, e=0;
		cin>>n;
		vector<int> v;
		for(int i=0; i<2*n; i++){
			cin>>x;
			if(x%2==0) e++;
			else o++;
		}
		if(o==e) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

return 0;
}