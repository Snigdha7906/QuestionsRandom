#include<iostream>
using namespace std;

int KadanesAlgoMaxSum(int arr[],int n){
	int currentsum=0;
	int maxsum=0;

	for(int i=0;i<n;i++){
		currentsum+=arr[i];

		if(currentsum < 0)
			currentsum=0;
		if(currentsum > maxsum)
			maxsum = currentsum; 
		cout<<"currentsum: "<<currentsum<<" maxsum: "<<maxsum<<endl;
	}
	return maxsum;
}

int main(){

	int n;
	cin>>n;
	int arr[n]={0};
	for (int i = 0; i < n; ++i)
		cin>>arr[i];

	cout<<"maxsum is : "<<KadanesAlgoMaxSum(arr,n);
	return 0;
}