/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class StaticVariablesAreShared
{
	
	private static int num;
	private String str;
	
	public static void main (String[] args) 
	{
		StaticVariablesAreShared obj1 = new StaticVariablesAreShared();
		StaticVariablesAreShared obj2 = new StaticVariablesAreShared();
		
		obj1.num = 23;
		obj1.str = "Germany";
		
		obj2.num = 53;
		obj2.str = "Netherlands";
		
		System.out.println("obj1.num : "+obj1.num+", obj1.str : "+obj1.str); // obj1.num : 53, obj1.str : Germany
		System.out.println("obj2.num : "+obj2.num+", obj2.str : "+obj2.str); // obj2.num : 53, obj2.str : Netherlands
		
		num = 0;
	}
}
