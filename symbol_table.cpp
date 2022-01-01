#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

class Node {

	string ID, scope, typ;
	int lineNo;
	Node* next;

public:
	Node()
	{
		next = NULL;
	}

	Node(string key, string value, string typ, int lineNo)
	{
		this->ID = key;
		this->scope = value;
		this->typ = typ;
		this->lineNo = lineNo;
		next = NULL;
	}

	void print()
	{
		cout << "ID:" << ID<< "\nType:" << typ<< "\nScope: " << scope<< "\nLine Number: " << lineNo << endl;
	}

	friend class SymbolTable;
};

class SymbolTable {
	Node* head[MAX];

public:
	SymbolTable(){
		for(int i=0; i< MAX; i++)
			head[i]=NULL;
	}

	int hx(string id){
		int ascsum=0;
		
		for(int i=0; i<id.length(); i++){
			ascsum=ascsum + id[i];
		}
		return (ascsum%100);
	}

	bool insert(string id, string scope, string typ, int lineno){
		int index=hx(id);
		Node* p=new Node(id, scope, typ, lineno);

		if(head[index]==NULL){
			head[index]=p;
			cout<< "\n"<< id <<" inserted";
			return true;
		}

		else{
			Node* start=head[index];
			while(start->next!=NULL)
				start=start->next;

			start->next=p;
			cout<<"\n"<<id<<" inserted \n";

			return true;
		}

		return false;
	}

	string find(string id){
		int index=hx(id);
		Node* start=head[index];

		if(start==NULL) return "-1";

		while(start!=NULL){
			if(start->ID==id){
				start->print();
				return start->scope;
			}
			start=start->next;
		}

		return "-1";
	}

	bool deleteRecord(string id){
		int index= hx(id);
		Node* temp= head[index];
		Node* par= head[index];

		if(temp==NULL) return false;
		
		if(temp->ID==id && temp->next==NULL){
			temp->next= NULL;
			delete temp;
			return true;
		}

		while(temp->ID!=id && temp->next!=NULL){
			par=temp;
			temp=temp->next;
		}
		if(temp->ID==id && temp->next!=NULL){
			par->next = temp->next;
			temp->next = NULL;
			delete temp;
			return true;
		}

		else{
			par->next=NULL;
			temp->next=NULL;
			delete temp;
			return true;
		}
		return false;
	}

	bool modify(string id, string s, string t, int ln){
		int index=hx(id);
		Node* start=head[index];

		if (start==NULL) return "-1";

		while(start!=NULL){
			if(start->ID==id){
				start->scope=s;
				start->typ=t;
				start->lineNo=ln;
				return true;
			}
			start=start->next;
		}
		return false; 
	}
};


int main()
{
	SymbolTable st;
	cout << "SYMBOL TABLE\n";

	bool cont=true;

	while(cont){
		cout<<"1.insert 2.find 3.delete 4.modify 5.Exit\n";
		int x;
		cin>>x;
		if(x==1){
			cout<<"Enter id, scope, type, line no : ";
			string id, scope, type; int ln;
			cin>>id>>scope>>type>>ln;
			if(st.insert(id, scope, type, ln)) cout<<"\nInserted \n";
			else cout<<"\nFailed to insert\n";
		}
		else if(x==2){
			cout<<"Enter id: ";
			string id;
			cin>>id;
			string p=st.find(id);
			if(p!="-1") cout<<"\nID present\n";
			else cout<<"\nID not present\n";
		}
		else if(x==3){
			cout<<"Enter id: ";
			string id;
			cin>>id;
			if(st.deleteRecord(id)) cout<<"\nID deleted\n";
			else cout<<"\nFailed to delete ID\n";
		}
		else if(x==4){
			cout<<"Enter id, scope, type, line no : ";
			string id, scope, type; int ln;
			cin>>id>>scope>>type>>ln;
			if(st.modify(id, scope, type, ln)) cout<<"\nModified\n";
			else cout<<"\nFailed to modify\n";
		}
		else if(x==5) cont=false;
		else cout<<"\nEnter valid choice \n";
	}

	return 0;
}
