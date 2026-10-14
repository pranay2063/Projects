#include <iostream>
using namespace std;

//https://www.geeksforgeeks.org/does-compiler-always-create-a-copy-constructor/
//Compiler creates its own normal and copy constructors if both are absent
//Comiler creates its owm copy constructor if we create our own normal constructor
//But compiler does not create its own normal constructor if we create our own copy constructor
//We need to create our own normal constructor if we have created a copy constructor
//error: no matching function for call to ‘A::A(int)’ for above case

class A{
	int x;
	public:
	A(int num){ 
		x = num; 
		cout<<"Normal constructor is being called"<<endl;
	}
	A(const A &a){
		x = a.x;
		cout<<"Copy constructor is getting called"<<endl;
	}
	void display(){
		cout<<"x is : "<<x<<endl;
	}
	
	friend void update(A);
};

void update(A a){
	//Copy constructor is called during pass by value in function parameter
	//All data members and methods can be accessed through objects in friend function
	a.x = 89;
	cout<<"value of x inside friend : "<<a.x<<endl;
}

int main() {
	A obj(69); //Normal constructor is being called
	obj.display(); //x is : 69
	update(obj);   
	//Copy constructor is getting called
	//value of x inside friend : 89
	obj.display(); //x is : 69
	return 0;
}
