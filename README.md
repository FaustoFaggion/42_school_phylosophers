# 42SP - Philosophers

This project was create to teach the basics of threading a process.

If you intend to undertand how the program works, I highly recommend to watch the follow play list on the NESO ACADEMY youtube channel

https://www.youtube.com/watch?v=LOfGJcVnvAk&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=31

## Dining Philosophers Problem

- Several philosophers are sitting at a round table doing one of three things: eating, thinking, or sleeping.
- While eating, they are not thinking or sleeping, while sleeping, they are not eating or thinking and of course, while thinking, they are not eating or sleeping.
- The philosophers sit at a circular table with a large bowl of spaghetti in the center.
- There are some forks on the table.
- As spaghetti is difficult to serve and eat with a single fork, it is assumed that a philosopher must eat with two forks, one for each hand.
- The philosophers must never be starving.
- Every philosopher needs to eat.
- Philosophers don’t speak with each other.
- Philosophers don’t know when another philosopher is about to die.
- Each time a philosopher has finished eating, he will drop his forks and start sleeping.
- When a philosopher is done sleeping, he will start thinking.
- The simulation stops when a philosopher dies.
- Each program should have the same options: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
  - number_of_philosophers: is the number of philosophers and also the number of forks
  - time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal or the beginning of the simulation, it dies
  - time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks.
  - time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping.
  - number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.

- Each philosopher should be given a number from 1 to ’number_of_philosophers’.
- Philosopher number 1 is next to philosopher number ’number_of_philosophers’. - Any other philosopher with the number N is seated between philosopher N - 1 and philosopher N + 1
- Any change of status of a philosopher must be written as follows (with X replaced with the philosopher number and timestamp_in_ms the current timestamp in milliseconds)

  - timestamp_in_ms X has taken a fork
  - timestamp_in_ms X is eating
  - timestamp_in_ms X is sleeping
  - timestamp_in_ms X is thinking
  - timestamp_in_ms X died

- The status printed should not be scrambled or intertwined with another philosopher’s status.
- You can’t have more than 10 ms between the death of a philosopher and when it will print its death.
- Again, philosophers should avoid dying!

## Compile the Program

Install: `git clone git@github.com:barimehdi77/Philosophers.git`

run: `make`

#### Maratory

run: `./philo [nb_philo] [time_to_die] [time_to_eat] [optionnal: nb_of_eating_cycles]`

#### Bonus

run: `make bonus`

run: `./philo [nb_philo] [time_to_die] [time_to_eat] [optionnal: nb_of_eating_cycles]`

## Threads Theory

### What is a Thread?
A thread is an execution context, which is all the information a CPU needs to execute a stream of instructions. A process can contain multiple threads.

### Thread X Process
A program under execution is known as a process and a thread is a basic unit execution. Thread is a basic unit of CPU utilization.

#### Threads

Threads Comprises:
- A Thread ID
- A Program counter
- A register set
- A stack

Threads share the same resources that was allocated to the process they are bellong to. For exemple:
- Code section
- Data section
- Open files
- Signals

#### Process

- Run indepently from others process
  - Have independent memory space
  - When a process is created, the parent variables are duplicated for the child process.
  - Changes in variables on the parent process don't afect the variables in the child process.
- File handlers are duplicated.

### Advantages

- Responsiveness > May allow a program to continue running even if part of if is blocked or is performing a lengthy operation, therreby increasing responsiveness to the user.
- Resource Sharing > Allows several different threads to share the same adress space, making the process more economic. Create resources for process it is costly.
- Utilization of Multiprocessor Architecture > Where threads can be running parallel on different processors, making a multithread process run tasks in parallel. A single thread process can run only on one CPU no matter how many CPUs are avaiable.

### Thread execution:

- Read the data in your own register.
- Apply a function required using the data saved in his register.
- Return the result to the data in memory.

## Types of Threads

- User Threads > Supported above the kernel and are managed whitout kernel support.
- Kernel Threads > Supported an manage directly by the operating system.

### Relationship User Threads x Kernel Threads

- Many to One

<img width=1800 src="./readme/many_to_one_thread.png">

- One to One
 
<img width=1800 src="./readme/one_to_one_thread.png">

- Many to Many > Best solution(most used model)

<img width=1800 src="./readme/many_to_many_thread.png">

### Race Condition

A situation where several threads access and manipulate the same data concurrently and the outcome of the execution depends on the particular order in which the access takes place.

### Critical Section

Is a section in which the process may be changing commom data, writing commom files and so on.
When one process is executing in its critical section, no other process is to be allowe to execute in its critical section.

