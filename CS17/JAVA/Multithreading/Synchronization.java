
class Sender {
    public void send(String message){
        try{
            System.out.println(message);
            Thread.sleep(5000);
            System.out.println(message+" sent");
        }
        catch (Exception e){
            System.out.println("Exception Occurred in send method of Sender class");
        }
    }
}

class Receiver extends Thread {
    String message;
    Sender obj;

    Receiver(String message, Sender obj){
        this.message = message;
        this.obj = obj;
    }

    @Override
    public void run(){
        synchronized (obj){
            obj.send(message);
        }
    }
}

class Synchronization {
    public static void main(String[] args){
        Sender obj = new Sender();
        Receiver r1 = new Receiver("Hello", obj);
        Receiver r2 = new Receiver("Bye", obj);
        r1.start();
        r2.start();

        /*
        Output without synchronized -
        Hello
        Bye
        Bye sent
        Hello sent

        Output with synchronized -
        Hello
        Hello sent
        Bye
        Bye sent
         */
    }
}
