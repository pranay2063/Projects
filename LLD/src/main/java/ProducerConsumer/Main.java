package ProducerConsumer;

public class Main {

    public static void main(String[] args){
        Buffer buffer = new SynchronizedBuffer(3);
        Producer producer = new FixedProducer();
        Consumer consumer = new ContinuousConsumer();
        producer.produce(buffer);
        consumer.consume(buffer);
    }

}
