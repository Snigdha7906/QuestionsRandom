#include <bits/stdc++.h>
using namespace std;
void pair_demo()
{
	cout<<"PAIR OUTPUT:\n";
	pair<int,int> p={1,2};
		cout<<p.first<<" "<<p.second<<endl;
	pair<int, pair<int, int>> p1 = {1, {3, 4}};
		cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;
	pair<int,int> arr[]={{1,2},{3,4},{5,6}};
		cout<<arr[0].first<<" "<<arr[2].second<<endl;
	pair<int,int> p2;
	p2=make_pair(-1,3);
	cout<<p2.first<<" "<<p2.second<<endl;
}
void vector_demo()
{
	cout<<"VECTOR OUTPUT:\n";
	vector<int> v;
	vector<pair<int,int>> v1;
	vector<int> v2(5); //{0,0,0,0,0}
	vector<int> v3(5,20); //{20,20,20,20,20)}
	vector<int> v4(v3); //{20,20,20,20,20}
	// insert
	v.push_back(10);
	v.push_back(20);
	v.emplace_back(30);
	v.emplace_back(40);

	v1.push_back({3,4});
	v1.emplace_back(5,6);

	vector<int>::iterator it1=v.begin();
	// vector<int>::iterator it2 = v.rbegin();
	vector<int>::iterator it3=v.end();
	// vector<int>::iterator it4=v.rend();

	cout<<*(it1)<<" "<<*(it3)<<" "<<endl;
	it1++; it3--;
	cout<<*(it1)<<" "<<*(it3)<<endl;

	cout<<v[2]<<" "<<v.at(2)<<endl;
	cout<<v.back()<<" "<<v.front()<<endl;

	// ways to print vector
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
		cout<<*(it)<<" ";
		cout<<endl;
	for(auto it=v.begin();it!=v.end();it++)
		cout<<*(it)<<" ";
		cout<<endl;
	for(auto it:v)
		cout<<it<<" ";
		cout<<endl;
	// print in reverse order
	for(auto it=v.rbegin();it!=v.rend();it++)
		cout<<*(it)<<" ";
		cout<<endl;
	//insert
		cout<<"insert\n";
	v.insert(v.begin(),50);
	for(auto it:v) cout<<it<<" "; cout<<endl;

	v.insert(v.begin()+1,2,60);
	for(auto it:v) cout<<it<<" "; cout<<endl;

	v.insert(v.begin()+3,v3.begin(),v3.end());
	for(auto it:v) cout<<it<<" "; cout<<endl;

	// erase
	v.erase(v.begin()+1);
	for(auto it:v) cout<<it<<" "; cout<<endl;

	v.erase(v.begin()+2,v.end()-4);
	for(auto it:v) cout<<it<<" "; cout<<endl;

	//size 
	cout<<v.size()<<endl;
	//sort
	sort(v.begin(),v.end(),greater<int>());
	for(auto it:v) cout<<it<<" "; cout<<endl;
	sort(v.begin(),v.end());
	for(auto it:v) cout<<it<<" "; cout<<endl;
	
	
	v.pop_back();
	for(auto it:v) cout<<it<<" "; cout<<endl;
	v.swap(v3);
	for(auto it:v) cout<<it<<" "; cout<<endl;
	v3.clear();
	cout<<v3.empty()<<endl;
}
void list_demo()
{
	cout<<"LIST OUTPUT:\n";
	list<int> ls;
	ls.push_back(1);
	ls.emplace_back(2);
	ls.push_front(3);
	ls.emplace_front(4);
	for(auto it:ls) cout<<it<<" "; cout<<endl;
	// begin end rbegin rend clear insert size swap same as vector
	// vector is preffered over list
}
void deque_demo()
{
	cout<<"DEQUE OUTPUT:\n";
	deque<int> dq;
	dq.push_back(1);
	dq.emplace_back(2);
	dq.push_front(3);
	dq.emplace_front(4);
	for(auto it:dq) cout<<it<<" "; cout<<endl;
	cout<<dq.back()<<" "<<dq.front()<<endl;
	dq.pop_back();
	dq.pop_front();
	for(auto it:dq) cout<<it<<" "; cout<<endl;
}

