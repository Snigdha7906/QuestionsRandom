#include<bits/stdc++.h>
using namespace std;
// Q.Given a positive integer N, print count of set bits in it. eg.6 ie110 ans->2
int count_set_bits1( int n)
{
	if (n==0)
		return 0;
	else
		return 1+ count_set_bits1(n&(n-1));
}

int count_set_bits2( int n)
{
	int count=0;

	while(n){
		count= count+ n&1;
		n=n>>1;
	}
}

void sortby_no_of_sortbits(vector<int>& arr){
	vector<vector<int>> count(32);
	//max no of setbits can be 31. so rows represent no of setbits, 
	//and vector at row i represent arr elms with i no of setbits 
	for(int i=0; i<arr.size();i++){
		int x=count_set_bits2(arr[i]);
		count[x].push_back(arr[i]);
	}
	int n=0; 

	for(int i=31; i>=0; i--){					//elms with higher no of setbits come first,
		for(int j=0; j<count[i].size(); j++){   //if same no of setbits come in original order in arr
			arr[n]=count[i][j];
			n++;
		}
	}
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
	#endif
    int n;
    cin>>n;	
    cout<<count_set_bits1(n);
return 0;
}