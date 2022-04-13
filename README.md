# Philosophers
In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.
Philosophers
The outline of this project and the establishment of the concept to proceed with the project.

# Project Introduction

Dining philosophers problem)is a problem created by Edsger Wybe Dijkstra in 1965 to explain the deadlock state of an operating system, which is traditionally commonly introduced in lectures on operating systems.


For example, n philosophers are sitting at the round table and eating. A fork is placed between the philosophers, and the philosophers eat through the following process.

The philosopher repeats three actions: eating ➔ sleeping ➔ thinking.
When eating, both forks should be used.
If you lift both forks, eat for a certain amount of time.
When you're done eating, put your fork down.
Not a single philosopher should die from not eating for a certain period of time.
If all the philosophers were hungry and picked up the left chopsticks at the same time, the right chopsticks would have already been picked up by the philosopher sitting to their right, and everyone would forever be unable to hold the right chopsticks. That is, there is no further progress, and the philosophers are forever on standby. This phenomenon is called deadlock. Once in a deadlock, philosophers continue to suffer and die of starvation.

The task is to implement a program that solves this problem using (Mutex)or (Semaphore).

# permissible function

Mandatory

memset

malloc()Initializes the memory allocated in or calloc()to a specific value. It is usually used to initialize before doing any work NULL.

header:#include <string.h>
form :void *memset(void *s, int c, size_t n)
factor :
void *s: memory start address to initialize
int c: Initialization value
size_t size: Initial size
Return: void *sA pointer to , on success, NULL on failure.
printf

It is a standard output function of the C language, and it allows you to output various types of data in various formats.

header:#include <stdio.h>
form :int printf(const char *format, ...)
Argument: %[flag][width][.precision][length]specifier
Returns: the total number of characters printed on success, a negative number on failure.


