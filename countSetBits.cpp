/*count number of 1s in binary representation of an integer

Input Format
Input N = Number of Test Cases, followed by N numbers*/

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n){
	int count;
	while(n){
		count+= (n&1);
		n=n>>1;
	}
	return count;
}

int main(){
	int T,x;
	cin>>T;
	for (int i = 0; i < T; ++i){
		cin>>x;
		cout<<countSetBits(x)<<endl;
	}
	return 0;
}
/*
3 5 4 15
expected output:
2 1 4
*/