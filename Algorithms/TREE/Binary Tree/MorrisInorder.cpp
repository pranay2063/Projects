
#include <bits/stdc++.h>

using namespace std;

class Node{
	//class to create node
	public:
	int data;
	Node *right;
	Node *left;
	Node(int data){
		//constructor to initialize node with data
		this->data = data;
		right = NULL;
		left = NULL;
	}
};

void MorrisInorder(Node *root){

	//The time complexity of the algorithm is O(n) and space complexity is O(1)
	//Morris traversal does inorder & preorder traversal of a binary tree without using any additional space
	//Morris traversal creates additional links and then breaks them to bring original tree back
	
	if(root == NULL) return;

	Node *current = root;
	while(current != NULL){
		//left child of current is NULL
		if(current->left == NULL){
			cout<<current->data<<" ";
			current = current->right;
		}
		else{
			
			//this is where changes occur as a part of morris traversal
			Node *pre = current->left;
			while(pre->right != NULL && pre->right != current)
				pre = pre->right;

			if(pre->right == NULL){
				//find inorder predecessor of current assuming BST
				//set current as the right child of the rightmost node of the left subtree
				pre->right = current;
				current = current->left;
			}
			else{
				//this is the case where restoration of the original tree happens 
				//links which were added as a part of morris traversal are removed
				cout<<current->data<<" ";
				pre->right = NULL;
				current = current->right;
			}

		}
	}
}

int main(){

	Node *root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(2);
	root->left->left = new Node(11);
	root->left->right = new Node(13);
	root->right->left = new Node(41);
	root->right->right = new Node(37);
	root->left->left->left = new Node(6);
	root->left->left->right = new Node(18);

	cout<<"Inorder : ";
	MorrisInorder(root); 
	cout<<endl;

	return 0;

}

