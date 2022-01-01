#include<iostream>
using namespace std;

int MaxSumofSubarray(int arr[], int n){
	int maxsum=0;
	int left=-1, right=-1;
	int csum[n]={0};

    //cumulative sum calc
	csum[0]=arr[0];
	for(int i=1;i<n;i++)
		csum[i] =csum[i-1] + arr[i];

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum=0;
			if(i==0)
				sum=csum[j];
			else
				sum=csum[j]-csum[i-1];

			if(sum>maxsum){
				maxsum=sum;
				left=i;
				right=j;
			}
		}
	}
	cout<<"Subarray: ";
	for (int i = left; i <=right; ++i)
		cout<<" "<<arr[i];

	return maxsum;
}

int main(){

	int n;
	cin>>n;
	int arr[n]={0};

	for(int i=0;i<n;i++)
		cin>>arr[i];
	int maxsum=MaxSumofSubarray(arr,n);
	cout<<endl<<"maxsum is :"<<maxsum;
	return 0;
}