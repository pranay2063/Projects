/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class MergeSortImplementation
{
	
	private static int N = 5;
	
	public static void disp(int[] a){
		for(int i : a) 
			System.out.print(i+" ");
		
		System.out.println();
	}
	
	public static void randomGenerator(int[] a){
		for(int i = 0; i < a.length; ++i){
			Random rand = new Random();
			a[i] = rand.nextInt(200000)-100000; //random numbers between -100000 to 100000
		}
	}
	
	public static void merge(int a[], int start, int mid, int end){
		
		if(a[mid] <= a[mid+1]) return ; //no merge required as array is sorted
		
		int[] x = new int[mid-start+1]; //copy first subarray a[start...mid] into x
		int[] y = new int[end-mid]; //copy second subarray a[mid+1...end] into y
		
		for(int i = 0; i < x.length; ++i) x[i] = a[start+i];
		for(int i = 0; i < y.length; ++i) y[i] = a[mid+1+i];
		
		int i = 0, j = 0, k = start;
		while(i < x.length && j < y.length){
			if(x[i] <= y[j]) a[k++] = x[i++];
			else a[k++] = y[j++];
		}
		
		while(i < x.length) a[k++] = x[i++];
		while(j < y.length) a[k++] = y[j++];
		
	}
	
	public static void mergeSort(int a[], int start, int end){
		if(start >= end) return ;
		int mid = (start+end)/2;
		mergeSort(a, start, mid);
		mergeSort(a, mid+1, end);
		merge(a, start, mid, end);
	}
	
	public static void main (String[] args)
	{
		int[] a = new int[N];
		randomGenerator(a);
		disp(a);
		mergeSort(a, 0, N-1);
		disp(a);
	}
}
