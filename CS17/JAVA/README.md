
**JDK, JRE, JVM**

      https://www.geeksforgeeks.org/differences-jdk-jre-jvm/
      JIT compiler - https://www.geeksforgeeks.org/just-in-time-compiler/

**JVM and ClassLoader internals**

      https://www.turing.com/kb/guide-to-the-basics-of-classloader
      https://www.geeksforgeeks.org/jvm-works-jvm-architecture/
      G1GC https://www.dynatrace.com/news/blog/understanding-g1-garbage-collector-java-9/

**JAVA Basics**

      https://beginnersbook.com/2013/05/java-introduction/

      Why is main static in Java? - 
      
            https://stackoverflow.com/questions/146576/why-is-the-java-main-method-static
            https://www.geeksforgeeks.org/understanding-static-in-public-static-void-main-in-java/
            https://stackoverflow.com/questions/7279887/what-is-the-use-of-a-private-static-variable-in-java
            
      Final, Finally and Finalize in Java - https://www.geeksforgeeks.org/g-fact-24-finalfinally-and-finalize-in-java/
      
      Can overridden methods differ in return type? - https://stackoverflow.com/questions/14694852/can-overridden-methods-differ-in-return-type
      
      Interfaces in Java (complete explanation) - https://beginnersbook.com/2013/05/java-interface/      
      
      Packages in JAVA - https://www.geeksforgeeks.org/packages-in-java/

      Arrays - https://www.geeksforgeeks.org/arrays-in-java/
      
      JAVA OOPS - https://beginnersbook.com/2013/04/oops-concepts/
      

**POJO vs JavaBeans**
      
      POJO - Plain Old Java Object
      All JavaBeans are POJOs but vice-verse is not true
      There are some conditions on POJOs which makes them JavaBeans 
      
      JavaBeans -
            https://stackoverflow.com/questions/11406977/what-is-a-java-bean
            https://stackoverflow.com/questions/1727603/places-where-javabeans-are-used
            https://stackoverflow.com/questions/4275897/whats-the-point-of-beans
      
      Difference betweeb the two -
            https://www.geeksforgeeks.org/pojo-vs-java-beans/
            https://sites.google.com/site/sureshdevang/java-bean-v-s-pojo


**Object class**

      How to override equals() and hashCode()
            https://www.geeksforgeeks.org/overriding-equals-method-in-java/
            
**Serialization and Deserialization**

      Serialization - 
            Process of converting object to bytestream
            Bytestream is platform independent 
            It saves/persist the state of an object
            Helps in transfer of an object across network
            
      Deserialization -
            Converting bytestream to object
            
      https://www.geeksforgeeks.org/serialization-in-java/

**String Class**

      JAVA Sting Pool - 
            https://www.journaldev.com/797/what-is-java-string-pool
            https://stackoverflow.com/questions/3801343/what-is-string-pool-in-java
            https://stackoverflow.com/questions/2486191/what-is-the-java-string-pool-and-how-is-s-different-from-new-strings
            
      Equals VS == - 
            https://stackoverflow.com/questions/7520432/what-is-the-difference-between-and-equals-in-java
            https://www.journaldev.com/1321/java-string-interview-questions-and-answers#java-string-equals
            
      Why are strings immutable in Java? - https://www.programcreek.com/2013/04/why-string-is-immutable-in-java/      
      
      String comparison in Java
            https://stackoverflow.com/questions/513832/how-do-i-compare-strings-in-java


**Sorting**

      Sorting - Arrays.sort(), Collections.sort()
            https://stackoverflow.com/questions/5208133/collections-vs-arrays-regarding-sort
            
      Comparable vs Comparator
            1. https://stackoverflow.com/questions/1440134/when-should-a-class-be-comparable-and-or-comparator
            2. https://www.journaldev.com/780/comparable-and-comparator-in-java-example

