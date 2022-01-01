/*
There are several cards arranged in a row, and each card has an associated number of points The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.*/

#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardpoints, int k) {

//          0 1 2 3 4 5 6   n=7-1=6    left=0  right=6-3=3
//         [1,2,3,4,5,6,1]  k = 3
//                l     r  
        int n=cardpoints.size()-1;
        int left=0, right=n-k;      //window initialise
        
        int total=accumulate(cardpoints.begin(), cardpoints.end(),0);
        int windowsum= accumulate(cardpoints.begin(), cardpoints.begin()+ (right+1), 0);
        
        // int total=0;
        // for(int i=0; i<=n; i++){
        //     total+=cardpoints[i];
        // }
        
        // int sum=0;
        // for(int i=left; i<=right; i++){
        //     sum+=cardpoints[i];
        // }
        int minsum=windowsum;         //to select k elem window sum, find min n-k window sum
        
        while(right<n){ 
            
            left++; right++;                //slide the window
            
            windowsum=windowsum- cardpoints[left-1];    //remove prev elm from sum
            windowsum=windowsum+ cardpoints[right];     //add added elm to sum
                
            minsum=minsum<windowsum?minsum:windowsum;
        }
        
        return total-minsum;
    }

    int main(){
        int n,x;
        vector<int> v;
        cout<<"Size: "<<endl;
        cin>>n;
        cout<<"Card Points: "<<endl;
        for(int i=0; i<n; i++){
            cin>>x;
            v.push_back(x);
        }
        cout<<"k: "<<endl;
        cin>>x;
        cout<<"Max score is: "<<maxScore(v, x);
        return 0;
    }

    /*
    7
    1 2 3 4 5 6 1
    3
    */