#include <iostream>
using namespace std;

class TDK{
	
	public:
	static int joker;
	TDK(){
		//undefined reference error for initializing static variables here
	}
};

int TDK::joker = 9; //static variable initialization

int main() {
	TDK obj1, obj2;
	//undefined reference error for initializing static variables here
	//obj1.joker = 99;
	//obj2.joker = 121;
	cout<<obj1.joker<<" "<<obj2.joker<<endl; //9 9
	TDK::joker = 10;
	cout<<obj1.joker<<" "<<obj2.joker<<endl; //10 10
	return 0;
}
