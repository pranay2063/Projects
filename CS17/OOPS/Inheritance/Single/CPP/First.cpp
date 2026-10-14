//Hierarchical - multiple classes are inherited from one class

#include <iostream>
using namespace std;
class A {
	public:
	void display(){
		cout<<"Class A data"<<endl;
	}
};

class B : public A{
	
};

int main() {
	B obj;
	obj.display();

	return 0;
}
