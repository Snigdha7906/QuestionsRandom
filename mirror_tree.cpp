#include<bits/stdc++.h>
using namespace std;
// Given a Binary Tree, convert it into its mirror.

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newnode(int data)
{
	struct node* nd=(struct node*)malloc(sizeof(struct node));
	nd->data=data;
	nd->left=NULL;
	nd->right=NULL;
	return(nd);
}

void mirror_tree(struct node* nd)
{
	struct node* tmp;
	if (nd==NULL)
		return;
	else
	{
		mirror_tree(nd->left);
		mirror_tree(nd->right);
		tmp=nd->left;
		nd->left=nd->right;
		nd->right=tmp;
	}
}
void inorder_print(struct node* nd)
{
	if (nd==NULL)
		return;
	inorder_print(nd->left);
	cout<<nd->data<<"  ";
	inorder_print(nd->right);
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
	#endif

    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right = newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    cout<<"\n inorder traveersa of original tree: ";
    inorder_print(root);
    mirror_tree(root);
    cout<<"\n inorder traveersa of mirror tree: ";
    inorder_print(root);
return 0;
}