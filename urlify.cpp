/*
Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. 
*/
#include<bits/stdc++.h>
using namespace std;

const int MAX=100;

void urlify(char *str,int length)
{
	int count=0;
	for(int i=0;i<length;i++) //count no of spaces
		if(str[i]==' ')
			count++;


	int new_len=length+count*2; //new length is prev len + 2 times no of spaces as space needed for 2 and 0
	if(new_len>MAX) cout<<"Not enough space";
	else{
			int index=new_len-1;             //index is newlen -1
			for(int i=length-1;i>=0;i--)     //starting from end of string
			{                              //if space then at new index we put %20 otherwise same char of string
				if(str[i]!=' ')
					str[index--]=str[i];
				else
				{
					str[index--]='0';
					str[index--]='2';
					str[index--]='%';
				}
			}
		}	
}
int count(char *str)
{
	int count=0;
	for(int i=0;str[i]!='\0';i++)
		count++;
	return count;
}

int main()
{
	char s[MAX];
	cin.getline(s,MAX);
	cout<<s<<endl;
	urlify(s,count(s));
	cout<<s;
}