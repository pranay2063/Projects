/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class ConstructorChaining
{
	int age;
	String name;
	String address;
	String addhar;
	ConstructorChaining(){
		this("Pranay Ranjan");
	}
	
	ConstructorChaining(String name){
		this(name, 25);
	}
	
	ConstructorChaining(String name, int age){
		this(name, age, "407MMBLR");
	}
	
	ConstructorChaining(String name, int age, String address){
		this(name, age, address, "1234 5678 4321");
	}
	
	ConstructorChaining(String name, int age, String address, String addhar){
		this.name = name;
		this.age = age;
		this.address = address;
		this.addhar = addhar;
	}
	
	void display(){
		System.out.println("Name : "+this.name);
		System.out.println("Age : "+this.age);
		System.out.println("Address : "+this.address);
		System.out.println("Addhar : "+this.addhar);
	}
	
	public static void main (String[] args) 
	{
		ConstructorChaining obj = new ConstructorChaining();
		obj.display();
	}
}
