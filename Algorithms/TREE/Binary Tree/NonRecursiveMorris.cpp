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

//The time complexity of the algorithm is O(n) and space complexity is O(1)
//Morris traversal does inorder & preorder traversal of a binary tree without using any additional space
//This algorithm can be modified to work for postorder traversal also

void inorderMorris(node *root)
{

	cout<<"INORDER : ";
	if(root == NULL) return;

	node *current = root;
	while(current)
	{

		if(current->left == NULL)
		{
			cout<<current->data<<" ";
			current = current->right;
		}	
		else 
		{

			//this is where changes occur as a part of morris traversal
			node *pre = current->left;
			while(pre->right && pre->right != current)
				pre = pre->right;

			if(pre->right == NULL)
			{
				//find inorder predecessor of current assuming BST
				//set current as the right child of the rightmost node of the left subtree
				pre->right = current;
				current = current->left;
			}	
			else
			{
				//this is the case where restoration of the original tree happens 
				//links which were added as a part of morris traversal are removed
				pre->right = NULL;
				cout<<current->data<<" ";
				current = current->right;
			}	

		}	

	}	

	cout<<endl;

}

void preorderMorris(node *root)
{

	cout<<"PREORDER : ";
	if(root == NULL) return;

	node *current = root;
	while(current)
	{

		if(current->left == NULL)
		{
			cout<<current->data<<" ";
			current = current->right;
		}	
		else
		{

			//this is where changes occur as a part of morris traversal
			node *pre = current->left;
			while(pre->right && pre->right != current)
				pre = pre->right;

			if(pre->right == NULL)
			{
				//find inorder predecessor of current assuming BST
				//set current as the right child of the rightmost node of the left subtree
				pre->right = current;
				cout<<current->data<<" ";
				current = current->left;
			}	
			else
			{
				//this is the case where restoration of the original tree happens 
				//links which were added as a part of morris traversal are removed
				pre->right = NULL;
				current = current->right;
			}	

		}	

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

	inorderMorris(root);
	preorderMorris(root);
	//postorder(root);

	return 0;
}

