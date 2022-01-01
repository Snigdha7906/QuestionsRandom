#include<iostream>
#include<algorithm>
using namespace std;

void twoSum(int arr[],int n, int target){
	int i=0;
	int j= n-1;

	while(i<j){

		int currentsum=arr[i]+arr[j];
		if(currentsum<target){
			i++;
		}
		if(currentsum>target){
			j--;
		}
		if(currentsum==target){
			cout<<"Pair: "<<arr[i]<<" "<<arr[j]<<endl;
			i++;
			j--;
		}
	}
}
//O(n)
int main(){
	int n,target;
	cin>>n;
	int arr[n]={0};
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	cout<<"Enter target: ";
	cin>>target;
	twoSum(arr,n,target);
   
	return 0;
}