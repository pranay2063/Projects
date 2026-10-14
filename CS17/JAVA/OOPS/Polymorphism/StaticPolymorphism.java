/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class FunctionOverloading{
	void add(int a, int b){
		System.out.println(a+b);
	}
	void add(String a, String b){
		System.out.println(a+b);
	}
}

/* Name of the class has to be "Main" only if the class is public. */
class StaticPolymorphism
{
	public static void main (String[] args)
	{
		FunctionOverloading obj1 = new FunctionOverloading();
		obj1.add(23, -20);
		obj1.add("WeShallOvercome","Someday");
	}
}
