package RateLimiting;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * Token bucket assigns an available token to a request
 * Tokens are refilled with a fixed rate and there is a max capacity of tokens
 * If no token is available, a new request is dropped
 */
public class TokenBucket implements RateLimiter {

    private Integer capacity;
    private Integer refillRate;
    private AtomicInteger currentTokens;
    public TokenBucket(int capacity, int refillRate){
        this.capacity = capacity;
        this.refillRate = refillRate;
        this.currentTokens = new AtomicInteger(0);
    }

    public void incrementToken(){
        if(currentTokens.get() < capacity) {
            currentTokens.addAndGet(refillRate);
            if (currentTokens.get() > capacity) {
                currentTokens.set(capacity);
            }
            System.out.println("Current tokens: " + currentTokens.get());
        }
    }

    @Override
    public void acceptRequest(Request request) {
        if(currentTokens.get() > 0){
            System.out.println("Processed request: "+request.getMessage());
            currentTokens.decrementAndGet();
        }
        else {
            System.out.println("No token, dropping request: "+request.getMessage());
        }
    }
}
