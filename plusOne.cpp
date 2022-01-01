/*Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

eg [1,2.3] is 123 and it becomes [1,2,4]
*/


#include<bits/stdc++.h>
using namespace std;


vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=0, num=0;
        while(i<n)
        { 
       		num=num+ digits[i]*pow(10,n-1-i);
       		i++;
        }
        num++;
        digits.clear();
        i=0; 
        while(num>0){ 
            digits.insert(digits.begin(),num%10);
            num=num/10;
            i++;
        }
        
        return digits;
    }

int main(){
	int n,x;
	cin>>n;

	vector<int> v,ans;
	for(int i=0; i<n; i++){
			cin>>x;
			v.push_back(x);
	}
	ans=plusOne(v);
	cout<<endl;
	for(int i=0;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}