### Paralelism

Threads runing simultaniously in different cores. It just can happen if there is a multi core processor.

### Atomic Operations

Ensure that changes to a field are always consistent. Threads that share the same operation field are not allowed to run it at the same time.

### Semaphores

Semaphore proposed by Edger Dijikstra, is a techinique to manage concurent processes by using a simple integer, wich is known as a semaphore.

It is simply a variable wich is non-negative and shared among threads.

Apart from initialization, is accessed only throug two standard atomic operations: wait() and signal().

semaphore   ->    S

wait()      ->    P (from Dutch word proberen, wich means "to test")

signal()    ->    V (from Dutch word verhogen, wich means "to increment")

It is used to control the access of Proccess into critical sections.

How it works:

```
function()
{
  code
  sem_wait(<semaphore_name>);
  
  critical_section;

  sem_post(<semaphore_name>);
  code
}
```
- When a semaphore is created by the 'sem_open' function, a integer, that can be defined as the last parameter of the 'sem_open' function, is assigned to it.
- Every time that a thread from a proccess pass through the 'sem_wait' instruction, this integer is decreased by 1(integer--).
- Every time that a thread from a proccess pass through the 'sem_post' instruction, this integer is increased by 1 (integer++).
- When the integer reach 0, any thread that reachs the 'sem_wait' instruction will enter in a looping that will be breaked when the integer became greater than 0 again.
- when a thread that is int the 'critical_section' reachs the 'sem_post', the integer is increased and the threads are able to pass through the 'sem_wait' again until the integer reachs 0 again.
- Looking the function above, it is possible to define how many threads can access the critical_section simultaniously

### Mutex

- It is a semaphore used to syncronizing threads from the same proccess.

How it works:

```
function()
{
  code
  pthread_mutex_lock(<mutex_name>);
  
  critical_section;

  pthread_mutex_unlock(<mutex_name>);
  code
}
```
- When a mutex is created a integer of value 1 is assigned to it
- Every time that a thread pass through the 'mutex_lock' instruction, this integer is decreased by 1(integer--).
- Every time that a thread from a proccess pass through the 'mutex_unlock' instruction, this integer is increased by 1 (integer++).
- When the integer reach 0, any thread that reachs the 'mutex_lock' instruction will enter in a looping that will be breaked when the integer became greater than 0 again.
- when a thread that is int the 'critical_section' reachs the 'mutex_unlock', the integer is increased and the threads are able to pass through the 'mutex_lock' again until the integer reachs 0 again.
- Looking the function above, only a thread at time can access the 'critical_section'. It is not allowed that two or more threads access the 'critical section' simultaneously.

## Code Solution

Follow a simple resume of what is happining in the code:

- For each philosophers was created a thread
- The threads run the same function that has a looping with the instructions to be done:
  - take a fork;
  - eat
  - sleep
  - think
- Each fork that a philosophers needs to eat is a mutex. For each philosopers is assigned two mutex, one representing his rigth fork and other representing his left fork.

- **Note:**

  - The right fork of a philosopher is the same of lef fork of the previous philosopher.
  - The left fork of a philosopher is the same of lef fork of the next philosopher

- Generaly speeking, placing the right and left mutex before the critical_section will ensure that any philosopher will eat without or only one fork.

- In order to verify if a philosopher die, another thread called MONITOR was created.

This thread runs a function that keeps verifing if the time of the last meal of each philosophers is greater than the time to die. If yes, the thread sets a flag to show all threads that a philosophers die, in order to stop. The program close.

## Links

README:

[Tutorial README](https://www.youtube.com/watch?v=eJojC3lSkwg)

Makefile:

[Tutorial Makefile](https://www.youtube.com/watch?v=GExnnTaBELk)

Threads:

[Introdution to Threads](https://www.youtube.com/watch?v=LOfGJcVnvAk&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=31)

[Multithreading Models](https://www.youtube.com/watch?v=HW2Wcx-ktsc&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=32)

[What is a Thread](https://www.geeksforgeeks.org/thread-in-operating-system/)

[Compiling threads](https://www.youtube.com/watch?v=j9csJohayPU)

[Code Valt - threads](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)

[Race Condition(process syncronization)](https://www.youtube.com/watch?v=ph2awKa8r5Y&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=56)

[Critical Section](https://www.youtube.com/watch?v=UtEORPakw5Y&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=58)

[Semaphore](https://www.youtube.com/watch?v=XDIOC2EY5JE&list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O&index=60)

[Instructions per Second](https://en.wikipedia.org/wiki/Instructions_per_second)