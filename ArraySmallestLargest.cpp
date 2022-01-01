#include<iostream>
#include<climits>
using namespace std;

int main(){
	
	int n,key,i;
	cin>>n;

	int arr[n] = {0};
	for(i=0; i<n; i++)
		cin>>arr[i];

	int largest=INT_MIN;
	int smallest=INT_MAX;

	for(i=0;i<n;i++){
		// if(arr[i]>largest)
		// 	largest=arr[i];
		// if(arr[i]<smallest)
		// 	smallest=arr[i];
		largest = max(largest,arr[i]);
		smallest=min(smallest,arr[i]);
	}
	cout<<"largest: "<< largest<<" smallest: "<<smallest;
	return 0;
}