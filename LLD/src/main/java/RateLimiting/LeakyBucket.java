package RateLimiting;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Leaky bucket keeps the requests in a queue with have a max capacity
 * Requests are processed from the queue with the processingRate
 * If the queue is full, a new request is dropped
 */
public class LeakyBucket implements RateLimiter {

    private BlockingQueue<Request> queue;
    private Integer capacity;
    private int processingRate;

    public LeakyBucket(int capacity, int processingRate){
        this.capacity = capacity;
        this.processingRate = processingRate;
        queue = new LinkedBlockingQueue<>();
    }

    @Override
    public void acceptRequest(Request request) throws InterruptedException {
        if(queue.size() < this.capacity){
            System.out.println("Request accepted successfully: "+request.getMessage());
            queue.put(request);
        }
        else {
            System.out.println("Request dropped: "+request.getMessage());
        }
    }

    public void processRequest(){
        AtomicInteger consumed = new AtomicInteger(0);
        while (!queue.isEmpty() && consumed.get() < processingRate){
            System.out.println("Request consumed successfully: "+ queue.poll().getMessage());
            consumed.incrementAndGet();
        }
    }

}
