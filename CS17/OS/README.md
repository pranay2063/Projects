# Operating System


[**OS Basics**](https://www.geeksforgeeks.org/operating-systems/#basics)

1. **What happens when we turn on computer?**
2. [**Multiprogramming, Multiprocessing, Multitasking, Multithreading**](https://www.geeksforgeeks.org/operating-system-difference-multitasking-multithreading-multiprocessing/)
3. [**System Call**](https://www.geeksforgeeks.org/operating-system-introduction-system-call/)
4. **Process Management** - Process Control Block(PCB) - Process ID (PID), Process State, Program Counter, CPU Scheduling Info, CPU Registers 
  
   *https://www.geeksforgeeks.org/gate-notes-operating-system-process-management-introduction/*
   *https://www.geeksforgeeks.org/operating-system-process-table-process-control-block-pcb/*
   
5. **CPU Scheduling (Process Scheduling)** - 

   Process scheduler - 
   
                       Long term scheduler - New -> Ready transition, Job scheduler, controls degree of multi-programming
                       Short term scheduler - Ready -> Running selection, only selection, not transition, dispatcher handles transition
                       Medium term scheduler - suspending and resuming process, switching from main memory to secondary memory and vice-versa
   
   Dispatcher - 
        
                       handles transition from ready to running state (Context Switching)
                       https://www.geeksforgeeks.org/operating-system-difference-dispatcher-scheduler/
   
   Time variants related to a process - 
   
                       Arrival Time - Time when program arrives in Job Queue (Ready Queue)
                       Completion Time  - Time when process completes execution
                       Burst Time - Time duration of process execution at CPU (Process can be executed in multiple bursts)
                       Turn Around Time (TAT) - Completion Time - Arrival Time
                       Waiting Time - TAT - Burst Time
                       Service Time - Time at which process execution starts or is responded for the first time
                       
   CPU scheduling algorithms - Non-preemptive and Preemptive algorithms 
   
                       Non-preemptive algorithms - 
                          FCFS - Convoy effect - https://www.geeksforgeeks.org/convoy-effect-operating-systems/
                          Shortest Job First (SJF)
                          Non-preemptive priority scheduling
                       
                       Preemptive algorithms - 
                          Round Robin
                          SRTF (Shortest Remaining Time First) (Pre-emptive version of SJF)
                          Pre-emptive priority scheduling
                          Multi-level queue scheduling
                          Multi-level feedback queue scheduling (extension of above algorithm)
                       
   Starvation -
   
                       Starvation - Indefinite wait (Lived Lock)
                       Deadlock - Infinite wait (Circular Waiting)
                       Aging - solution to starvation (https://www.geeksforgeeks.org/starvation-aging-operating-systems/)
                       
   Deadlock -
   
                       Conditions for deadlock -
                          1. Mutual exclusion
                          2. Hold and wait
                          3. No preemption
                          4. Circular wait
                          
                       Solution to deadloack - 
                          1. Deadloack avoidance
                          2. Dead detection and recovery
                          3. Ignore the problem at all (if not frequent) - Let it happen and reboot
                          
                       Deadlock avoidance -
                          Banker's algorithm 
                            - Safety algorithm - to decide if system is in safe state
                            - Resource-request algorithm
                            
   Critical Section Problem - 
                        
                       Cooperative processes - processes whose execution affects execution of other processes (opposite of independent processes)
                       
                       Race condition - If several processes are accessing a resource or segment concurrently, then outcome of the execution depends order of access
                       
                       Critical section - A segment which can be accessed by one process at a time
                       
                       Solution to critical section must satisfy following conditions:
                          1. Mutual exclusion 
                          2. Progress - 
                          3. Bounded wait -
                          
                       Peterson solution - software based solution
                       Test and Set (Lock and Unlock)
                       Mutex (Locking mechanism)
                       Semaphore (Signalling mechanism)
                       
   Producer - Consumer Problem - 
    
                       Also called bounded buffer problem
                       There are two processes - 
                              One producer (produces resource and adds to buffer)
                              One consumer (removes resource from buffer and consumes it)
                       
                       Concept - https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem
                       Implementation in JAVA - https://www.geeksforgeeks.org/producer-consumer-solution-using-threads-java/
                       
**Other OS concepts**

    System Call - https://www.geeksforgeeks.org/operating-system-introduction-system-call/

    Interrupt vs Polling
        1. https://en.wikipedia.org/wiki/Polling_(computer_science)
        2. https://techdifferences.com/difference-between-interrupt-and-polling-in-os.html
    
   [Mutex vs Semaphore](https://stackoverflow.com/questions/62814/difference-between-binary-semaphore-and-mutex)
    
