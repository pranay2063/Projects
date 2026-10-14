
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

bool path(node *root, vector<int> &p, int x){
	
	//x is the node being for which path is being determined
	//p is the path vector that is updated in each recursion call
	//https://stackoverflow.com/questions/270408/is-it-better-in-c-to-pass-by-value-or-pass-by-constant-reference
	
	if(root == NULL) 
		return false; 

	p.push_back(root->data); //push current node to path vector
	
	if(root->data == x) 
		return true; //node x is found

	if(path(root->left, p, x) || path(root->right, p, x)) 
		return true; //case when one of the children has node x

	p.pop_back();

	return false; //case when node is not found

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

	int x = 23;
	vector<int> p;
	if(path(root, p, x)){
		cout<<"Path from "<<root->data<<" to "<<x<<" : ";
		for(int i = 0; i < p.size(); ++i)
			cout<<p[i]<<" ";
		cout<<endl;	
	}
	else{
		cout<<"Node "<<x<<" not found"<<endl;
	}

	return 0;

}
