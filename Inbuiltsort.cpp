#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
	return a>b;
}
int main(){

	int n,i;
	cin>>n;
	int arr[n]={0};
	for(i=0;i<n;i++)
		cin>>arr[i];

	sort(arr,arr+n);

	for(i=0;i<n;i++)
		cout<<arr[i];

	cout<<endl;
	
	sort(arr,arr+n,compare);
	for(i=0;i<n;i++)
		cout<<arr[i];

	return 0;
}