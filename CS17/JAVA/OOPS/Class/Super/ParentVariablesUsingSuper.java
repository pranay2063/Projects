/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Parent{
	int num = 2019;
}

class ParentVariablesUsingSuper extends Parent
{
	int num = 2020;
	private void disp(){
		System.out.println(num);
		System.out.println(super.num);
	}
	
	public static void main (String[] args)
	{
		//disp();
		//error: non-static method disp() cannot be referenced from a static context
		
		ParentVariablesUsingSuper obj = new ParentVariablesUsingSuper();
		obj.disp();
		//2020
		//2019
		
	}
}
