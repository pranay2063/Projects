/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class StaticVariableDirectAccess
{
	
	static int num;
	static String str;
	void initdisp(){
		num  = 100;
		str = "Swimming is the best exercise";
		System.out.println("Num : "+num);
		System.out.println("Str : "+str);
	}
	public static void main (String[] args) 
	{
		StaticVariableDirectAccess obj = new StaticVariableDirectAccess();
		obj.initdisp();
		//Num : 100
		//Str : Swimming is the best exercise
	}
}
