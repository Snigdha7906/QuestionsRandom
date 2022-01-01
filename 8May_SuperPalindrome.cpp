/*Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].
Example 1:
Input: left = "4", right = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
Constraints:

1 <= left.length, right.length <= 18
left and right consist of only digits.
left and right cannot have leading zeros.
left and right represent integers in the range [1, 1018].
left is less than or equal to right.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int n=s.length();

    int left=0, right=n-1;
    while(left<n/2){
        if(s[left]!=s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
/*

works only till 10^8 on leetcode

int superpalindromesInRange(string left, string right) {
    int count=0;
    long long int p=stoi(left), q=stoi(right);

    for(long long int i=p; i<=q; i++){
        long long int root=round(sqrt(i));
        if(i==root*root){

            bool x=isPalindrome(to_string(i));
            bool y=isPalindrome(to_string(root));
            if(x==1 && y==1)
                count++;
        }
    }
    return count;
} */

int superpalindromesInRange(string left, string right) {
    int count=0;
    long long l=stoll(left), r=stoll(right); //stoll() coverts string to long long

    // vector used to store pallindromes
    vector<long long> v;

    // 1 to 9 are already pallindromes, therefore pushing in v
    for(int i=1; i<10; i++)
        v.push_back(i);

    // P= R*R, where R is a pallindrome. P->10^18, thus R->10^9
    //Creating Pallindromes till 10^9
    // palindrome= if even,  num+rev(num)  (10^8) thus num till 10^4
    //palindrome= if odd, num+ '0 to 9 possible digits' +rev(num)  (10^9) adding middle digit manually  thus 10^4   
    //Eg. 423 -> 423324 and (4230324-4239324),  1-> 11 and (101-191) therefore we needed to add 1 to 10 in v before

    for(int i=0; i<=1e4; i++){
        string s1=to_string(i), s2=to_string(i);
        reverse(s2.begin(), s2.end());

        //even
        v.push_back(stoll(s1+s2));
        //odd
        for(int j=0; j<10; j++)
            v.push_back(stoll(s1+ to_string(j)+ s2));
    }

    for(auto i:v){
        if(i>1e9)
            continue;
        //check if sqq of these pallindrome in v are also pallindrome and are in range of [l,r]
        long long num= i*i;  //10^18 

        if(num>=l && num<=r && isPalindrome(to_string(num))){
            count++;
        }
    }
    return count;
} 

int main(){
    string s1,s2;
    cout<<"Enter num 1"<<endl;
    cin>>s1;
    cout<<"Enter num 2"<<endl;
    cin>>s2;

    cout<<"No of super palindromes: "<<superpalindromesInRange(s1,s2);
    return 0;
}

/*
1
100000000000000000
expected output: 70 
*/