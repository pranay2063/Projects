#include <iostream>
using namespace std;

//Once declared, static variables have space allocated for lifeime of the program
//Value of static members is carry forwarded for next function call

void func(){
	static int cnt = 0;
	cout<<cnt<<" ";
	++cnt;
}

int main() {
	for(int i = 0; i < 5; ++i)
		func();
	//0 1 2 3 4 
	cout<<endl;	
	return 0;
}
