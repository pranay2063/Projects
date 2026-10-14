#include <stack>
#include <cstdlib>
#include <iostream>
using namespace std;

struct node 
{
	int data;
	node *left;
	node *right;
};

void inorder(node *root)
{

	cout<<"INORDER : ";

	stack<node *> s;
	while(1)
	{
		while(root != NULL)
		{
			s.push(root);
			root = root->left;
		}	

		if(!s.empty())
		{
			node *x = s.top();
			s.pop();
			cout<<x->data<<" ";
			if(x->right != NULL) root = x->right;
		}	
		else break;
	}	

	cout<<endl; 

}

void preorder(node *root)
{

	cout<<"PREORDER : ";

	stack<node *> s;
	while(1)
	{
		while(root != NULL)
		{
			cout<<root->data<<" ";
			s.push(root);
			root = root->left;
		}	

		if(!s.empty())
		{
			node *x = s.top();
			s.pop();
			if(x->right != NULL) root = x->right;
		}	
		else break;
	}	

	cout<<endl;

}

void preorder2(node *root)
{

	cout<<"PREORDER2 : ";
	
	if(root == NULL) return ;
	
	stack<node *> s;
	s.push(root);
	
	while(!s.empty()){
		node *root = s.top();
		cout<<root->data<<" ";
		s.pop();
		if(root->right != NULL)
			s.push(root->right);
		if(root->left != NULL)
			s.push(root->left);
	}
	cout<<endl;
}

void postorder(node *root)
{

	cout<<"POSTORDER : ";

	stack<node *> s;
	while(1)
	{
		while(root)
		{
			if(root->right) s.push(root->right);
			s.push(root);
			root = root->left;
		}	

		root = s.top();
		s.pop();

		if(root->right && !s.empty() && root->right == s.top())
		{
			s.pop();
			s.push(root);
			root = root->right;
		}	
		else
		{
			cout<<root->data<<" ";
			root = NULL;
		}		
		
		if(s.empty()) break;
	}

	cout<<endl;

}

node * newNode(int data)
{

	node *tmp = (node *)malloc(sizeof(struct node));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;

}

int main(int argc, char const *argv[])
{
	
	node *root = newNode(25);
	root->left = newNode(13);
	root->right = newNode(11);
	root->left->left = newNode(75);
	root->left->right = newNode(35);
	root->right->left = newNode(5);
	root->right->right = newNode(4);

	inorder(root);
	preorder(root);
	preorder2(root);
	postorder(root);

	return 0;
}
