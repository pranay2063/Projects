
import java.util.*;
import java.lang.*;
import java.io.*;

class QuickSortImplementation
{
	//Best case  - O(N) (Randomized quicksort)
	//Average case - O(NlogN) 
	//Worst Case - O(N^2) (When array is sorted or all elements are equal)
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
	
	public static int partition(int a[], int start, int end){
		//CLRS
		int pivot = end; //take last element as pivot
		int i = start;
		for(int j = start; j < end; ++j){
			if(a[j] <= a[pivot]){
				if(i != j){
					a[i] = a[i]+a[j];
					a[j] = a[i]-a[j];
					a[i] = a[i]-a[j];	
				} 
				++i;
			}
		}
		//swap a[i] and a[pivot]
		if(i != pivot){
			a[i] = a[i]+a[pivot];
			a[pivot] = a[i]-a[pivot];
			a[i] = a[i]-a[pivot];
		}
		return i;
	}
	
	public static void quickSort(int a[], int start, int end){
		if(start >= end) return;
		int pivot = partition(a, start, end);
		//disp(a);
		//System.out.println("calling "+start+" "+(pivot-1));
		quickSort(a, start, pivot-1);
		//System.out.println("calling "+(pivot+1)+" "+end);
		quickSort(a, pivot+1, end);
	}
	
	public static void main (String[] args) 
	{
		int[] a = new int[N];
		randomGenerator(a);
		disp(a);
		quickSort(a, 0, N-1);
		disp(a);
	}
}
