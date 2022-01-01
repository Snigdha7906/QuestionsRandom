/*Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true*/

#include<bits/stdc++.h>
using namespace std;


bool isAnagram1(string s, string t){
	if(s.length()!=t.length())
		return false;

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	if(s!=t)
		return false;
	else
		return true;
}

bool isAnagram2(string s, string t){
	if(s.length()!=t.length())
		return false;

	vector<int> count(128, 0);

	for(int i=0; i<s.length(); i++){
		count[s[i]]++;
		count[t[i]]--;
	}

	for (int i = 0; i < count.size(); ++i){
		if (count[i]!=0)
			return false;
	}

	return true;
}

int main(){
	
	string s,t;
	getline(cin,s);
	getline(cin,t);
	cout<< isAnagram1(s,t)<<endl<<isAnagram2(s,t);
	return 0;
}