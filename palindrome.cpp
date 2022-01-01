#include<iostream>
#include<cstring>

using namespace std;

bool checkPalindrome(char str[]){
	int n;

	// for(n=0;str[n]!='\0';++n){}
	n=strlen(str);
	
	int i=0;
	int j=n-1;

	while(i!=n/2){
		if(str[i]!=str[j])
			return false;
		i++;
		j--;
	}

	return true;
}

int main(){
	
	char str[100];
	cin.getline(str,100);

	bool p=checkPalindrome(str);
	if(p==true)
		cout<<str<<" is a palindrome";
	else
		cout<<str<<" is not a palindrome";

	return 0;
}