**Specific topics and functions**

      1. Split Regex - https://www.geeksforgeeks.org/split-string-java-examples/
      2. Length VS Length() - https://www.geeksforgeeks.org/split-string-java-examples/
      3. BigInteger Class - https://www.geeksforgeeks.org/biginteger-class-in-java/
      4. Storage of objects in Java - https://www.geeksforgeeks.org/g-fact-46/
      5. String scanning issue - https://stackoverflow.com/questions/5966599/java-scanner-string-input
      6. Prime check - https://stackoverflow.com/questions/21740745/clarification-of-the-certainty-factor-in-isprobableprime
      7. Implementing comparator interface for sorting - https://www.geeksforgeeks.org/comparator-interface-java/
      
            Problems
            7.1 https://www.hackerrank.com/challenges/java-comparator/problem
            7.2 https://www.hackerrank.com/challenges/java-sort/problem
      
      8. Why ArrayList is preferred over Vector? - https://www.google.com/search?q=arraylist+vs+vector+in+java&rlz=1C1GCEU_enIN821IN821&oq=arraylist+vs+vector+&aqs=chrome.1.69i57j0l5.7145j0j7&sourceid=chrome&ie=UTF-8
      9. HashSet, HashMap and TreeSet in Java Collections
      10. Internal working of HashMap - https://www.geeksforgeeks.org/internal-working-of-hashmap-java/
      11. Standard method to obtain subarray of an array - https://stackoverflow.com/questions/4439595/how-to-create-a-sub-array-from-another-array-in-java
      12. Checked and unchecked exceptions - https://stackoverflow.com/questions/2190161/difference-between-java-lang-runtimeexception-and-java-lang-exception
      13. Wrapper class (autoboxing and unboxing) - https://www.geeksforgeeks.org/wrapper-classes-java/
      14. final vs immutable - https://stackoverflow.com/questions/34087724/what-is-the-difference-between-immutable-and-final-in-java

**Concurrency and Multi-threading**

      Synchronised in Java
            https://www.geeksforgeeks.org/synchronized-in-java/
      

**Collections framework**
      
      Collection framework provides interfaces and classes for different containers in Java
      1. https://www.journaldev.com/1260/collections-in-java-tutorial
      2. List Interface - https://www.geeksforgeeks.org/list-interface-java-examples
      3. Map Interface - https://www.geeksforgeeks.org/map-interface-java-examples/
      
      Generics in Java (Why are they needed?)
      1. https://www.journaldev.com/1663/java-generics-example-method-class-interface

**Hashmap**

      Hashmap does not support mutiple values with same key. 
      HashMap internally stores mapping in the form of Map.Entry object which contains both key and value object.
      This means if same key is encountered again, previous entry is replaced by current one (over ridden).
      Internally, hashmap is represented as an array of bucket where each bucket represents a linked list.
      Collision is possible for multiple keys and all keys with same hashcode is maintained in linked list of that bucket. [Link 1]
      
      1. https://javarevisited.blogspot.com/2011/02/how-hashmap-works-in-java.html
      2. https://www.geeksforgeeks.org/internal-working-of-hashmap-java/
      3. https://stackoverflow.com/questions/4553624/hashmap-get-put-complexity
      4. https://stackoverflow.com/questions/2889777/difference-between-hashmap-linkedhashmap-and-treemap
      
**JAVA Streams**

      Streams Vs Loops - https://stackoverflow.com/questions/44180101/in-java-what-are-the-advantages-of-streams-over-loops
      Lazy Evaluation in streams - https://www.logicbig.com/tutorials/core-java-tutorial/java-util-stream/lazy-evaluation.html
      
**JAVA interview prep**

      1. https://www.java67.com/2015/11/how-to-set-javahome-path-in-mac-os-x.html#at_pco=smlwn-1.0&at_si=5d2e197bebdf1c66&at_ab=per-2&at_pos=0&at_tot=1
      
**Unit tests in Java**

      Mock vs Spy - https://stackoverflow.com/questions/15052984/what-is-the-difference-between-mocking-and-spying-when-using-mockito

**Virtual Threads**

      Java 21 introduces an enhancements to threads called virtual threads 
      Virtual threads are more effecient for high throughout concurrent applications
      Details can be found here https://docs.oracle.com/en/java/javase/21/core/virtual-threads.html#GUID-15BDB995-028A-45A7-B6E2-9BA15C2E0501 
