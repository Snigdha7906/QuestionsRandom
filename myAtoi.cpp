#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
        string s1="";

       for(auto c:s){
           if(c==' '){
               if(s1.size()==0) continue;
               else break;
           }
           else{
               if(c=='+'|| c=='-'){
                   if(s1.size()==0) s1+=c;
                   else break;
               }
               else if(c>='0' && c<='9') s1+=c;
               else break;
               }
       }
        int sign=1;
        if(s1[0]=='-')  sign=-1;
       
        int start=0;
        while(!(s1[start]>='0' && s1[start]<='9') || start==s.size())
            start++;
        if(start==s.size()) return 0;
        
         long long int num=0;
        for(int i=start; i<s1.size(); i++){
            num=num*10+ (s1[i]-'0');
            if(sign==-1 && num>INT_MAX) return INT_MIN;
            if(sign==1 && num>INT_MAX ) return INT_MAX;
        }
        return sign*num;
    }

    int main(){
      string s;
      getline(cin,s);
      cout<<myAtoi(s)<<endl;

    }
/*"42"
"   -42"
"4193 with words"
"words and 987"
"-91283472332"*/
