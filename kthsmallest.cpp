#include <bits/stdc++.h>
using namespace std;

int kthsmallest(vector<int> v,int k){    //O(logn)
	sort(v.begin(),v.begin()+k);
	return v[k-1];
}

int kthsmallestopt(vector<int> v; int k){

}

int main(){
	vector<int> v(5);
	v={1,2,3,4,5};
	cout<<kthsmallest(v, 3);
}