package PubSub;

public class FirstSubscriber implements Subscriber {
    @Override
    public void consume(Message message) {
        System.out.println("First subscriber consumed message: "+message.getContent());
    }
}
