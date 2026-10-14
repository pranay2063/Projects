**1. Design a system like Jira** 

    It should have the following functionalities :
    User should be able to create Task of type Story, Feature, Bugs. Each can have their own status.
    Stories can further have subtracts.
    Should be able to change the status of any task.
    User should be able to create any sprint. Should be able to add any task to sprint and remove from it.
    User should be able to print
    Delayed task
    Sprint details
    Tasks assigned to the user
        
**2. Task Planner System**

    Implement a Task Planner System.
    Sprint, story, task, epic, sub story etc. 
    Basic functionalities like create new sprint, delete sprint. 
    change assignee.
    Change task status etc. 
    Code should be modular and extensible.
    
**3. Ride sharing system**

    Design offerRide and shareRide mechanism on basis of fastest and earliest ride

    Create an application that will add user and add their vehicle, there will be two categories one who is offering ride and other who is selecting ride.

    offerRide(user_name, vehicle_no, origin, destination, start_time, duration)
    selectRide(user_name, origin, destination, parameter)

    return parameter is fastest ride which will be on shortest duration

**4. System for cab company (aggregator)**
    
    Design a simple solution for a cab company. Queries are given, output the correct values corresponding to it.

    Q1 : AVG DriverID => give the average rating points for the driver ID given
    Q2 : AVG CustomerID => give the average rating points for the customer ID given
    Q3 : TRIP CustomerID Rating DriverID Rating => Add the trip and rating points with customerID and driverID
    Q4 : TOP Drivers => List the top drivers sorted according to the rating points
    Q5 : TOP Customers => List the top customers sorted according to the rating points
    Q6 : ELIGIBLE CustomerID => Give the eligible drivers for the customerID. Eligible drivers had the following criteria ->
        (i) The average rating of the driver should be greater than the customer
        (ii) If the customer had given the driver a 1 star rating earlier then this driver is not to be considered
        (iii) If there are no drivers found, print the ones for which the customer had rode earlier

    The initial data was to be hardcoded and the solution was to be designed efficient all edge cases handled and optimised.
    
**5. Multi-level cache system design with different storage in each level**

    Candidates were divided into groups and each group was given different problems to solve. Full working code was required with any candidate’s preferred language. It was 90 min round.

    a. Read Operation : – Minimum time to read a particular key from cache system. This should be followed by writing the key in all levels above it. Eg. if “key” is found at level ‘i’, add this key to cache present at 1 to i-1 level.

    b. Write Operation: – Any write Operation should write  in cache of all levels.
    You can choose any algorithm for cache management like LRU, MRU.

    BONUS POINTS:-

    a. Show the current usage of each level cache.(Number of elements vs total Capacity of cache)
    b. Average read time and average write time.

    There was a long discussion on the code written and several test cases were given to check all boundary conditions.
    
**6. Text line editor**

    Implement a Text Line Editor which supports the following operations:

    Insert a line at a given line number
    Delete the specific set of lines
    Copy specific set of lines
    Paste the copied lines at given index
    Print the entire content
    Bonus-
        Undo command
        Redo command

**7. TextPad**

    I was asked to code a TextPad with following functionality:

    display() – to display the entire content
    display(n, m) – to display from line n to m
    insert(n, text) – to insert text at line n
    delete(n) – delete line n
    delete(n, m) – delete from line n to m
    copy(n, m) – copy contents from line n to m to clipboard
    paste(n) – paste contents from clipboard to line n
    undo() – undo last command
    redo() – redo last command
    They expected the textpad to be in memory(not as file). They also  expected to handle error gracefully and the program to be menu driven.

**8. Best Selling Price**

    You need to make a program in which

    1.) You can add a product -> addProduct(“p1”)
    2.) A user can purchase a product -> purchase(“u1″,”p1”)
    3.) A user can return a product -> returnProduct(“u1″,”p1”)
    4.) A user can be blacklisted and all of his purchases will be marked null -> blackListUser(“u1”)
    5.) Display the best selling product -> bestSelling()
    Best selling product will be the one which have been bought by most number of unique users.

    Bonus: Display the best selling products for each category.

    Evaluation: After you are done with your code, two Flipkart SDEs will run test cases on your code and evaluate it. They will also ask some questions around your code.
    
