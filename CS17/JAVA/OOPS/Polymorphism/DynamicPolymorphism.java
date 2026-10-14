/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Animal{
	void sound(){
		System.out.println("Default Animal Sound");
	}
}

class Dog extends Animal
{
	
	void sound(){
		System.out.println("Bark");
	}
	
}	

/* Name of the class has to be "Main" only if the class is public. */
class DynamicPolymorphism
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Animal obj = new Dog(); //Instance of class 'Animal' referring to instance of 'Dog'
		obj.sound(); //Method is decided at runtime (dynamic)
	}
} 
