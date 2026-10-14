//Multiple Inheritance - One class is inheriting from two base classes
#include <iostream>
using namespace std;

class A {
	public:
	void display(){
		//Constructor
		cout<<"Class A data"<<endl;
	}
};

class B {
	public:
	void display(){
		//Constructor
		cout<<"Class B data"<<endl;
	}
};

class C : public A, public B{
		
};

int main() {
	C obj;
	//obj.display();
	//Above syntax causes issues during function overriding
	//This can be resolved using scope resolution as shown below
	obj.A::display();
	obj.B::display();
	return 0;
}
