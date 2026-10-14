#include <iostream>
using namespace std;

class A{
	int x;
	public:
	void display(){
		x = 49;
		cout<<"X is : "<<x<<endl;
	}
	
	friend void update();
};

class B : public A{
	int y;
	public:
	void init(){
		cout<<"Welcome to class B"<<endl;
	}	
};

void update(){
	//All data members and methods can be accessed through objects in friend function
	A obj;
	obj.x = 9;
	cout<<"Private member x is updated inside friend function : "<<obj.x<<endl;
	B obj2;
	obj2.x = 99;
	cout<<"x is updated using object of B inside friend function : "<<obj2.x<<endl;
	//obj2.y = 101;
	//The above statement will give error as friend members are not inherited
}

int main() {
	A obj;
	//obj.x = 9;
	obj.display(); //X is : 49
	update();      
	//Private member x is updated inside friend function : 9
	//x is updated using object of B inside friend function : 99
	obj.display(); //X is : 49
	return 0;
}