void stack_demo()
{
	cout<<"STACK OUTPUT:\n";
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout<<st.top()<<" "<<st.size()<<" "<<st.empty()<<" "<<endl;
	st.pop();
	cout<<st.top()<<" "<<st.size()<<" "<<st.empty()<<" "<<endl;
	stack<int> st1;
	st1.push(1);
	st.swap(st1);
	cout<<st.top()<<" "<<st1.top()<<endl;
}

void queue_demo()
{
	cout<<"QUEUE OUTPUT:\n";
	queue<int> q;
	q.push(1);
	q.push(2); 
	q.emplace(3);
	cout << q.back()<<" "<< q.front()<<endl; 
	q.back() += 5;
	cout << q.back()<<" "<< q.front()<<endl; 
	q.pop(); 
	cout << q.back()<<" "<< q.front()<<endl; 
	cout << q.size()<<" "<< q.empty()<<endl; 

	queue<int> q1;
	q1.push(5);
	q1.push(6); 
	q1.emplace(7);
	cout << q.front()<<" "<< q1.front()<<endl; 
	q.swap(q1);
	cout << q.front()<<" "<< q1.front()<<endl; 
}
void priority_queue_demo()
{
	cout<<"PRIORITY QUEUE OUTPUT"<<endl;
	//by default desc ord
	priority_queue<int> pq;
	//asc order
	priority_queue<int,vector<int>,greater<int>> pq1;

	pq.push(1);
	pq.push(8);
	pq.emplace(5);
	pq.emplace(2);
	pq1.push(1);
	pq1.push(8);
	pq1.emplace(5);
	pq1.emplace(2);
	cout<<pq.top()<<" "<<pq1.top()<<endl;
	pq.pop();
	cout<<pq.top()<<endl;
	cout<<pq.size()<<" "<<pq.empty()<<endl;
	// pq.swap(pq1); to swap two must have same order of priority and type
	// cout<<pq.top()<<" "<<pq1.top()<<endl;
}

void set_demo()
{
	cout<<"SET OUTPUT\n";
	set<int> st;
	st.insert(2);
	st.insert(7);
	st.insert(3);
	st.insert(9);
	st.insert(1);
	st.insert(8);
	st.emplace(4);
	//begin rbegin end rend swap size empty same as vector
	for(auto it:st) cout<<it<<" "; cout<<endl;
	//find
	auto it1=st.find(2);
	auto it4=st.find(8);
	auto it2=st.find(5); //it2points to end index ie 5 as 5 not there in set
	cout<<*it1<<" "<<*it2<<endl;
	//delete
	st.erase(7); //log(n) time

	auto it3=st.find(3);
	st.erase(it3); //constant time

	st.erase(it1,it4); //to delete range
	for(auto it:st) cout<<it<<" "; cout<<endl;
	
	//to check if elm is there 
	//count of elm in set is always 1 as it stores unique elms in sorted order
	if(st.count(3)) cout<<"present "<<endl; 
	else cout<<"not present"<<endl;

	it1=st.lower_bound(8);
	it2=st.upper_bound(8);
	cout<<*it1<<" "<<*it2<<endl;
}
void multiset_demo()
{
	cout<<"MULTISET OUTPUT\n";
	//can store duplicates rest same
	multiset<int> ms;
	ms.insert(2);
	ms.insert(2);
	ms.insert(2);
	ms.insert(2);
	ms.insert(5);
	ms.insert(1);
	for(auto it:ms) cout<<it<<" "; cout<<endl;

	cout<<ms.count(2)<<endl;

	ms.erase(ms.find(2)); //only 1 2 erased
	for(auto it:ms) cout<<it<<" "; cout<<endl;
	ms.erase(2); //all 2 erased
	for(auto it:ms) cout<<it<<" "; cout<<endl;

	// ms.erase(ms.find(1), ms.find(1)+2);
}
void unorderedset_demo()
{
	unordered_set<int> st;
	//lower_bound and upper_bound function does not works, rest all functions are same
	// does not store in sortec order 
	// complexity reduced to O(1)
	// sometimes give wrong answers as collision happens
}

void map_demo()
{

}

void multimap_demo()
{

}

void unorderedmap_demo()
{
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	pair_demo();
	vector_demo();
	list_demo();
	deque_demo();
	stack_demo();
	queue_demo();
	priority_queue_demo();
	set_demo();
	multiset_demo();
	unorderedset_demo();
	return 0;
}