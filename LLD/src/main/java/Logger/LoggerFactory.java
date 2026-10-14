package Logger;

public class LoggerFactory {
    private static volatile Logger logger;

    public static Logger getLogger(){
        if(logger == null){
            synchronized (LoggerFactory.class){
                if(logger == null){
                    logger = new Logger();
                    logger.addLogSink(new ConsoleLogger());
                    logger.addLogSink(new FileLogger());
                }
            }
        }
        return logger;
    }

}
