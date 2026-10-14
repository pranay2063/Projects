#include <iostream>
using namespace std;

class Daredevil{

	int i;
	public:
	void Matt() const 
	{
		//const member function
		//cannot modify member variables inside const member function
		//Error : assignment of member ‘Daredevil::i’ in read-only object
		cout<<"Member variables cannot be modified here"<<endl;
	}
	
};

int main() {
	Daredevil obj;
	obj.Matt(); //Member variables cannot be modified here
	return 0;
}
