#include<iostream>
using namespace std;

int main(){

	int n,key,i;
	cin>>n;

	int arr[n]={0};
	for (i = 0; i < n; i++)
	{
		cin>>arr[i];
	}

	cout<<"Enter elm you want to search: ";
	cin>>key;


	for(i=0; i<n;i++){
		if(arr[i]==key){
			cout<<"Found at :"<<i;
			break;
		}
	}
	if(i==n){
		cout<<"Elm not found";
	}
	return 0;
}