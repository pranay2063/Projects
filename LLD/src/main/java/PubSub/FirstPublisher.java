package PubSub;

public class FirstPublisher implements Publisher {
    @Override
    public void publish(Broker broker, String message) {
        broker.onMessage(new Message(message));
    }
}
