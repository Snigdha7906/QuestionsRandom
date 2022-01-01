/*Write a function which returns the LCM of N1 and N2. Print the value returned.

Input Format
Constraints
0 < N1 < 1000000000 0 < N2 < 1000000000

Output Format
Sample Input
4 
6
Sample Output
12
*/

#include<bits/stdc++.h>
using namespace std;

long long gcd(long long n1, long long n2){
	if(n2==0) return n1;
	return gcd(n2, n1%n2);
}
long long lcm(long long n1, long long n2){
	return(n1/gcd(n1,n2))*n2;
}
int main(){
	int n1,n2;
	cin>>n1;
	cin>>n2;
	cout<<lcm(n1,n2);
	return 0;
}