**9. Binary Tree Sequence**

    Given a binary tree as a sequence of (parent, child) tuples: (A B)(A C)(B G)(C H)(E F)(B D)(C E) Write a program to find following errors in the tree:
    E1: More than 2 children
    E2: Duplicate Tuples
    E3: Cycle present
    E4: Multiple roots
    E5: Multiple parents
    Input is a expression containing parent child relations. output is Error codes or success.

    Sample test cases : 
    Input: (A B)(A C)(B G)(C H)(E F)(B D)(C E) Output: Success
    Input: (A B)(A C)(A D) Output: E1
    Input: (A B)(A B) Output: E2
    Input: (A B)(B C)(C A) Output: E3
    Input: (A B)(C D) Output: E4
    Input: (A B)(B C)(A C) Output: E5
    
**10. JSON Constructor**

    You are given some equations which may contain > or = on different-different operand. For example there are valid input and invalid (a=5, b<a=50)

     String e1 = "a>b=1";
     String e2 = "a>b=2";
     String e3 = "a>c>e=3";
     String e4 = "a>c>f=4";
     String e5 = "b>a=5";
     String e6 = "a>b>c=5";
     String e7 = "b=7";
     String e8 = "a>b>c>d=99";
     String e9 = "a>b=99";

    You need to create JSON string from it. 
    {
     ‘a’: {
        ‘b’: [1,2,99],
        ‘c’: {
            ‘e’:3,
            ‘f’:4
             }
         },

     ‘b’: {
        ‘a’ : 5
          }
    }
    
    Highlighted one is invalid because they come they ask for overwrite the data (a>b>c = 5; C has e and f so we can overwrite.

    Input: You are given those string in string array
    Output: Construct JSON, Print it
    If you print in same manner as above (nice manner) +point

    I solved this problem using Trie. 
    One can see interviewee's implementation here: https://github.com/nitsgupta/practice/tree/master/JAVA/JsonBuilder
  
**11. Finite State Machine**

    Implement a finite state machine.
    – The machine should have one start state and can have multiple end states
    – It should be extensible (I should be able to add any number of states or transitions at any time)
    – I should be able to set notifications on or off for any state or for the whole state machine
    
**12. Regular Expressions**

    In a regular expression, * represents 0 or more repetitions for preceding character. & represents the regex preceeding it is at the end of string. and all small case letters represent themselves. For example:

    rat&
    Pass: bigrat, smallrat
    Fail: ratoulite rats

    a*b
    Pass: b, ab, aab
    Fail a, asd

    abc
    Pass: abc, abcd zabcd
    Fail: abdc, dabfc

    Write a code for it.
    
**13. Design snake and ladder game**

    Design snake and ladder game. Questions were then asked on how it can be extended. 
    
    BONUS (System design of same problem):
    Design snakes and ladders game (multiplayer). Extend it so that it can be hosted over a server and played over a server.
    
**14. Tic Tac Toe Game**
    
    1. Design and build tic tac toe game. The code should be up and running. It should be scalable to multi-users and nXn grid.    
    
    2. Write a running code in any language to implement the famous tic-tac-toe game.
       First, there was a discussion on various approaches and basic functions which would be required to implement the same. Then I was asked to code.
       I was given 1 hour 15 mins to code this. I had to design this game as per following:
       Game has 3 modes: Human Vs Human, Human Vs Computer and Computer Vs Computer.
       Initially start with a 3X3 grid, but it can be generalised to NXN grid. So don’t hardcode any variable.
       Minimise Code Redundancy and try to make it as modular as possible.
       Try to use abstraction and expose a lesser number of functions(APIs) to the outside world.
       Try to cover maximum number of edge cases, like when to abort the game, draw condition, win condition, overwriting the existing value in grid etc)
       After I wrote running code for the same, I was told to explain my code and then run with some test cases. Then he asked me to mail the code.

**15. Two player multiple ships game**

    1. Machine Coding:
        Two players, two field; and have multiple ships located in their fields. They are guessing each others ship position and        hitting. 
        Tell who wins first. Design maintainable code which can incorporate future change.

    2. Discussion on Design of previous code. 
        A lot of new use cases to handle. 
        Explain your design. 
        How will you deal with new changes in problem statements.
        
