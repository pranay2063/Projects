#include <iostream>
using namespace std;

class Daredevil{

	int i;
	mutable int j;
	public:
	void Matt() const 
	{
		//const member function
		//cannot modify member variables inside const member function
		//But mutable variables can be modified
		j = 99;
		cout<<"Member variables except mutable ones cannot be modified here"<<endl;
		cout<<"j updated here : "<<j<<endl;	
	}
	
};

int main() {
	Daredevil obj;
	obj.Matt(); 
	//Member variables except mutable ones cannot be modified here
	//j updated here : 99
	return 0;
}
