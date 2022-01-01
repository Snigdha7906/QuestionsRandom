/*
Given two strings, write a method to decide if one is a permutation of the
other. (Also called as ANAGRAM)
*/
#include<bits/stdc++.h>
using namespace std;

bool is_perm(string s1, string s2)
{
	if(s1.length()!=s2.length())
		return false;
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	if(s1==s2)
		return true;
	return false;
}

//permuation is words having same character count
//assumption ascii char set
bool is_perm_eff(string s1,string s2)
{
	if(s1.length()!=s2.length())
		return false;
	int count[128]={};
	for(int i=0;i<s1.length();i++)
	{	int val = s1[i];
	 		count[val]++; //count number of occurances of each character of string 1   
	} 
	for(int i=0;i<s2.length();i++)
	{
		int val=s2[i];
		count[val]--;
		if(count[val]<0)
			return false;
	}
	return true;
}
int main()
{
	string a,b;
	cout<<"Enter two strings: \n";
	cin>>a>>b;
	cout<<is_perm(a,b)<<endl; //O(nlogn)
	cout<<is_perm_eff(a,b)<<endl;

}