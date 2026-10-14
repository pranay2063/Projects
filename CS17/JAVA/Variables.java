//Variables - Local, static and instance

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Variables
{
	public static String staticStr = "Previous Static";
	public String instanceStr = "Previous Instance";
	public String str = "Local"; 
	
	public void update(){
		String str = "Updated Local"; //Local definition of 'str'
		System.out.println(str);
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		//static
		Variables obj1 = new Variables();
		Variables obj2 = new Variables();
		
		System.out.println(obj1.staticStr); //Previous Static
		System.out.println(obj2.staticStr); //Previous Static
		
		obj1.staticStr = "Current Static";
		
		System.out.println(obj1.staticStr); //Current Static
		System.out.println(obj2.staticStr); //Current Static
		
		//Instance
		Variables obj3 = new Variables(); 
		Variables obj4 = new Variables();
		
		System.out.println(obj3.instanceStr); //Previous Instance
		System.out.println(obj4.instanceStr); //Previous Instance
		
		obj3.instanceStr = "Current Instance";
		
		System.out.println(obj3.instanceStr); //Current Instance
		System.out.println(obj4.instanceStr); //Previous Instance
		
		//Local
		Variables obj5 = new Variables();
		System.out.println(obj5.str); //Local
		obj5.update(); //Updated Local
		System.out.println(obj5.str); //Local
	}
}
