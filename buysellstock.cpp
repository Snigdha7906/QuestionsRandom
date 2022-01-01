#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > stockBuySell(vector<int> A, int n){
       vector<vector<int>> ans;    
       int i=0;
       while(i<n-1){
           
           //local minima
           while((i<n-1) && A[i+1]>=A[i])
               i++;
           int buy=i;
           
           if(i==n-1) break;
           
           //local maxima
           while(i<=n-1 && A[i]>=A[i-1])
               i++;
           int sell=i-1;
           vector<int> v;
           v.push_back(buy);
           v.push_back(sell);
           ans.push_back(v);
       }
       return ans;
};

int main(){
  vector<int> a;
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
  int x;
  cin>>x;
  a.push_back(x);
  }

  vector<vector<int>> ans;
  ans=stockBuySell(a,a.size());
  for(int i=0; i<ans.size();i++){
  for(int j=0; j<ans[0].size(); j++)
    cout<<ans[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}

/*
7
100 180 260 310 40 535 695
*/