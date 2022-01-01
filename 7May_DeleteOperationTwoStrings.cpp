/*Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

Example  Input: word1 = "sea", word2 = "eat"    Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
*/

#include<bits/stdc++.h>
using namespace std;


int lcsm(string s1, string s2, int n, int m){
        
        int arr[n+1][m+1];
        memset(arr, 0, sizeof(arr)); 
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(s1[i-1]==s2[j-1])    
                    arr[i][j]= arr[i-1][j-1]+1;
                else
                    arr[i][j]= max(arr[i-1][j], arr[i][j-1]);
            }
        } 

        return arr[n][m];
    }
    
    int minDistance(string word1, string word2) {
       
       int n=word1.size(), m=word2.size();
        
       return n+m -(2* lcsm(word1, word2, n, m));
    }
    /* If you clearly observe that we are deleting only those elements from the both strings which are not part of its lcsm(longest common susequence).
	in the given example lcs is "ea";
	hence from both the string we delete its lcs and rest is required answer
	int ans = word1.length - lcs(word1 , word2) + word2.length - lcs(word1 , word2);*/

int main(){
	string s1,s2;
	cout<<"Enter word 1"<<endl;
	cin>>s1;
	cout<<"Enter word 2"<<endl;
	cin>>s2;

	cout<<"Min steps: "<<minDistance(s1,s2);
	return 0;
}

/*
leetcode
etco
expected output: 4  (8+4 -2(4))
*/