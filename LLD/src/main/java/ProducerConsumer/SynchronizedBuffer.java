package ProducerConsumer;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Synchronized buffer does concurrency control and make the thread wait if buffer is full or empty
 */
public class SynchronizedBuffer implements Buffer {

    Queue<Message> queue;
    int capacity;

    SynchronizedBuffer(int capacity){
        this.capacity = capacity;
        queue = new LinkedList<>();
    }

    @Override
    public void produce(Message message) throws InterruptedException {
        synchronized (this) {
            if(queue.size() == capacity){
                System.out.println("Buffer full! Waiting for consumer to consume message");
                this.wait();
            }
            queue.add(message);
            System.out.println("Produced message "+message.getContent()+" successfully");
            this.notify();
        }
    }

    @Override
    public void consume() throws InterruptedException {
        synchronized (this){
            if(queue.isEmpty()){
                System.out.println("Buffer empty! Waiting for producer to produce message");
                this.wait();
            }
            System.out.println("Consumed message "+queue.remove().getContent()+" successfully");
            this.notify();
        }
    }

}
