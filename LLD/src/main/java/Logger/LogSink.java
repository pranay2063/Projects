package Logger;

public interface LogSink {

    void log(LogLevel logLevel, String message);

}
