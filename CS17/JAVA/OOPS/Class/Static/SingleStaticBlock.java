/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

//Single static block
class SingleStaticBlock
{
	static int num;
	static String str;
	static{
		num = 97;
		str = "We shall overcome";
	}
	public static void main (String[] args) 
	{
		System.out.println(num); //97
		System.out.println(str); //We shall overcome
	}
}
