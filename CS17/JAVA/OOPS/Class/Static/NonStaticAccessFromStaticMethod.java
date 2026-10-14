/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class NonStaticAccessFromStaticMethod
{
	
	int a;
	static int b; 
	
	static void disp(){
		//a = 20; 
		//Above statement will giver error 
		//non-static variable a cannot be referenced from a static context
		b = 120;
		//System.out.println(a+" "+b);
		System.out.println(b);
	}
	
	public static void main (String[] args)
	{
		disp();
	}
}
