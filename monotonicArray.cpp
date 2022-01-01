/*An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.*/

#include<bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int>& A) {
    bool isMonoInc=true;
    bool isMonoDec=true;
    
    for(int i=0; i<A.size()-1; i++)
    {
    	if(A[i]>A[i+1]) //A[i] <= A[j] for inc, therefore false if A[i]>A[i+1]
    	{
    		isMonoInc= false;
    		break;
    	}    		
    } 

    for(int i=0; i<A.size()-1; i++)
    {
    	if(A[i]<A[i=1]) //A[i] >= A[j] for dec, therefore false if A[i]<A[i+1]
    	{
    		isMonoDec=false;
    		break;
    	}
    }
    return isMonoInc||isMonoDec;
}

int main(){
	int n,x;
	cin>>n;
	vector<int> v;
	for(int i=0; i<n; i++)
	{	
		cin>>x;
		v.push_back(x);
	}
	cout<<isMonotonic(v);
	return 0;
}