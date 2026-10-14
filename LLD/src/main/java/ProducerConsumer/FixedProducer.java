package ProducerConsumer;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class FixedProducer implements Producer{
    @Override
    public void produce(Buffer buffer) {
        Runnable runnable = () -> {
            int i = 0;
            while (i++ < 10){
                try {
                    buffer.produce(new Message("Message"+i));
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        };
        ExecutorService executorService = Executors.newFixedThreadPool(2);
        executorService.submit(runnable);
    }
}
