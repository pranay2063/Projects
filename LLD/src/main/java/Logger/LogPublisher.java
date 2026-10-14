package Logger;

public interface LogPublisher {

    void addLogSink(LogSink logSink);
    void removeLogSink(LogSink logSink);
    void notifyAll(LogLevel logLevel, String message);

}
