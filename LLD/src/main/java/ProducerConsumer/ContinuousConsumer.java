package ProducerConsumer;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ContinuousConsumer implements Consumer {
    @Override
    public void consume(Buffer buffer) {
        Runnable runnable = () -> {
          while (Boolean.TRUE){
              try {
                  buffer.consume();
              } catch (InterruptedException e) {
                  throw new RuntimeException(e);
              }
          }
        };
        ExecutorService executorService = Executors.newFixedThreadPool(2);
        executorService.submit(runnable);
    }
}
