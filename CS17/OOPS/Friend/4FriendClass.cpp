#include <iostream>
using namespace std;

class A{
	int x;
	public:
	void set(){
		x = 69;
	}
	
	friend class B;
};

class B{
	//class B can access private members also as it is a friend of A
	public:
	void display(A a){
		//private member of class A can now be accessed through object as B is friend
		cout<<"x is : "<<a.x<<endl;
	}
	
};

int main() {
	A obj;
	obj.set();
	B obj2;
	obj2.display(obj); //x is : 69
	return 0;
}
