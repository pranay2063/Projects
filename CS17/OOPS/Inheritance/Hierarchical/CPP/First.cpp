//Hierarchical - multiple classes are inherited from one class

#include <iostream>
using namespace std;
class A {
	public:
	void display(){
		cout<<"Class A data"<<endl;
	}
	void show_date();
};

//the below definition is done when function has a lot of line executions 
void A :: show_date(){
	cout<<"Today is 13 January 2019"<<endl;
}

class B : public A{
	
};

class C : public A{
	
};

int main() {
	B obj1;
	C obj2;
	obj1.display();
	obj2.show_date();
	return 0;
}
