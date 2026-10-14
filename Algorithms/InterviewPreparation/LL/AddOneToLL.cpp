#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node *next;
	node(int data){
		this->data = data;
		this->next = NULL;
	}
};

void display(node *head){
	while(head != NULL){
		if(head->next == NULL)
			cout<<head->data;
		else
			cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

node *reverse(node *head){
	node *prev = NULL;
	node *current = head;
	node *temp;
	while(current != NULL){
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	
	return prev; 
}

node *addone(node *head){
	//Time complexity : O(n)
	node *R1 = reverse(head); //reverse LL first
	node *temp = R1; //Add 1 to LL
	int carry = 1;
	while(temp != NULL){
		int x = temp->data;
		temp->data = (x+1)%10;
		carry = (x+1)/10;
		if(temp->next == NULL && carry != 0){
			temp->next = new node(carry);
			break;
		}
		temp = temp->next;
	}
	return reverse(R1); //reverse back and return LL
}

int main() {
	
	//A number is represented in the form of LL - 123 : 1->2->3
	node *head = new node(1);
	head->next = new node(9);
	head->next->next = new node(9);
	head->next->next->next = new node(9);
	
	display(head);
	node *R1 = addone(head);
	display(R1);
	
	return 0;
}
