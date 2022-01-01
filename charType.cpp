/*Take the following as input.

A character (ch) Write a function that returns ‘U’, if it is uppercase; ‘L’ if it is lowercase and ‘I’ otherwise. Print the value returned.*/

#include<bits/stdc++.h>
using namespace std;

char charTypeI(char ch){
	if(ch>=65 && ch<=90) return 'U';
	else if(ch>=97 && ch<=122) return 'L';
	else return 'I';
}

char charTypeII(char ch){
	if(isupper(ch)) return 'U';
	else if(islower(ch)) return 'L';
	else return 'I';
}

char charTypeIII(char ch){
	if(ch>='A' && ch<='Z') return 'U';
	else if(ch>='a' && ch<='z') return 'L';
	else return 'I';
}
int main() {
	char ch;
	cin>>ch;
	cout<<charTypeI(ch)<<endl;
	cout<<charTypeII(ch)<<endl;
	cout<<charTypeIII(ch)<<endl;

	return 0;
}