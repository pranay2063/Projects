import java.util.*;

class MultithreadingClass extends Thread{
    private static int counter = 0;
    @Override
    public void run(){
        try{
            System.out.println("Counter for Thread (Name,Id) ("+Thread.currentThread().getName()+","+Thread.currentThread().getId()+") now is "+counter);
            ++counter;
            System.out.println("Incrementing counter to "+counter);
            Thread.sleep(5000);
            System.out.println("Counter for Thread (Name,Id) ("+Thread.currentThread().getName()+","+Thread.currentThread().getId()+") now is "+counter);
            ++counter;
            System.out.println("Incrementing counter to "+counter);
        }
        catch (Exception e){
            System.out.println("An exception was caught.");
        }
    }
}

class MultithreadingGetIdSetName {
    public static void main(String[] args){
        for(int i = 0; i < 5; ++i){
            MultithreadingClass obj = new MultithreadingClass ();
            obj.setName("Thread "+i);
            obj.start();
        }
    }
}
