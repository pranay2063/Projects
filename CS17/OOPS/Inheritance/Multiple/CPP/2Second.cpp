//Multiple	Inheritance - One class is inheriting from two base classes
#include <iostream>
using namespace std;

class A {
	public:
	A(){
		//Constructor
		cout<<"Class A data"<<endl;
	}
};

class B {
	public:
	B(){
		//Constructor
		cout<<"Class B data"<<endl;
	}
};

class C : public A, public B{
		
};

int main() {
	C obj;
	return 0;
}
