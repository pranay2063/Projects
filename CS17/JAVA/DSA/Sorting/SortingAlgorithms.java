/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class SortingAlgorithms
{
	//All the algorithms below are for sorting in ascending order
	public static void disp(int[] a){
		for(int i : a){
			System.out.print(i+" ");
		}
		System.out.println();
	}
	
	public static void randomGenerator(int[] a){
		for(int i = 0; i < a.length; ++i){
			Random rand = new Random();
			a[i] = rand.nextInt(200000)-100000; //random numbers between -100000 to 100000
		}
	}
	
	public static void bubbleSort(int[] a){
		
		for(int i = 0; i < a.length; ++i){
			for(int j = 0; (j+1) < (a.length-i); ++j){
				if(a[j+1] < a[j]){
					//swap without using extra variable
					a[j] = a[j] + a[j+1];
					a[j+1] = a[j] - a[j+1];
					a[j] = a[j] - a[j+1];
				}
			}
		}
		//Number of swaps done in this case is O(n*n)
	}
	
	public static void selectionSort(int[] a){
		
		for(int i = 0; i < a.length; ++i){
			int min_idx = i;
			for(int j = i+1; j < a.length; ++j){
				if(a[j] < a[min_idx]){
					min_idx = j;
				}	
			}
	
			if(i != min_idx){
				//swap without using extra variable
				a[i] = a[i] + a[min_idx];	
				a[min_idx] = a[i] - a[min_idx];
				a[i] = a[i] - a[min_idx];
			}
			//Number of swaps done in this case is O(n)
		}
		
	}
	
	public static void insertionSort(int[] a){
		
		for(int i = 1; i < a.length; ++i){
			for(int j = i-1; j >= 0 && a[j+1] < a[j]; --j){
				//swap a[j] and a[j+1]
				a[j] = a[j] + a[j+1];
				a[j+1] = a[j] - a[j+1];
				a[j] = a[j] - a[j+1];
			}
		}
		
	}
	
	public static void JavaUtilArraysSort(int[] a){
		Arrays.sort(a);
	}
	
	public static void JavaUtilCollectionsSort(){
		//Collections.sort() expects list as input and does not work for arrays of primitive types
		ArrayList<Integer> arr = new ArrayList<Integer>();
		Random rand = new Random();
		for(int i = 0; i < 5; ++i){
			arr.add(rand.nextInt(200000)-100000);	
			System.out.print(arr.get(i)+" ");
		}
		System.out.println();
		Collections.sort(arr);
		for(int i : arr){
			System.out.print(i+" ");
		}
		System.out.println();
	}
	
	public static void main (String[] args)
	{
		int[] a = new int[5];
		System.out.println("Bubble Sort");
		randomGenerator(a);
		disp(a);
		bubbleSort(a);
		disp(a);
		System.out.println("Selection Sort");
		randomGenerator(a);
		disp(a);
		selectionSort(a);
		disp(a);
		System.out.println("Insertion Sort");
		randomGenerator(a);
		disp(a);
		insertionSort(a);
		disp(a);
		System.out.println("Java Util Arrays Sort");
		randomGenerator(a);
		disp(a);
		JavaUtilArraysSort(a);
		disp(a);
		System.out.println("Java Util Collections Sort");
		JavaUtilCollectionsSort();
	}
}
