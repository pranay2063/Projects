#include <iostream>
using namespace std;

class A{
	int x;
	public:
	void set(){
		x = 69;
	}
	void display(){
		cout<<"x is : "<<x<<endl;
	}
	
	friend void update(A&);
};

void update(A &a){
	//All data members and methods can be accessed through objects in friend function
	a.x = 89;
	cout<<"value of x inside friend : "<<a.x<<endl;
}

int main() {
	A obj;
	obj.set();
	obj.display(); //x is : 69
	update(obj);   //value of x inside friend : 89   
	obj.display(); //x is : 89
	return 0;
}
