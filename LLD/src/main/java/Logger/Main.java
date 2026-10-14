package Logger;

public class Main {

    public static void main(String[] args){
        Logger logger = LoggerFactory.getLogger();
        logger.info("I am here");
        logger.debug("Debugging some issue");
        logger.warn("This is a warning. Please take a note.");
        logger.error("Encountered an error");
    }

}
