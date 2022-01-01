#include<iostream>
using namespace std;

int binarySearch(int arr[],int key,int high,int low){
	if(high>=low){
		int middle= (high+low)/2;
		if(key>middle){
			low=middle+1;
			return binarySearch(arr,key,high,low);
		}
		if(key<middle){
			high=middle-1;
			return binarySearch(arr,key,high,low);
		}

		return middle;
	}
    return -1;
}

int main(){
	int n,key,i;
	cin>>n;
	int arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];

	cout<<"Find element: ";
	cin>>key;
	cout<<endl<<"Index: "<<binarySearch(arr,key,n-1,0);

}