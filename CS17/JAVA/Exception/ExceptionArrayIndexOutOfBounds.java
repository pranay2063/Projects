/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class ExceptionArrayIndexOutOfBounds
{
	public static void main (String[] args) throws java.lang.Exception
	{
		//Scanner input = new Scanner(System.in);
		
		int arr[] = {1,2,3,4,5};
		
		try{
			for(int i = 0; i <= arr.length; ++i)
				System.out.print(arr[i]+" ");
			System.out.println();
			System.out.println("Execution has reached at the end of TRY block");
		}	
		catch(ArrayIndexOutOfBoundsException e){
			System.out.println("");
			System.out.println("Exception : Accessing array index out of bound is not allowed");
		}
		catch(Exception e){
			//generic catch block
			System.out.println("An exception occured!!!");
		}
	}
}

//1 2 3 4 5 
//Exception : Accessing array index out of bound is not allowed
 
