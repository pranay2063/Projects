/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

//THROWS does the same job as TRY-CATCH
//It is more effective when there are multiple methods having exception scenarios as it will be tedious to write TRY-CATCH inside all of them
class ExceptionHandlingThrows
{

	public void example(int a, int b) throws Exception{
		int div = b/a;		
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		ExceptionHandlingThrows obj = new ExceptionHandlingThrows();
		try{
			obj.example(0,10); //java.lang.ArithmeticException: / by zero
		}
		catch(Exception e){
			System.out.println(e);
		}
	}
}
