/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class CopyConstructorInvoked
{
	private String data;
	
	CopyConstructorInvoked(){
		System.out.println("Non-parameterized constructor is called");
		this.data = "Default data";
	}
	
	CopyConstructorInvoked(String data){
		System.out.println("Parameterized constructor is called");
		this.data = data;
	}
	
	CopyConstructorInvoked(CopyConstructorInvoked obj){
		System.out.println("Copy constructor is called");
		this.data = obj.data;
	}
	
	void disp(){
		System.out.println(data); //this.data
	}
	
	public static void main (String[] args) 
	{
		
		CopyConstructorInvoked obj1 = new CopyConstructorInvoked("How is the Josh?"); //Parameterized constructor is called
		CopyConstructorInvoked obj2 = new CopyConstructorInvoked(obj1); //Copy constructor is called
		obj1.disp(); //How is the Josh?
		obj2.disp(); //How is the Josh?
	}
}
