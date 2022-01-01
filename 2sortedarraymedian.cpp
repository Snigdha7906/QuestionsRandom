#include<bits/stdc++.h>
using namespace std;

double med2sortedArray(vector<int>& v1,vector<int>& v2){
	int m=v1.size();
	int n= v2.size();
	double median;

	for(int i=0;i<n;i++){
		v1.push_back(v2[i]);
	}
	sort(v1.begin(),v1.end());

	int size=n+m;

	if(size%2!=0)
		median=v1[size/2];
	else
		median=(v1[(size-1)/2]+v1[size/2])/2.0;

	return median;
}

int main(){
	int m,n,x;
	cout<<"Size: ";
	cin>>m;
	cin>>n;
	vector<int> v1,v2;
	cout<<"\nElms: ";
	for(int i=1;i<=m;i++){
		cin>>x;
		v1.push_back(x);
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		v2.push_back(x);
	}

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	cout<<"\nMedian of joined array: "<<med2sortedArray(v1,v2);
	return 0;
}