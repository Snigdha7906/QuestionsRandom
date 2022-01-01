#include<bits/stdc++.h>
using namespace std;

//A trailing zero is always produced by prime factors 2 and 5. count the number of 5s and 2s
// number of 2s in prime factors is always more than or equal to the number of 5s.count 5s in prime factors of n
//Trailing 0s in n! = Count of 5s in prime factors of n! = floor(n/5) + floor(n/25) + floor(n/125) + ....
//28!= floor(28/5)+floor(28/25) ; 130!=floor(130/5)+ floor(130/25)+ floor(130/125)

int trailingZeroes(int n){
	int count=0;

	for(int i=5; i<=n; i=i*5){
		count+=n/i;
	}
	return count;
}

int main(){
	int n;
	cin>>n;
	cout<<trailingZeroes(n);
}