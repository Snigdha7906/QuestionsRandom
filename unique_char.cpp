/*
Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures? 
*/
#include<bits/stdc++.h>
using namespace std;
bool is_unique(string str){
	if(str.length()>128)
		return false;

	vector<bool> chr(128);
	for(int i=str.length()-1;i>=0;i--)
	{
		int val=str[i];
		if(chr[val])
			return false;
		chr[val]=true;
	}
	return true;
}

bool is_unique_bitvector(string str)
{
	unsigned int checker=0;// 32 bits of space, 0-26 bits for 26 alphabets (smallcaps only)
	for (int i = str.length()-1; i >=0; i--)
	{
		//str[i]-'a' is 0 to 25 a-z
		int val=1<<(str[i]-'a'); //the bit at str[i]-'a' set to 1
		if(checker&val) //if bit already set in checker, it return true (1 and 1=1)
			return false;
		checker|=val; //bit at checker updated to 1 (0 or 1=1)
	}
	return true;
}

bool is_unique_noDs(string str)
{
	for(int i=0;i<str.length()-1;i++)
	{
		for(int j=i+1;j<str.length();j++)
		{
			if(str[i]==str[j])
				return false;
		}
	}
	return true;
}



int main() 
{
	string s;
	cout<<"Enter a string: ";
	cin>>s;
	cout<<endl<<is_unique(s)<<" "<<is_unique(s)<<"\n"; //O(1)
	cout<<is_unique_bitvector(s)<<" "<<is_unique_bitvector(s)<<"\n"; //O(1)
	cout<<is_unique_noDs(s)<<" "<<is_unique_noDs(s); //O(n^2)
	return 0;
}