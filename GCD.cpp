#include<bits/stdc++.h>
using namespace std;

long long gcd(long long n1, long long n2){  //O(log(max(a,b)))
	if(n2==0) return n1;
	return gcd(n2, n1%n2);
}

int main(){
	int n1,n2;
	cin>>n1;
	cin>>n2;
	cout<<gcd(n1,n2);
	return 0;
}
