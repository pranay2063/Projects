/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class MultipleStaticBlock
{
	static int num;
	static String str;
	static{
		System.out.println("Entering static block 1");
		num = 10;
		str = "Initial";
	}
	
	static{
		System.out.println("Entering static block 2");
		num = 50;
		str = "Updated";
	}
	
	public static void main (String[] args) 
	{
		//Entering static block 1
		//Entering static block 2
		System.out.println("Num : "+num); //Num : 50
		System.out.println("Str : "+str); //Str : Updated
	}
}
