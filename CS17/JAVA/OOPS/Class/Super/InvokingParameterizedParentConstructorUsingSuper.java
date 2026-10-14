/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class parent{
	parent(){
		System.out.println("Parent constructor is invoked");
	}
	
	parent(String str){
		System.out.println("Parameterized parent constructor is invoked : "+str);
	}
}

class child extends parent{
	child(){
		super("LOL");
		System.out.println("Non-parameterised child constructor is invoked");
	}
	
	child(int a){
		super("LLOL");
		System.out.println("parameterised child constructor is invoked");
	}
}

class InvokingParameterizedParentConstructorUsingSuper
{
	public static void main (String[] args)
	{
		new child();
		//Parent constructor is invoked
		//Non-parameterised child constructor is invoked
		new child(10);
		//Parent constructor is invoked
		//parameterised child constructor is invoked
	}
}
