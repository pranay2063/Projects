/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class parent{
	parent(){
		System.out.println("Parent constructor is invoked");
	}
}

class child extends parent{
	child(){
		System.out.println("Non-parameterised child constructor is invoked");
	}
	
	child(int a){
		System.out.println("parameterised child constructor is invoked");
	}
}

/* Name of the class has to be "Main" only if the class is public. */
class ConstructorSuper
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
