/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class ConstructorExample
{
	String name;
	int age;
	
	ConstructorExample(){
		this.name = "Pranay Ranjan";
		this.age = 24;
	}
	
	ConstructorExample(String name, int age){
		this.name = name;
		this.age = age;
	}
	
	void display(){
		System.out.println("Name : "+this.name+", Age : "+this.age);
	}
	
	public static void main (String[] args) 
	{
		
		ConstructorExample obj1 = new ConstructorExample();
		ConstructorExample obj2 = new ConstructorExample("Scarlett Johansson", 33);
		
		obj1.display();
		obj2.display();
		
	}
}
