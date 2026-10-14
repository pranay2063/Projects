package PubSub;

public class Main {

    public static void main(String[] args){
        Broker broker = new TopicBroker();
        Publisher publisher = new FirstPublisher();
        publisher.publish(broker, "Hello from first publisher");
    }

}
