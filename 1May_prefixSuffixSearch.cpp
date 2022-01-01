/*Design a special dictionary which has some words and allows you to search the words in it by a prefix and a suffix.

Implement

WordFilter(string[] words) Initializes the words in the dictionary

f(string prefix, string suffix) Returns the index of the word in the dictionary which has the prefix prefix and the suffix suffix. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.

Eg.
words:["apple"] 
pre, suff: "a", "e"
output: 0 (word at index 0 has prefix = "a" and suffix = 'e")
*/


#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> hshmp;
    
void WordFilter(vector<string>& words) {
        
        int n=words.size();
        
        for(int i=0; i<n; i++){
            string word=words[i];
            int sz= word.size();
            
            for(int p=1; p<=sz; p++){
                string prefix= word.substr(0,p);
                
                for(int s=0; s<sz; s++){
                    string sufix= word.substr(s,sz);
                    hshmp[prefix+"#"+sufix]=i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return hshmp[prefix+"#"+ suffix]; 
    }

    int main(){
        int n;

        vector<string> words;
        cout<<"Enter no of words:"<<endl;
        cin>>n;
        cout<<"Enter words:"<<endl;
        for(int i=0; i<n; i++){
            string s;
            cin>>s;
            words.push_back(s);
            cout<<words[i]<<endl;
        }
        WordFilter(words);
        cout<<"Enter no of queries"<<endl;
        cin>>n;
        cout<<"Enter prefix, suffix"<<endl;
        for(int i=0; i<n; i++){
            string p,s;
            cin>>p;
            cin>>s;
            cout<<"Largest index at"<<f(p,s)<<endl;
        }

        return 0;
    }
/*
    Test case:
10

cabaabaaaa ccbcababac bacaabccba bcbbcbacaa abcaccbcaa accabaccaa cabcbbbcca ababccabcb caccbbcbab bccbacbcba

10
bccbacbcba a
ab abcaccbcaa
a aa 
cabaaba abaaaa
cacc accbbcbab
ccbcab bac
bac cba
ac accabaccaa
bcbb aa
ccbca cbcababac

Expected Output:
[9,4,5,0,8,1,2,5,3,1]
*/