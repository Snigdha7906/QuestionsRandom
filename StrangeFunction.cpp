#include<bits/stdc++.h>
using namespace std;	

long calcfirst(long x){
	for(long i=2; i<=x/2+1; i++)
		if(x%i!=0)
			return i;
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n;
		cin>>n;
		long f[n+1];
		f[1]=2;
		f[2]=3+f[1];
		for(long i=3; i<=n; i++){
			f[i]=(f[i-1]%1000000007+ calcfirst(i%1000000007))%1000000007;
		}
		cout<<f[n]<<endl;
	}

return 0;
}