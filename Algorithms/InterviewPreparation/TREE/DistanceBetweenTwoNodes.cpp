
#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	int data;
	node *left;
	node *right;
	node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

node *LCA(node *root, int x, int y){

	//returns LCA of two nodes x and y
	if(root == NULL)
		return NULL;

	if(root->data == x || root->data == y)
		return root; //return if any node is found

	//check returned data from two children
	node *lchild = LCA(root->left, x, y);
	node *rchild = LCA(root->right, x, y);

	if(lchild != NULL && rchild != NULL)
		return root;
	
	if(lchild != NULL)
		return lchild;
	
	if(rchild != NULL)
		return rchild;

	return NULL;  

}

int distanceBetweenNodes(node *root, int x){
	
	//function finds distance between root and any specified node x
	if(root == NULL) 
		return -1;
	
	if(root->data == x)
		return 0; //return if node is found
	
	//check if any of children has found node x
	int dleft = distanceBetweenNodes(root->left, x);
	int dright = distanceBetweenNodes(root->right, x);

	if(dleft > -1)
		return dleft+1;
	
	if(dright > -1)
		return dright+1;

	return -1;

}

int main(){

	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	root->left->left->left = new node(8);
	root->left->left->right = new node(9);
	root->left->right->left = new node(10);
	root->left->right->right = new node(11);
	root->right->left->left = new node(12);
	root->right->left->right = new node(13);
	root->right->right->left = new node(14);
	root->right->right->right = new node(15);

	int X = 8, Y = 1;
	node *lca = LCA(root, X, Y);
	cout<<"Distance between "<<X<<" and "<<Y<<" is "<<distanceBetweenNodes(lca, X)+distanceBetweenNodes(lca, Y);

	return 0;

}
