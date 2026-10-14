/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class DataTypes
{
	public static void main (String[] args) throws java.lang.Exception
	{
		System.out.println("Hello World");
		boolean flag = true;
		char ch = 'A'; // size : 2 bytes
		byte b = 111; // -128 to 127 (size : 1 byte)
		short snum = 30000; // -32,768 to 32767 (size : 2 bytes)
		int num = 2000000000; //-2,147,483,648 to 2,147,483,647 (size : 4 bytes)
		long lnum = 9000000000000000000L; // -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (size : 8bytes)
		float fnum = 33949.45f; //(4 bytes, 6 to 7 decimal digits)
		double dnum = 123384.3d; //(8 bytes, 15 decimal digits)
		String str = "Pranay Ranjan";
		
		System.out.println(flag+" "+ch+" "+b+" "+snum+" "+num+" "+lnum+" "+fnum+" "+dnum+" "+str);
		//Hello World
		//true A 111 30000 2000000000 9000000000000000000 33949.45 123384.3 Pranay Ranjan
	}
}
