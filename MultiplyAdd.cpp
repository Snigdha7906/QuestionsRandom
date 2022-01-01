#include<bits/stdc++.h>
using namespace std;	

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n,a,b, p=false;
		stack<int> s;
		s.push(1);
		cin>>n;
		cin>>a;
		cin>>b;
		while(!s.empty()){
			int x=s.top();
			s.pop();

			if(x*a==n || x+b==n){
				cout<<"Yes"<<endl;
				p=true;
				break;
			}
			s.push(x*a);
			s.push(x+b);
		}
		if(p==false) cout<<"False"<<endl;
	}

return 0;
}