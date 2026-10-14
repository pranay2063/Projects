/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class ControlStatements
{
	public static void main (String[] args) throws java.lang.Exception
	{

		//if-else		
		int x = 100;
		
		if(x < 10)
			System.out.println("Below 10");
		else if(x < 100)
			System.out.println("Above 9 and Below 100");
		else System.out.println("Above 100");	
		
		//Switch
		int y = 3;
		switch(y){
			
			case 1: 
				System.out.println("Case 1");
				break;
			case 2:
				System.out.println("Case 2");
				break;
			case 3:
				System.out.println("Case 3");
				break;
			case 4:
				System.out.println("Case 4");
				break;
			case 5:
				System.out.println("Case 5");
				break;
			default:
				System.out.println("Default");
		}
		
		//loops
		for(int i = 0; i < 10; ++i)
			System.out.print(i+" ");
		System.out.println();	
		
		int arr[] = {1, 22, 16, 44};
		for(int i = 0; i < arr.length; ++i)
			System.out.print(arr[i]+" ");
		System.out.println(" ");
		
		System.out.print("Simplified for-loop to iterate in an array :");
		for(int num : arr)
			System.out.print(num+" ");
		System.out.println(" ");	
	
		//There are while-loop and do-while loop also
		//Also continue and break behave same as in C++
		
	}
	
}
