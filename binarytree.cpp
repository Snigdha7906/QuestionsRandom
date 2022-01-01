#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode *left, *right;
	TreeNode(int x){
		this->data=x;
		left=NULL;
		right=NULL;
	}
	~TreeNode(){
		delete left;
		delete right;
	}
};

class binarytree
{
public:
	TreeNode* initialiseBinaryTree();
	TreeNode* initialiseBinaryTreeLevelwise();
	void printTree(TreeNode* root);
	void printTreeLevelwise(TreeNode* root);

	void preorder(TreeNode* root);  // Root L R
	void postorder(TreeNode* root); // L R Root
	void inorder(TreeNode* root);   // L Root R
	void levelorder(TreeNode* root); //level wise
	
	int countNodes(TreeNode* root);
	int height(TreeNode* root);
	int diameter(TreeNode* root);
	int heightDia(TreeNode* root);

};

TreeNode* binarytree::initialiseBinaryTree(){
	cout<<"Enter data: ";
	int x;
	cin>>x;

	if(x== -1) return NULL;

	TreeNode* root= new TreeNode(x);
	root->left=initialiseBinaryTree();
	root->right=initialiseBinaryTree();

	return root;
}

TreeNode* binarytree::initialiseBinaryTreeLevelwise(){
	cout<<"Enter root: ";
	int x; cin>>x;
	if(x==-1) return NULL;

	TreeNode* root= new TreeNode(x);
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){
		TreeNode* front= q.front();
		q.pop();

		cout<<"Enter left child of "<<front->data<<" ";
		cin>>x;
		if(x==-1) front->left=NULL;
		else {
			front->left= new TreeNode(x);
			q.push(front->left);
		}

		cout<<"Enter right child of "<<front->data<<" ";
		cin>>x;
		if(x==-1) front->right=NULL;
		else {
			front->right= new TreeNode(x);
			q.push(front->right);
		}
	}
	return root;
}

void binarytree::printTree(TreeNode* root){
	if(root==NULL) return;  //base case

	cout<<root->data<<": ";
	if(root->left!=NULL) cout<<" L: "<<root->left->data;
	if(root->right!=NULL) cout<<" R: "<<root->right->data;
	cout<<endl;

	printTree(root->left);
	printTree(root->right);
}

void binarytree::printTreeLevelwise(TreeNode* root){
	if(root==NULL) return;

	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){
		TreeNode* front=q.front();
		q.pop();

		cout<<front->data<<": ";
		if(front->left!=NULL){ 
			cout<<"L: "<<front->left->data;
			q.push(front->left);
		}
		if(front->right!=NULL){
			cout<<" R: "<<front->right->data;
			q.push(front->right);
		}
	}
}


void binarytree::preorder(TreeNode* root){
	if(root==NULL) return;

	cout<<root->data<<", ";
	preorder(root->left);
	preorder(root->right);
}

void binarytree::postorder(TreeNode* root){
	if (root==NULL) return;

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<", ";
}

void binarytree::inorder(TreeNode* root){
	if(root==NULL) return;

	inorder(root->left);
	cout<<root->data<<", ";
	inorder(root->right);
}

void binarytree::levelorder(TreeNode* root){
	if(root==NULL) return;

	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){
		TreeNode* front= q.front();
		q.pop();
		cout<<front->data<<", ";
		if(front->left) q.push(front->left);
		if(front->right) q.push(front->right);
	}
}


int binarytree::countNodes(TreeNode* root){
	if(root==NULL) return 0;

	int ans=1;
	ans+=countNodes(root->left);
	ans+=countNodes(root->right);
	return ans;

}

int tree::height(TreeNode* root){
	if(root==NULL) return 0;

	return 1+ max(height(root->left), height(root->right));
}

int tree::diameter(TreeNode* root){   //O(n*h)
	if(root==NULL) return 0;
	int lh=height(root->left);
	int rh=height(root->right);
	return max(lh+rh, max(diameter(root->left),diameter(root->right)));
}


pair<int,int> tree::heightDia(TreeNode* root){   //O(n)
	pair<int,int> p;

	//base case
	if(root==NULL){
		p.first=0;
		p.second=0;
		return p;
	}

	//hypothesis
	pair<int, int> leftans=heightDia(root->left);
	int lh=leftans.first ,ld=leftans.second;
	pair<int, int> rightans=heightDia(root->right);
	int rh=rightans.first, rd=rightans.second;

	// math
	int h=1+ max(lh, rh);
	int d=max(lh+rh, max(ld, rd));
	p.first=h;
	p.second=d;
	return p;
}

bulidtreehelper(int* in, int* pre, int instart, int inend, int prestart, int preend){

	if(instart>inend) return NULL;    //base condition

	int rootdata=pre[prestart];
	TreeNode* root=new TreeNode(rootdata);

	int rootindex=-1;
	for(int i=instart; i<=inend; i++)
		if (in[i]==rootdata)
		{
			rootindex=i;
			break;
		}

	int l_instart=instart;
	int l_inend=rootindex-1;
	int r_instart=rootindex+1;
	int r_inend=inend;

	int l_prestart=prestart+1;
	int l_preend= l_inend-l_instart +l_prestart;
	int r_prestart= l_preend+1;
	int r_preend=preend;

	root->left=bulidtreehelper(in, pre, l_instart, l_inend, l_prestart, l_preend);
	root->right=bulidtreehelper(in, pre, r_instart, r_inend, r_prestart, r_preend);
	return root;
}

TreeNode* tree::buildtree(int* in, int* pre, int sz);
{
	return bulidtreehelper(in, pre, 0, sz-1, 0, sz-1);
}


int main(){
	binarytree bt;
	// TreeNode* root =bt.initialiseBinaryTree();
	// bt.printTree(root);
	// delete root;

	TreeNode* root =bt.initialiseBinaryTreeLevelwise();
	bt.printTreeLevelwise(root);
	cout<<endl<<"preorder: ";
	bt.preorder(root);
	cout<<endl<<"postorder: ";
	bt.postorder(root);
	cout<<endl<<"inorder: ";
	bt.inorder(root);
	cout<<endl<<"levelorder: ";
	bt.levelorder(root);
	cout<<endl;
	cout<<"No of nodes: "<<bt.countNodes(root);
	cout<<endl;

	cout<<"height: "<<bt.height(root);
	cout<<endl<<"O(n*h) -> ";
	cout<<"diameter: "<<bt.diameter(root);
	cout<<endl<<"O(n) -> ";
	pair<int,int> p=bt.heightDia(root);
	cout<<"height: "<<p.first<<"diameter: "<<p.second;
	cout<<endl;
	delete root;
	return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1