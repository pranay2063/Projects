package RateLimiting;

import java.util.UUID;

public class Request {

    UUID requestID;
    String message;

    String user;

    public Request(String message, String user){
        this.requestID = UUID.randomUUID();
        this.message = message;
        this.user = user;
    }

    public UUID getRequestID() {
        return requestID;
    }

    public void setRequestID(UUID requestID) {
        this.requestID = requestID;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public String getUser() {
        return user;
    }

    public void setUser(String user) {
        this.user = user;
    }

}
