
**Root - Collection (I) and Map (I)**

**Collection (I) extends Iterable (I)**
    
    List (I), Set (I) and Queue (I) extends Collection (I) 
      ArrayList (C) implements List (I)
      Vector (C) implements List (I)
      LinkedList (C) implements List (I) and Queue (I)
      PriorityQueue (C) implements Queue (I)

    Set (I) extends Collection (I)
      HashSet (C) implements Set (I)
      LinkedHashSet (C) implements Set (I)
      SortedSet (I) extends Set (I)
        TreeSet (C) implements SortedSet (I)
        
**Map (I)**
    
    HashMap (C) implements Map (I)
    HashTable (C) implements Map (I)
    SortedMap (I) extends Map (I)
      TreeMap (C) implements SortedMap (I)

**HashMap**

    Hashmap does not support mutiple values with same key (dublicate keys). 
    HashMap internally stores mapping in the form of Map.Entry object which contains both key and value object.
    This means if same key is encountered again, previous entry is replaced by current one (over ridden).
    Internally, hashmap is represented as an array of bucket where each bucket represents a linked list.
    Collision is possible for multiple keys and all keys with same hashcode is maintained in linked list of that bucket. [Link 1]
  
    1. https://javarevisited.blogspot.com/2011/02/how-hashmap-works-in-java.html
    2. https://www.geeksforgeeks.org/internal-working-of-hashmap-java/
    
    HashMap and LinkedHashMap allows null keys and null values but TreeMap doesn't allow any null key or value.
        https://stackoverflow.com/questions/15091148/hashmaps-and-null-values
    
    Default size of HashMap and resizing? 
        Default size (16)  
        Load Factor (.75)
        Default size * Load Factor = 12 (12 keys can be supported for default size)
        If number of keys extends 12, then bucker size will be doubled (2x) 
            https://stackoverflow.com/questions/5040753/why-arraylist-grows-at-a-rate-of-1-5-but-for-hashmap-its-2
            https://stackoverflow.com/questions/10901752/what-is-the-significance-of-load-factor-in-hashmap
    
    Complexity of get() and put()? 
        https://stackoverflow.com/questions/4553624/hashmap-get-put-complexity
    
    HashMap vs ConcurrentHashMap vs SynchronizedHashMap 
      HashMap is by default not synchronized and so not thread-safe
      ConcurrentHashMap provides locking (thread safety) by default but not at a level of synchronized HashMap (where each method is synchronized)
        https://stackoverflow.com/questions/1291836/concurrenthashmap-vs-synchronized-hashmap
        https://www.geeksforgeeks.org/difference-hashmap-concurrenthashmap/
        https://javarevisited.blogspot.com/2011/04/difference-between-concurrenthashmap.html
        https://stackoverflow.com/questions/510632/whats-the-difference-between-concurrenthashmap-and-collections-synchronizedmap
      ConcurrentMap
        https://dzone.com/articles/beware-of-slightly-different-behavior-between-conc
        https://www.geeksforgeeks.org/concurrentmap-interface-java/
      HashMap vs ConcurrentHashMap 
        https://stackoverflow.com/questions/1378310/performance-concurrenthashmap-vs-hashmap
      ConcurrentHashMap
        https://www.geeksforgeeks.org/concurrenthashmap-in-java/
        https://dzone.com/articles/how-concurrenthashmap-works-internally-in-java
        https://www.journaldev.com/122/concurrenthashmap-in-java
      
**HashSet**

**PriorityQueue**

    PriorityQueue class
        https://www.geeksforgeeks.org/priority-queue-class-in-java-2/
    PriorityQueue implementing Comparator interface
        https://www.geeksforgeeks.org/implement-priorityqueue-comparator-java/
