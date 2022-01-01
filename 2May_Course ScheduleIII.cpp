/*There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

You will start on the 1st day and you cannot take two or more courses simultaneously.

Return the maximum number of courses that you can take.

Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

static bool cmp(vector<int>&a, vector<int>&b) {
	return a[1]<b[1];
}

int scheduleCourse(vector<vector<int>> courses) {
	int time=0;
	sort(courses.begin(),courses.end(),cmp);

	priority_queue<int> pq;
	for(int i=0; i<courses.size(); i++){

		time+=courses[i][0];
		pq.push(courses[i][0]);
		cout<<
		if(time>courses[i][1]){
			time-=pq.top();
			pq.pop(); 
		}
	}

	return pq.size();
}

int main(){
	int n,x,y;
	cout<<"Enter no of courses:"<<endl;
	cin>>n;
	cout<<"Enter duration, lastdate:"<<endl;
	vector<vector<int>> v1;

	for(int i=0; i<n; i++){
		vector<int> v;
		cin>>x>>y;
		v.push_back(x);
		v.push_back(y);
		v1.push_back(v);
	}
	cout<<"Max courses: "<<scheduleCourse(v1);
}

/*
3

5 5
4 6
2 6

expected: 2
*/