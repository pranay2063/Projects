//Runtime Polymorphism - The decision to call an overridden function is taken at runtime

#include <iostream>
using namespace std;

class base{
	public:
	virtual void show() { cout<<"Welcome to Base!"<<endl; }
};

class derived : public base{
	public:
	void show() { cout<<"Welcome to Derived!"<<endl; }
};

int main() {
	base *objb = new derived; //Runtime Polymorphism
	objb->show(); //Welcome to Derived!
	return 0;
}
 
