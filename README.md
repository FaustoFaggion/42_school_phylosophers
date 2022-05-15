# 42SP - Philosophers

This project was create to teach the basics of threading a process.

## What is a Thread?

A thread is an execution context, which is all the information a CPU needs to execute a stream of instructions. A process can contain multiple threads.

## Thread X Process
A program under execution is known as a process and a thread is a basic unit execution. Thread is a basic unit of CPU utilization.

### Threads

Threads Comprises:
- A Thread ID
- A Program counter
- A register set
- A stack
Threads share with other threads belonging to the same process the follow resources:
- Code section
- Data section
- Open files
- Signals
Share the same resources the was allocated to the process by the Operate System.

### Process

- Run independily from others process
  - Have independent memory space
  - When create a process, the parent variables are duplicated for the child process.
  - Changes in variables on the parent process don't afect the variables in the child process.
- File handlers are duplicated.

### Advantages

- Responsiveness > May allow a program to continue running even if part of if is blocked or is performing a lengthy operation, therreby increasing responsiveness to the user.
- Resource Sharing > Allows several different threads to share the same adress space, making the process more economic. Create resources for process it is costly.
- Utilization of Multiprocessor Architecture > Where threads can be running parallel on different processors, making a multithread process run tasks in parallel. A single thread process can run only on one CPU no matter how many CPUs are avaiable.

## Race Condition

A Race Condition occurr when two or more threads have to access the same data at the same time, creating a concorrency. The programer has to make sure that the threads do not use this data at the same time. When a thread is using a specific data, its necessary to block the use of it from other threads. For this we use the mutex.

It just can happen if there is a multi core processor.

## Paralelism

### Thread execution:

- Read the values in your own register.
- Apply a function required using the values saved in his register.
-  Apply this values to the variables in memory.

### Links

README:

[Tutorial README](https://www.youtube.com/watch?v=eJojC3lSkwg)

Makefile:

[Tutorial Makefile](https://www.youtube.com/watch?v=GExnnTaBELk)

Threads:

[Introdution to Threads](https://www.youtube.com/watch?v=LOfGJcVnvAk&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=31)

[Waht is a Thread](https://www.geeksforgeeks.org/thread-in-operating-system/)

[Compiling threads](https://www.youtube.com/watch?v=j9csJohayPU)

[Code Valt - threads](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)