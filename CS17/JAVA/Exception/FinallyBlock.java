/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class FinallyBlock
{
	
	public static int myMethod(){
		try{
			System.out.println("Inside try block of called method");
			return 112;
		}
		finally{
			System.out.println("We have reached finally block");
			System.out.println("Finally block is getting executed even if return statemnent is present");
		}
		//Finally block overrides the value returned by try and catch blocks
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		
		//finally can be present without a CATCH block, TRY is a necessity
		
		FinallyBlock.myMethod();
		//Inside try block of called method
		//We have reached finally block
		//Finally block is getting executed even if return statemnent is present
		
		try{
			System.out.println("SYSTEM EXIT: Inside try block");
			System.exit(0);
		}
		finally{
			System.out.println("We have to reached finally block");
			System.out.println("FINALLY : SYSTEM EXIT");
		}
		//SYSTEM EXIT: Inside try block
	}
}
