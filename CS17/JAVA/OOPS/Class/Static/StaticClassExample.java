/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class StaticClassExample
{
	int num;
	static String str;
	
	static class StaticClass{
		
		void set(){
			//num = 101;
			//error: non-static variable num cannot be referenced from a static context
			str = "You have to do it";
		}
		
		void disp(){
			//system.out.println(num);
			//error: non-static variable num cannot be referenced from a static context
			System.out.println(str);
		}
	}
	
	public static void main (String[] args) 
	{
		StaticClassExample.StaticClass obj = new StaticClass();
		obj.set();
		obj.disp();
	}
}
