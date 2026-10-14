/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class SortingAlgorithmsPerformance
{
	//All the algorithms below are for sorting in ascending order
	private static long nano = 1000000000;
	private static int N = 100000;
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
	
	public static float bubbleSort(){
		
		int[] a = new int[N];
		randomGenerator(a);
		long startTime = System.nanoTime();
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
		long endTime = System.nanoTime();
		//Number of swaps done in this case is O(n*n)
		return (float)(endTime-startTime)/nano;
	}
	
	public static float selectionSort(){
		
		int[] a = new int[N];
		randomGenerator(a);
		long startTime = System.nanoTime();
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
		long endTime = System.nanoTime();
		return (float)(endTime-startTime)/nano;
	}
	
	public static float insertionSort(){
		
		int[] a = new int[N];
		randomGenerator(a);
		long startTime = System.nanoTime();
		for(int i = 1; i < a.length; ++i){
			for(int j = i-1; j >= 0 && a[j+1] < a[j]; --j){
				//swap a[j] and a[j+1]
				a[j] = a[j] + a[j+1];
				a[j+1] = a[j] - a[j+1];
				a[j] = a[j] - a[j+1];
			}
		}
		long endTime = System.nanoTime();
		return (float)(endTime-startTime)/nano;
	}
	
	public static float JavaUtilArraysSort(){
		int[] a = new int[N];
		randomGenerator(a);
		long startTime = System.nanoTime();
		Arrays.sort(a);
		long endTime = System.nanoTime();
		return (float)(endTime-startTime)/nano;
	}
	
	public static float JavaUtilCollectionsSort(){
		//Collections.sort() expects list as input and does not work for arrays of primitive types
		ArrayList<Integer> arr = new ArrayList<Integer>();
		Random rand = new Random();
		for(int i = 0; i < N; ++i){
			arr.add(rand.nextInt(200000)-100000);	
		}
		System.out.println();
		long startTime = System.nanoTime();
		Collections.sort(arr);
		long endTime = System.nanoTime();
		return (float)(endTime-startTime)/nano;
	}
	
	public static void main (String[] args)
	{
	
		//System.out.println("Bubble Sort : "+bubbleSort()+" seconds");
		//System.out.println("Selection Sort : "+selectionSort()+" seconds");
		//System.out.println("Insertion Sort : "+insertionSort()+" seconds");
		System.out.print("Java Util Arrays Sort : "+JavaUtilArraysSort()+" seconds");
		System.out.println("Java Util Collections Sort : "+JavaUtilCollectionsSort()+" seconds");
	}
}
