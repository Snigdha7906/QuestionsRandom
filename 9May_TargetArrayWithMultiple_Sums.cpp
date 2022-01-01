/*Given an array of integers target. From a starting array, A consisting of all 1's, you may perform the following procedure :

let x be the sum of all elements currently in your array.
choose index i, such that 0 <= i < target.size and set the value of A at index i to x.
You may repeat this procedure as many times as needed.
Return True if it is possible to construct the target array from A otherwise return False.

Example 1:
Input: target = [9,3,5]
Output: true
Explanation: Start with [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
*/
#include<bits/stdc++.h>
using namespace std;

    
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq; //stores elements in decreasing order
        unsigned int sum=0;
        
        for(auto i:target){
            sum+=i;
            pq.push(i);
        }
        
        while(pq.top() != 1){   // till largest elm is not 1 as if largest value in pq is a 1, then all values in pq                                    are 1s and we should return true.
            int x=pq.top();   //largest no
            pq.pop();         // we should remove the largest value  
            sum=sum-x;        //sum is replacement val 
            
            if(x<=sum || sum<1) //if we insert a number less than 1 into pq return false
                return false;
            
            x=x%sum;  //compute its replacement's value
            sum=sum+x; //new sum with replacement value
            pq.push(x); //reinsert that replacement back into pq
        }
        
        /*Take, for example, target = [3,5,33]. Normally, we'd remove the 33 and compute its replacement to be 25, then from 25 to 17, then 17 to 9, then finally 9 to 1. Each time, we're removing the sum of all the remaining values (3 + 5 = 8) from the current number. In any valid target array, as we noted at the very beginning, the max value must be larger than the sum of the remaining elements, since it came from that sum plus the value that was replaced.

That means that we should be able to remove the remaining sum (8) from our current max value (33) as many times as we possibly can, since only the remainder will bring us below that sum. This we can achieve quite easily with the mod operator which will result in our replacement value (33 % 8 = 1) without the need to iterate through every step.
        */
        return true;
    }

int main(){
	int n,x;
	vector<int> v;
	cout<<"Enter size"<<endl;
	cin>>n;
	cout<<"Enter elements"<<endl;

	for(int i=0;i<n; i++){
		cin>>x;
		v.push_back(x);
	}
	cout<<isPossible(v);
	return 0;
}

/*
3
3 5 33
expected output: true
*/    