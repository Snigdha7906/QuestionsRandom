#include<iostream>
using namespace std;
#include<climits>

int maxSumSubsequence(int arr[], int n){

	int maxsum=INT_MIN;
	int left=-1, right=-1;

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum=0;
			for(int k=i;k<=j;k++){
				sum+=arr[k];
			}
			if(sum>maxsum){
				maxsum=sum;
				left=i;
				right=j;
			}
		}
	}

	cout<<" Subarray: ";
	for(int k=left;k<=right;k++)
		cout<<" "<<arr[k];
	return maxsum;
}

int main(){

	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin>>arr[i];

	int maxsum=maxSumSubsequence(arr,n);
	
	cout<<endl<<"Max Sum is : "<<maxsum;
	return 0;
}