**16. N player game of cards**

    I was given a problem statement and I had to write a fully functional working code at my laptop. 
    I was told that the focus is not on logic but on the way I code and the design of my solution. 
    
    The problem statement was something like : 
    There is a n player game of cards. 
    The deck of card is not fair, i.e. any card can be there any number of times. 
    A card has a number and a color. Each player gets k card each (n and k can be harcoded in the solution). 
    The computer starts the game by throwing a card from the deck of cards. Assume the card is 4 of Green. 
    Then the other player has to throw either a 4 of any color or Green of any number. 
    If the player does not have any such card, then it can say pass. 
    The player who finishes all his card wins. 
    The logic of selecting the card by the user can be hardcoded (Eg, If you use a list data structure for storing the cards for a           player, then you can say that the player always throws the first card from the list). 
    The logic was required only to start and conclude the game.

    I was given close to 1 hour to finish this. First we had a discussion about the design of my solution and then I was asked to code.     After I was done coding, she checked my code, asked a few questions about how will I add some new features in the game.
    
**17. Employee Hierarchy**

    Round 1. Machine coding round
    Maintain an employee hierarchy with attributes 
    Print complete hierarchy of given employee.
    find top 10 employees on the basis of salary, at any instant of time .
    Perform CRUD opérations on the hierarchy.

    They measure you performance on following:
    Code should be running
    time limit is 1:30 minutes.
    Appropriate data structures used.
    optimized and modular code.

    Round 2: Technical
    Optimize the code done in machine coding round
        A lot of discussion on the approach I used. Various edge case discussions.
        
**18. Company hierarchy**
    
    Company hierarchy/bonus question.
    Write down the code in any language for a simple employee hierarchy which has 3 types of employees.
    CEO
    Manager
    Employee
    Where an employee can have only 1 mgr, and a mgr has 1+ employees.
    We were asked to input employee details(name, id, salary, rating etc) in any order (employees might be input before his manager), create the hierarchy and implement these functionalities:

    Print hierarchy given any employee/mgr/CEO (used an n-ary tree + hash table)
    Given a bonus and performance rating of each employee divide it to the lowest level employees(in the hierarchy ) in the ratio of their rating. i.e 100 divided among 2:3 is 40 and 60. and print the bonus of each ( simple recursive solution)
    Top 10 employees with ratio of bonus:salary (used maxheap)
    Had a discussion on the solution with various variants and edge/faulty cases.

**19. Book Catalogue Search**

    Design a book catalogue search (API’s were given for the search, full needs to be implemented as running application).
    Discussion on the design and optimization of the application.
    
**20. Snake and ladder problem**

    Design the snake and ladder write - https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0
    The full working code was required. They gave us more than 2 hours to complete.
    Discussion on the code written and how i have implemented.
    
**21. Simple employee hierarchy**

    Write down code in any language for a simple employee hierarchy which has 3 types of employees.
    CEO
    Manager
    Employee
    where an employee can have only 1 mgr, and a mgr has 1+ employees.

    We were asked to input employee details(name, id, salary, rating etc) in any order (employees might be input before his manager), create the hierarchy and implement these functionalities:

    Print hierarchy given any employee/mgr/CEO (used an n-ary tree + hash table)
    Given a bonus and performance rating of each employee divide it to the lowest level employees(in the hierarchy ) in the ratio of their rating. i.e 100 divided among 2:3 is 40 and 60. and print the bonus of each ( simple recursive solution)
    Top 10 employees with ratio of bonus:salary (used maxheap)
    Write working code, modular, extensible, corner case handling etc. was around 1.5 – 2 hrs
    
    Discussion on your solution of the 1st round, how you can optimize it, then a review of the written code.
    
**22. Book catalogue system**

    You are given a catalog of books, which have following attributes.
    Name
    Author
    Publisher
    Publish year
    Category
    Price
    Count (sold)
    Implement following APIs on top of this catalog

    addBookToCatalog(Book)
    searchBook(by partial book name/author)
    getMostSoldBooks(by author name/category, limit)
    Expectations:

    Maintain DB on memory
    Code should be readable. Design, handle naming convention,handle exceptions & should be running.
    
    Discussion on design (interfaces & extension)
    Discussion on data structures (trie)
    Discussion on sorting
    
**23. Operations on large numbers**

    Problem was to do 3 operations on very large numbers.
    Addition
    Subtraction
    Multiplication
    Input can be positive or negative. In this round, the focus was on Design and Coding Skills.
    
    I was given 1 hr 30 mins to code for the problem. I completed in around 1hr 15 mins. Then he asked me to extend my code for decimal numbers as well. I told him the approach. Then he asked me how will I do the division as well.
    
