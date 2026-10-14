
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

int pathSumX(node *root, vector<int> &p, int sum){
	
	if(root == NULL) 
		return 0;

	sum -= root->data;
	p.push_back(root->data);

	if(root->left == NULL && root->right == NULL){
		if(sum == 0){
			//path is found
			//print path from root to this node 
			for(int i = 0; i < p.size(); ++i)
				cout<<p[i]<<" ";
			cout<<endl;
			p.pop_back();
			return 1;
		}
	}

	int cnt = pathSumX(root->left, p, sum) + pathSumX(root->right, p, sum);

	p.pop_back();

	return cnt;

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

	int X = 15;
	vector<int> p;
	int cnt = pathSumX(root, p, X);
	cout<<"Number of path(s) from root to leaf whose sum is "<<X<<" = "<<cnt;

	return 0;

}
