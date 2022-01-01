#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(){    //constructor
		this->data=-1;
		next=NULL;
	}
	Node(int data){    //constructor
		this->data=data;
		next=NULL;
	} 	
};

class LinkedList{
public:
	Node* initialize_list();
	void print_list_recurr(Node* head);
	void print_list_iter(Node* head);

	Node* insert_itterative(Node* head, int idx, int val);
	Node* insert_recurrsion(Node* head, int idx, int val);
	Node* delete_iterative(Node* head, int idx);
	Node* delete_recurrsion(Node* head, int idx);
	Node* reverse_recurrsion(Node* head);
	Node* reverse_iterative(Node* head);

	Node* mid_element(Node* head);
	Node* deleteMiddle(Node* head);
	Node* merge_lists(Node* l1, Node* l2);
	Node* mergesort(Node* head);
};

Node* LinkedList::initialize_list(){
		
	Node* head=NULL;
	Node* tail=NULL;
	int choice;
	do{
		cout<<"Enter value"<<endl;
		int x;
		cin>>x;
		Node* newnode= new Node(x);
		if(head==NULL){
			head=newnode;
			tail=newnode;
		}
		else{
			tail->next=newnode;
			tail=newnode;
		}
		
		cout<<"Enter 1 if you wish to continue else 0"<<endl;
		cin>>choice;

	}while(choice);

	return head;
}


void LinkedList::print_list_iter(Node* head){
	Node* curr=head;
	while(curr!=NULL){
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
	return;
}

void LinkedList::print_list_recurr(Node* head){
	if(head==NULL) {cout<<endl; return;}

	cout<<head->data<<" ";

	LinkedList::print_list_recurr(head->next);

}

Node* LinkedList::insert_itterative(Node* head, int idx, int val){
	// 0 1 2 3 4 5 
	// 1 2 3 4 5
	Node* newnode= new Node(val);
	if(idx==0){
		newnode->next=head;
		head=newnode;
	}
	else{
		Node* curr=head;
		for(int i=0; i<idx-1; i++)
			if(curr!=NULL)
			curr=curr->next;

		if(curr!=NULL){
			newnode->next=curr->next;
			curr->next=newnode;
		}
		// Node* temp=curr->next;
		// curr->next=newnode;
		// newnode->next=temp;
	}	
	return head;
}

Node* LinkedList::insert_recurrsion(Node* head, int idx, int val){
	if(head==NULL) return NULL;
	if(idx==0){
		Node* newnode=new Node(val);
		newnode->next=head;
		head=newnode;
	}
	else{
		Node* temp= LinkedList::insert_recurrsion(head->next, idx-1, val);
		head->next=temp;
	}
	return head;
}

Node* LinkedList::delete_iterative(Node* head, int idx){
	if(idx==0){
		Node* temp=head;
		head=head->next;
		delete temp;
		return head;
	}

	Node* curr=head;
	for(int i=0; i<idx-1; i++)
		if(curr!=NULL)
		curr=curr->next;

	if(curr!=NULL){
		Node* temp=curr->next;
		curr->next=temp->next;
		delete temp;
	}
	return head;
}


Node* LinkedList::delete_recurrsion(Node* head, int idx){
	if(head==NULL) return NULL;
	if(idx==0){
		Node*temp= head;
		head=head->next;
		delete temp;
	}
	else{
		Node* temp= delete_recurrsion(head->next, idx-1);
		head->next=temp;
	}
	return head;
}
       	

Node* LinkedList::reverse_iterative(Node* head){
	Node* curr=head, *Prev=NULL,  *Next=head->next;
	while(curr!=NULL){
		curr->next=Prev;
		Prev=curr;
		curr=Next;
		if(Next!=NULL) Next=curr->next;
	}
	return Prev;
}


Node* LinkedList::reverse_recurrsion(Node* head){
	if(head==NULL || head->next==NULL) return head;

	Node* temp=reverse_recurrsion(head->next);
	Node* tail=head->next;		//H->1->2->3->4->NULL
	tail->next=head;		 //temp->4->3->2,   2 that is now tail of temp is head->next
	head->next=NULL;		// put head in temp's tail next, and Null in head's next		
	return temp;
}
               
Node* LinkedList::mid_element(Node* head){
	Node* slow=head, *fast=head->next;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

Node* LinkedList::deleteMiddle(Node* head){
    if(head==NULL) return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    } 
    Node *slow=head, *fast=head->next,*prev=head;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=slow->next;
    delete slow;
    return head;
}
    Node* LinkedList::merge_lists(Node* l1, Node* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        Node* curr1=l1, *curr2=l2, *head=NULL,*tail=NULL;
        
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->data<=curr2->data){
                if(head==NULL){
                    head=new Node(curr1->data);
                    tail=head;
                }
                else{
                    tail->next=new Node(curr1->data);
                    tail=tail->next;
                }
                curr1=curr1->next;
            }
            else{
                if(head==NULL){
                    head= new Node(curr2->data);
                    tail=head;
                }
                else{
                    tail->next=new Node(curr2->data);
                    tail=tail->next;
                }
                curr2=curr2->next;
            }
        }
        
        if(curr1!=NULL){
            while(curr1!=NULL){
                tail->next=new Node(curr1->data);
                tail=tail->next;
                curr1=curr1->next;
            }
        }
        if(curr2!=NULL){
            while(curr2!=NULL){
                tail->next=new Node(curr2->data);
                tail=tail->next;
                curr2=curr2->next;
            }
        }
        return head;
    }

Node* LinkedList::mergesort(Node* head){
	if(head->next==NULL) return head;
	Node *slow=head, *fast=head->next;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	Node* head2=slow->next;
	slow->next=NULL;
	Node* n1=LinkedList::mergesort(head);
	Node* n2=LinkedList::mergesort(head2);

	return LinkedList::merge_lists(n1,n2);
}
int main(){

	LinkedList list;
	
	Node* head=list.initialize_list();
	list.print_list_iter(head);
	list.print_list_recurr(head);

	int idx,val;
	cout<<"Enter index (starting from 0) and value: "<<endl;
	cin>>idx>>val;
	list.insert_itterative(head, idx, val);
	list.print_list_recurr(head);
	list.insert_recurrsion(head, idx, val);
	list.print_list_recurr(head);

	list.delete_iterative(head, idx);
	list.print_list_recurr(head);
	list.delete_recurrsion(head,idx);
	list.print_list_recurr(head);

	Node *head1=list.reverse_iterative(head);
	list.print_list_recurr(head1);
	head=list.reverse_recurrsion(head1);
	list.print_list_recurr(head);


	cout<<"Mid elm is: "<<list.mid_element(head)->data<<endl;
	head=list.deleteMiddle(head);
	list.print_list_recurr(head);

	head=list.merge_lists(head,head);
	list.print_list_recurr(head);

   cout<<"Merge sort is: ";
	head1=list.mergesort(head1);
	list.print_list_recurr(head1);

	return 0;
}

/* 1 1 2 1 3 1 4 1 5 0

   3 9
*/

/*Doubly linked list reverse

Node* reverse_DLL(Node* head){
	Node* curr=head, temp=NULL;

	while(curr!=NULL){
		temp=curr->prev;
		curr->prev=curr->next;
		curr->next=temp;
		curr=curr->prev;
	}
	if(temp==NULL) return head;
	return temp->prev;
}

*/