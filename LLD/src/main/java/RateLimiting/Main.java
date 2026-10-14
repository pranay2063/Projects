package RateLimiting;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {

    public static void callLeakyBucket() {

        System.out.println("***LEAKY BUCKET***");

        LeakyBucket leakyBucket = new LeakyBucket(3, 1);

        Runnable acceptTask = () -> {
            Request request;
            int count = 0;
            while (count < 10){
                request = new Request("Request"+count, "User"+count++);
                try {
                    leakyBucket.acceptRequest(request);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        };

        Runnable processTask = () -> {
            while (Boolean.TRUE){
                leakyBucket.processRequest();
            }
        };

        ExecutorService executorService = Executors.newFixedThreadPool(2);
        executorService.submit(acceptTask);
        executorService.submit(processTask);

    }

    public static void callTokenBucket(){

        System.out.println("***TOKEN BUCKET***");

        TokenBucket tokenBucket = new TokenBucket(3, 1);

        Runnable acceptTask = () -> {
            Request request;
            int count = 0;
            while (count < 10){
                request = new Request("Request"+count, "User"+count++);
                tokenBucket.acceptRequest(request);
            }
        };

        Runnable incrementTokenTask = () -> {
            int i = 0;
            while (i++ < 5){
                tokenBucket.incrementToken();
            }
        };

        ExecutorService executorService = Executors.newFixedThreadPool(2);
        executorService.submit(incrementTokenTask);
        executorService.submit(acceptTask);

    }

    public static void main(String[] args) {

        //callTokenBucket();
        callLeakyBucket();

    }

}