**24. Operations on numbers (same as 23)**

    Given two very large numbers a & b in string format. You need to produce the result for the following operation:
    0: Add a & b
    1: Subtract a & b
    2: Multiply a & b
    Example:
    123456789
    987654321

    Output:
    0 → 1111111110
    1 → -864197532
    2 → 1219326313718945259

    Few cases were checked specifically:

    Output of 132-132 must be 0 not 000.
    2 – 122222000002 should produce -122222000000 i.e either a or b can be the bigger string.
    Negative input should be handled. Result of -2+202 = 200.
    1000000000 – 1 = 999999999 i.e. resulting answer can be of different length.
    
**25. Employee database**
 
    Create an employee database structure in which Employee has id, name, manager. Three functionalities required were
    a) Given any id return all the employee details
    b) Given any name(or id) list all the subordinates of the given employee.
    c) Given a name search with prefix search property.
    45 minutes of time was given and running code was asked. The interviewer first asked the approach and then after coding, he reviewed the code thoroughly.

**26. Organizational hierarchy**

    Need to write a fully functionally and working code for a problem statement. 
    Problem is to write the code for maintaining a directory for any organization where the employee will have id, name, post and manager as an attribute. 
    Basically, two features need to be implemented: 
    (a) Should be able to do searching on the basis of name, prefix search for the name should also be supported 
    (b) For any employee, we can get the list of all the subordinates which comes under him/her, like for CEO all the employee’s list should get displayed
    
    No database is needed, memory storage was asked to use for this
    Code should be extendable so that new attributes for the employee can be added
    Approach for maintaining the structure and optimality in searching for required.
    
**27. Parse Tree**

    Write a program which should create a parse tree, find invalid query and do some optimizations.
    Input: fist line contains the list of columns. There will be subsequent lines which will contain the query as follows.
    
    EMP_ID, EMP_NAME, EMP_DEPT, EMP_AGE
    
    SELECT EMP_ID,EMP_NAME where EMP_ID>5 AND EMP_NAME=’robert’
    
    SELECT EMP_AGE WHERE (EMP_NAME=’robert’ AND EMP_ID=5) AND 
                        (EMP_ID=32) OR (EMP_ID= 32) 

**28. XML parser**

    I was asked to write code to parse an XML and do the following options by not hardcoding any value.
    Validate the XML.
    Given a level number, print all values of tags in the sub-levelsel.
    Search a tag name for a given value
    For value of any tag given, search a value of tag at any sub levels.
    
    First there was discussion as to how to go about the problem and the algorithm. Then 1 hour for coding the solution. Finally the code was evaluated and some extensions to the solutions were discussed.
    
**29. Regex parser (same as 12)**

    Given a string regex and anothe ther string pat find whether the pattern is acceptable against given regex string.
    Regex string contains following characters and special characters:
    
    1. Normal alphabets – a to z and A to Z
    
    2. ‘$’ – all string should end with all characters preceding $
    Example:
    Regex :abc$ ,
    Pattern: abcd(Not acceptable) , abc(acceptable), ab(Not acceptable), dhfusdhabc(acceptable) etc..
    
    3. ‘^’ – all string should start with all characters exceeding ^
    Example: Regex : ^abc
    Pattern: abcd(acceptable) , abc(acceptable), ab(Not acceptable), dhfusdhabc(NOT acceptable) etc..
    Regex: ^ then only pattern acceptable is null.
    
    4. ‘.’ – any character can be mapped to dot except null
    Example 1: Regex : .abc
    Pattern: Zabc(acceptable) , abc(NOT acceptable), ab(Not acceptable), habc(acceptable) etc..
    Example 2: Regex :a.bc
    Pattern: abc(NOT acceptable) , aXbc(acceptable), ab(Not acceptable), habc(NOT acceptable) etc..
    
    5. ‘*’-the character just preceding * can be repeated n time where (n>=0)
    Example 1: Regex :abc*de
    Pattern: abccccccccccde (acceptable), abcde(acceptable), abcccd(not acceptable)
    
    Code should follow OOPs principle such as modularity (make each function for each special character), encapsulation etc.
    Further discussion on improving the code and how would other person can see the code and add other functions to it.
    
