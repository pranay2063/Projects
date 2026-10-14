/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;


class StaticMethod
{
	static void mymethod(){
		System.out.println("You are able to access me directly because I am static");
	}
	public static void main (String[] args) 
	{
		mymethod(); //You are able to access me directly because I am static
	}
}
