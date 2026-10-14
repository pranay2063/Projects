//Multiple	Inheritance - One class is inheriting from two base classes
#include <iostream>
using namespace std;

class A {
	public:
	void displayA(){
		cout<<"Class A data"<<endl;
	}
};

class B {
	public:
	void displayB(){
		cout<<"Class B data"<<endl;
	}
};

class C : public A, public B{
		
};

int main() {
	C obj;
	obj.displayA();
	obj.displayB();
	return 0;
}
