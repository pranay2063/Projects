package ProducerConsumer;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

/**
 * This is an implementation of producer consumer using the Java standard data structure BlockingQueue
 * This is just for understanding purpose
 */
public class BlockingQueueBuffer implements Buffer {

    BlockingQueue<Message> blockingQueue;

    BlockingQueueBuffer(int capacity){
        blockingQueue = new LinkedBlockingQueue<>(capacity);
    }

    @Override
    public void produce(Message message) throws InterruptedException {
        blockingQueue.put(message);
        System.out.println("Produced message "+message.getContent()+" successfully");
    }

    @Override
    public void consume() throws InterruptedException {
        Message message = blockingQueue.take();
        System.out.println("Consumed message "+message.getContent()+" successfully");
    }
}
