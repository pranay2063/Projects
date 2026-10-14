/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class MultipleExceptions
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner input = new Scanner(System.in);
		
		int arr[] = new int[5];
		for(int i = 0; i < arr.length; ++i)
			arr[i] = input.nextInt();
		
		try{
			for(int i = 0; i <= arr.length; ++i)
				System.out.print((1000/arr[i])+" ");
			System.out.println();
			System.out.println("Execution has reached at the end of TRY block");
		}	
		catch(ArrayIndexOutOfBoundsException e){
			System.out.println("Exception : Accessing array index out of bound is not allowed");
		}
		catch(ArithmeticException e){
			System.out.println("Exception : Division by zero not allowed");
		}
		catch(Exception e){
			//generic catch block
			System.out.println("An exception occured!!!");
		}
	}
}

/*
Input : 1 2 3 4 5
Output : 1000 500 333 250 200 Exception : Accessing array index out of bound is not allowed
Input : 1 2 0 4 5
Output : 1000 500 Exception : Division by zero not allowed
*/
