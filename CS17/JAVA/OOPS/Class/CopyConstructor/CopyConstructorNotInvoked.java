/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class CopyConstructorNotInvoked
{
	private String data;
	
	CopyConstructorNotInvoked(){
		System.out.println("Non-parameterized constructor is called");
		this.data = "Default data";
	}
	
	CopyConstructorNotInvoked(String data){
		System.out.println("Parameterized constructor is called");
		this.data = data;
	}
	
	CopyConstructorNotInvoked(CopyConstructorNotInvoked obj){
		System.out.println("Copy constructor is called");
		this.data = obj.data;
	}
	
	void disp(){
		System.out.println(data); //this.data
	}
	
	public static void main (String[] args)  
	{
		
		CopyConstructorNotInvoked obj1 = new CopyConstructorNotInvoked("How is the Josh?"); //Parameterized constructor is called
		CopyConstructorNotInvoked obj2 = new CopyConstructorNotInvoked(); //Non-parameterized constructor is called
		obj2.disp(); //Default data
		obj2 = obj1;
		obj1.disp(); //How is the Josh?
		obj2.disp(); //How is the Josh?
	}
}
