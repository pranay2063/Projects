package PubSub;

public class SecondSubscriber implements Subscriber {
    @Override
    public void consume(Message message) {
        System.out.println("Second subscriber consumed message: "+message.getContent());
    }
}
