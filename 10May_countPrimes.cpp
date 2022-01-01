/*Count the number of prime numbers less than a non-negative number, n.
  Constraints: 0 <= n <= 5 * 10^6
  Input: n = 10
  Output: 4
*/

#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
        
        if(n==0 || n==1) return 0;
        vector<bool> v(n,true);
        v[0]=false; v[1]=false;

        for(int i=2; i*i<n; i++){       //if n is divisible by some number p, then n = p × q and since p ≤ q, we                                               could derive that p ≤ √n.
            if(v[i]==false) continue;   //if prime continue to be true
            
            for(int j=i*i; j<n; j=j+i)  // start with i*i  , increment with i
                v[j]=false;             //mark multiples of that prime <n as false
        }
                
        int count=0;
        for(auto i:v)
            if(i) count++;
        
        return count;
    }

int main(){
	int n;
	cout<<"Enter n"<<endl;
	cin>>n;
	cout<<"No of primes: "<<countPrimes(n)<<endl;
	return 0;
}

/*
5000000
Expected Output: 348513
*/