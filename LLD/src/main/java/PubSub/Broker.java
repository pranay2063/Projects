package PubSub;

public interface Broker {

    void addSubscriber(Subscriber subscriber);
    void removeSubscriber(Subscriber subscriber);
    void onMessage(Message message);

}
