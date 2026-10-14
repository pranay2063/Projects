
## Problem Statement

1. User should be able to log a message based on the log level
2. Logger implementation should handle multiple log sinks like console, log, db, etc

## Possible Approaches

1. Using factory and observer design patterns <br>
  1.1 Factory is used to create Logger object <br>
  1.2 Observer is used to keep a track of all the log sinks (console, file, db) and update all of them for any log request <br>

2. Chain of responsibility pattern <br>
  2.1 https://www.tutorialspoint.com/design_pattern/chain_of_responsibility_pattern.htm <br>
  2.2 There is an abstract logger class which tracks next logger handler and has a log method <br>
  2.3 There will be multiple extensions of logger class based on the log sink type <br>
  2.4 Each extension sets next logger and adds the implementation of log method <br>
  
