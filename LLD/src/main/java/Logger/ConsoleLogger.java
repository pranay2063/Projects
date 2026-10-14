package Logger;

import java.util.Date;

public class ConsoleLogger implements LogSink {
    @Override
    public void log(LogLevel logLevel, String message) {
        System.out.println("CONSOLE " + logLevel + ": [" + new Date() + "] " + message);
    }
}
