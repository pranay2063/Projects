/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Incident 
{
	int ID;
	String desc;
	int priority;
	
	Incident(int ID, String desc, int priority){
		this.ID = ID;
		this.desc = desc;
		this.priority = priority;
	}
	
	void display(){
		//map priority from numeric to string
		String temp = "default";
		switch(this.priority){
			case 0: temp = "Very High"; break;
			case 1: temp = "High"; break;
			case 2: temp = "Medium"; break;
			case 3: temp = "Low"; break;
		}
		
		System.out.println("Issue : "+this.desc+" and its priority is "+temp);
	}
	
	public static void main (String[] args)
	{
		Random rand = new Random();
		Incident obj1 = new Incident(rand.nextInt(1000000), "BCO Activation Issue", 0);
		Incident obj2 = new Incident(rand.nextInt(1000000), "Tenant Precheck", 1);
		obj1.display();
		obj2.display();
	}
}
