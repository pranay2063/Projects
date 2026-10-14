package RateLimiting;

public interface RateLimiter {

    public void acceptRequest(Request request) throws InterruptedException;

}
