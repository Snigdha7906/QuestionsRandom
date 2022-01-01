#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(){
		this->data=INT_MIN;
		this->next=NULL;
	}
	Node(int x){
		this->data=x;
		this->next=NULL;
	}
};

class Queue{
	Node* head, *tail;
	int sz;
public:
	Queue(){
		this->head=NULL;
		this->tail=NULL;
		this->sz=0;
	}

	void enqueue(int x);
	int dequeue();
	int front();
	bool isEmpty();
	int size();
};

// exit <- 10->20->30->NULL  <- entry

void Queue::enqueue(int x){
	Node* newnode= new Node(x);
	if(head==NULL){
		head=newnode;
		tail=newnode;
	}
	else{
		tail->next=newnode;
		tail=newnode;
	}
	sz++;
}

int Queue::dequeue(){
	if(head==NULL){
		cout<<"Empty queue";
		return INT_MIN;
	}
	
	Node* temp=head;
	head=head->next;
	int x= temp->data;
	delete temp;
	sz--;
	return x;
}

int Queue::front(){
	if(head==NULL){
		cout<<"Empty queue";
		return INT_MIN;
	}
	return head->data;	
}

int Queue::size(){
	return sz;
}

bool Queue::isEmpty(){
	return head==NULL;
}

int main(){
	Queue q;
	while(1){
		int ch;
		cout<<"CHOICE: 1)Push 2)Pop 3)Top 4)isEmpty 5)Size 6)Break:"<<endl;
		cin>>ch;
		if(ch==1)		{int x; cout<<"Element:"; cin>>x; q.enqueue(x);}
		else if(ch==2)	cout<<q.dequeue()<<endl;
		else if(ch==3)	cout<<q.front()<<endl;
		else if(ch==4)  cout<<q.isEmpty()<<endl;
		else if(ch==5)	cout<<q.size()<<endl;
		else if(ch==6)	break;
		else			cout<<"Invalid choice"<<endl;	
	}
	return 0;
}

/*
queue <dtype> name;
name.push(int x) //void
name.pop()  //void return type
name.front() //int
name.size() //int
name.empty() //bool
*/