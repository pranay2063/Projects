#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class student{

	long long scholarID;
	char name[30];
	char address[50];
	long long int phoneNO;

	public : 
	void read();
	void insert(long long, char [], char [], long long);
	//functions defined inside class are implicitly inline
	//https://www.geeksforgeeks.org/inline-functions-cpp/
	
};

void student :: read(){
	
	cout<<"Name : "<<name<<endl;
	cout<<"Address : "<<address<<endl;
	cout<<"Phone : "<<phoneNO<<endl;
	
}

void student :: insert(long long a, char b[], char c[], long long d){
	
	scholarID = a;
	strcpy(name, b); 
	//https://stackoverflow.com/questions/15914220/c-error-incompatible-types-in-assignment-of-char-to-char-2
	strcpy(address, c);
	phoneNO = d;
	
}

int main() {
	
	student obj;
	obj.insert(131112063, "Pranay Ranjan", "407MM BLR IN", 9996663331);
	obj.read();
	
	return 0;
}
