package Logger;

import java.util.ArrayList;

public class Logger implements LogPublisher {

    ArrayList<LogSink> logSinks;

    Logger(){
        logSinks = new ArrayList<>();
    }

    public void trace(String message){
        notifyAll(LogLevel.TRACE, message);
    }

    public void debug(String message){
        notifyAll(LogLevel.DEBUG, message);
    }

    public void info(String message){
        notifyAll(LogLevel.INFO, message);
    }

    public void warn( String message){
        notifyAll(LogLevel.WARN, message);
    }

    public void error(String message){
        notifyAll(LogLevel.ERROR, message);
    }

    @Override
    public void addLogSink(LogSink logSink) {
        logSinks.add(logSink);
    }

    @Override
    public void removeLogSink(LogSink logSink) {
        logSinks.remove(logSink);
    }

    @Override
    public void notifyAll(LogLevel logLevel, String message) {
        logSinks.forEach(logSink -> logSink.log(logLevel, message));
    }
}
