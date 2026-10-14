#include <iostream>
using namespace std;

class A{
	int x;
	public:
	void display(){
		cout<<"X is : "<<x<<endl;
	}
	
	friend void update();
};

void update(){
	//All data members and methods can be accessed through objects in friend function
	A obj;
	obj.x = 9;
	cout<<"Private member X is updated inside friend function : "<<obj.x<<endl;
}

int main() {
	A obj;
	//obj.x = 9;
	obj.display(); //X is : 854707568
	update();      //Private member X is updated inside friend function : 9
	obj.display(); //X is : 854707568
	return 0;
}
