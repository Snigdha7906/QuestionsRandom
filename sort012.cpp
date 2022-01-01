#include <bits/stdc++.h>
using namespace std;

void sort012(int *a, int n)
{
    int c_0=0, c_1=0, c_2=0;
    for(int i=0; i<n; i++){
        if(a[i]==0) c_0++;
        if(a[i]==1) c_1++;
        if(a[i]==2) c_2++;
    }
    
    for(int i=0;i<c_0; i++)
        a[i]=0;
    
    for(int i=c_0; i<c_0+c_1; i++)
        a[i]=1;
        
    for(int i=c_0+c_1; i<c_0+c_1+c_2; i++)
        a[i]=2;
    
}

int main(){
    int v[]={2, 1, 1, 0};
    sort012(v, 4);
    for (auto i:v)
    {
        cout<<i;
    }
}