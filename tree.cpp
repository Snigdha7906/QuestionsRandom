#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
	public:
	int data;
	vector<TreeNode*> children;
	TreeNode(int x){
		this->data=x;
	}
	~TreeNode(){
		for (int i=0; i<children.size(); i++){
			delete children[i];
		}
	}
};

class tree
{
public:
	TreeNode* initialiseTree();
	TreeNode* initialiseLevelWise();

	void printTree(TreeNode* root);
	void printTreeLevelwise(TreeNode* root);

	void preorder(TreeNode* root);
	void postorder(TreeNode* root);
	void levelorder(TreeNode* root);

	int countNodes(TreeNode* root);
	int countLeafNodes(TreeNode* root);

	int height(TreeNode* root);
	void printatLevel(TreeNode* root, int l);
};

TreeNode* tree::initialiseTree(){
	int x;
	int n;

	cout<<"Enter data ";
	cin>>x;
	TreeNode* root= new TreeNode(x);
	cout<<"Enter no of children of node : "<<x;
	cin>>n;
	for(int i=0; i<n; i++){
		TreeNode* child=initialiseTree();
		root->children.push_back(child);
	}
	return root;
}




TreeNode* tree::initialiseLevelWise(){
	cout<<"Enter root data: ";
	int x;
	int n;

	cin>>x;
	TreeNode* root= new TreeNode(x);

	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode* front=q.front();
		q.pop();
		cout<<"Enter no of children of "<<front->data;
		cin>>n;
		for(int i=0; i<n; i++){
			cout<<"Enter "<<i<<"th child of node"<<front->data;
			cin>>x;
			TreeNode* child= new TreeNode(x); 
			front->children.push_back(child);
			q.push(child);
		}
	}
	return root;
}


void tree::printTree(TreeNode* root){
	if(root==NULL) return; //edge case (not base case)
	cout<<root->data<<":";
	for(int i=0; i<root->children.size(); i++){
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;

	for(int i=0; i<root->children.size(); i++){
		printTree(root->children[i]);
	}
}

void tree::printTreeLevelwise(TreeNode* root){
	if(root==NULL) return;

	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){
		TreeNode* front=q.front();
		q.pop();
		cout<<front->data<<":";
		for (int i=0; i<front->children.size(); i++){
			cout<<front->children[i]->data<<",";
			q.push(front->children[i]);
		}
		cout<<endl;
	}
}

void tree::preorder(TreeNode* root){
	if(root==NULL) return;

	cout<<root->data<<",";
	for (int i=0; i<root->children.size(); i++){
		preorder(root->children[i]);
	}
}



void tree::postorder(TreeNode* root){
	if(root==NULL) return;

	for(int i=0; i<root->children.size(); i++){
		postorder(root->children[i]);
	}
	cout<<root->data<<",";
}

void tree::levelorder(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){
		TreeNode* front= q.front();
		q.pop();

		cout<<front->data<<", ";
		for(int i=0; i<front->children.size(); i++){
			q.push(front->children[i]);
		}
	}
}


int tree::countNodes(TreeNode* root){
	int count=1;
	for(int i=0; i<root->children.size(); i++){
		count+=countNodes(root->children[i]);
	}
	return count;
}

int tree::countLeafNodes(TreeNode* root){
	if(root==NULL) return -1;

	if(root->children.size()==0) return 1;
	int ans=0;

	for(int i=0; i<root->children.size(); i++){
		ans+=countLeafNodes(root->children[i]);
	}

	return ans;
}

int tree::height(TreeNode* root){
	if(root==NULL) return 0;

	int h=1, maxheight=1;
	for(int i=0; i<root->children.size(); i++){
		h+=height(root->children[i]);
		maxheight=maxheight>h?maxheight:h;
		h=1;
	}
	return maxheight;
}

void tree::printatLevel(TreeNode* root, int l){
	if(l==0) {
		cout<<root->data<<", ";
		return;
	}
	for(int i=0; i<root->children.size(); i++){
		printatLevel(root->children[i], l-1);
	}
}


int main()
{
	tree Tree;
	TreeNode* root1= Tree.initialiseTree();
	Tree.printTree(root1);

	TreeNode* root2=Tree.initialiseLevelWise();
	Tree.printTreeLevelwise(root2);

	Tree.preorder(root2);
	cout<<endl;
	Tree.postorder(root2);
	cout<<endl;
	Tree.levelorder(root2);
	cout<<endl;

	cout<<"No of Nodes: "<<Tree.countNodes(root2)<<endl;
	cout<<"No of Leaf Nodes: "<<Tree.countLeafNodes(root2)<<endl;
	cout<<"height: "<<Tree.height(root2)<<endl;

	cout<<"Enter level: ";
	int l; 	cin>>l;
	Tree.printatLevel(root2, l);

	delete root1; //calling destructor
	delete root2;
	return 0;
}