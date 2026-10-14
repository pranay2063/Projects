package Logger;

import java.util.Date;

public class FileLogger implements LogSink {
    @Override
    public void log(LogLevel logLevel, String message) {
        System.out.println("FILE " + logLevel + ": [" + new Date() + "] " + message);
    }
}
