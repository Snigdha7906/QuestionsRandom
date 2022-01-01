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
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
};

class Stack{
	Node* head;
	int sz;
	public:
	Stack(){
		this->head=NULL;
		this->sz=0;
	}
	void push(int x);
	int pop();
	int top();
	bool isEmpty();
	int size();
};

void Stack::push(int x){
	Node* newnode= new Node(x);
	newnode->next=head;
	head=newnode;
	sz++;
}

int Stack::pop(){
	if(head==NULL){
		cout<<"Underflow ";
		return INT_MIN;
	}
	int x=head->data;
	Node* temp=head;
	head=head->next;
	sz--;
	return x;
}

int Stack::top(){
	if(head==NULL){
		cout<<"Empty stack ";
		return INT_MIN;
	}
	return head->data;
}

bool Stack::isEmpty(){
	return head==NULL;
}

int Stack::size(){
	return sz;
}

/*
	Inbuilt stack

	stack<dtype> name;

	name.push(x);
	name.pop()  		//pop return type is void
	name.top()
	name.size()
	name.empty()
*/

bool checkParentheses(string str){
	stack<char> s;
	for(int i=0; i<str.size(); i++){
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')
			s.push(str[i]);

		if(str[i]==')' || str[i]=='}' || str[i]==']'){

			if(s.empty()) 
				return false;
			char x=s.top();
			s.pop();
			if( (x=='(' && str[i]!=')') || (x=='{' && str[i]!='}') || (x=='[' && str[i]!=']'))
				return false;
		}
	}
	return s.empty();
}

int main(){
	Stack stk;
	while(1){
		int ch;
		cout<<"CHOICE: 1)Push 2)Pop 3)Top 4)isEmpty 5)Size 6)Break:"<<endl;
		cin>>ch;
		if(ch==1)		{int x; cout<<"Element:"; cin>>x; stk.push(x);}
		else if(ch==2)	cout<<stk.pop()<<endl;
		else if(ch==3)	cout<<stk.top()<<endl;
		else if(ch==4)  cout<<stk.isEmpty()<<endl;
		else if(ch==5)	cout<<stk.size()<<endl;
		else if(ch==6)	break;
		else			cout<<"Invalid choice"<<endl;	
	}

	// string str;
	// cin>>str;
	// cout<<checkParentheses(str);
	
	return 0;		
}

