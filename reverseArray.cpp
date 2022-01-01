#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>&arr, int start,int end){
	if(start>=end) return;

	swap(arr[start], arr[end]);
	reverseArray(arr, start+1, end-1);
}
void reversestr(string &arr, int start,int end){
	if(start>=end) return;

	swap(arr[start], arr[end]);
	reversestr(arr, start+1, end-1);
}

int maxelm(vector<int>&arr){
	int maxelm=arr[0];
	for(int i=1; i<arr.size(); i++){
		if(arr[i]>maxelm) maxelm=arr[i];
	}
	return maxelm;
}

int main(){
	vector<int> v(5);
	v={1,2,3,4,5};
	for(auto i:v) cout<<i<<" ";
	cout<<endl;
	reverseArray(v, 0, 4);
	for(auto i:v) cout<<i<<" ";
	cout<<endl;
	cout<<maxelm(v);
	cout<<endl;
	string a="hello";
	for(int i=0; i<a.size(); i++) cout<<a[i]<<" "; 
	cout<<endl;
	reversestr(a,0, a.size()-1);
	for(int i=0; i<a.size(); i++) cout<<a[i]<<" ";

	return 0;
}