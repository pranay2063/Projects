package PubSub;

import java.util.HashSet;

/**
 * TopicBroker implements observer design pattern to keep track of subscribers
 * When a publisher publishes a message, the message is broadcast to all the subscribers
 */
public class TopicBroker implements Broker {

    HashSet<Subscriber> subscribers;

    TopicBroker(){
        subscribers = new HashSet<>();
        subscribers.add(new FirstSubscriber());
        subscribers.add(new SecondSubscriber());
    }

    @Override
    public void addSubscriber(Subscriber subscriber){
        subscribers.add(subscriber);
    }

    @Override
    public void removeSubscriber(Subscriber subscriber){
        subscribers.remove(subscriber);
    }

    @Override
    public void onMessage(Message message){
        subscribers.forEach(subscriber -> subscriber.consume(message));
    }

}
