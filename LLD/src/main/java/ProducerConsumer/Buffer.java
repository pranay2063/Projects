package ProducerConsumer;

public interface Buffer {

    void produce(Message message) throws InterruptedException;
    void consume() throws InterruptedException;

}
