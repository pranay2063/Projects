/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class ExceptionArithmetic
{
	public static void main (String[] args) throws java.lang.Exception
	{
		//Scanner input = new Scanner(System.in);
		
		int num1, num2;
		
		try{
			num1 = 0; num2 = 70;
			System.out.println("num2/num1 = "+(num2/num1));
			System.out.println("You have reached the end of TRY");
		}	
		catch(ArithmeticException e){
			System.out.println("Exception : Division by zero is not allowed");
		}
		catch(Exception e){
			System.out.println("An exception occured!!!");
		}
	}
}
