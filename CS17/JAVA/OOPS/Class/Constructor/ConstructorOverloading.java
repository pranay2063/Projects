/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class ConstructorOverloading
{
	
	ConstructorOverloading(int a, String b){
		System.out.println("Int"+"String");
	}
	
	ConstructorOverloading(String a, int b){
		System.out.println("String"+"Int");
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		new ConstructorOverloading(10, "Pranay"); //IntString
		new ConstructorOverloading("Pranay", 10); //StringInt
	}
}
