# Linux System Programming 

This repository contains **C programs demonstrating Linux System
Programming concepts** and the usage of various **system calls** across
multiple domains such as:

-   File Subsystem
-   Process Subsystem
-   Memory Management
-   Inter-Process Communication (IPC)
-   Static Linking and Dynamic Linking
-   Multi Threading and Multi Processing
-   Kernel Modules and Device Drivers

The goal of this repository is to **learn how user-space programs
interact with the Linux kernel using system calls**.

All programs are implemented in **C language** and tested on **Linux
systems**.

------------------------------------------------------------------------

# File Subsystem System Calls

### File Handling

-   open()
-   close()
-   creat()
-   unlink()
-   remove()
---

### File I/O

-   read()
-   write()
-   pread()
-   pwrite()
---

### File Positioning

-   lseek()
---

### File Size Management

-   truncate()
-   ftruncate()
---

### File Metadata

-   stat()
-   fstat()
-   lstat()
---

### File Links

-   link()
-   symlink()
-   readlink()
---

### File Synchronization

-   sync()
-   fsync()
-   fdatasync()
---

### Directory Operations

-   opendir()
-   closedir()
-   readdir()
-   mkdir()
-   rmdir()
-   chdir()
-   getcwd()
---

### File Access & Descriptor Management

-   access()
-   dup()
-   dup2()
---

### File Renaming

-   rename()

------------------------------------------------------------------------

# Memory Management

These functions and system calls demonstrate **dynamic memory allocation
and memory mapping**.


-   brk()
-   sbrk()
-   memset()
-   memcmp()
-   memcpy()
---

### Dynamic Memory Allocation

-   malloc()
-   calloc()
-   realloc()
-   free()
---

### Memory Mapping

-   mmap()
-   munmap()

------------------------------------------------------------------------

# Process Subsystem

### Process Creation

-   fork()
-   exec()
-   execl()
---

### Process Information

-   getpid()
-   getppid()
---

### Process Control

-   wait()
-   waitpid()
-   sleep()
-   exit()
-   _exit()
-   atexit()
---

### Process Priority

-   nice()
-   getpriority()
-   setpriority()
---

### Thread Management

-   pthread_create()
-   pthread_join()
-   pthread_exit()

------------------------------------------------------------------------

# Thread Synchronization

Used to protect **shared resources in multi-threaded programs**.

### Mutex Operations

-   pthread_mutex_t
-   pthread_mutex_init()
-   pthread_mutex_destroy()
-   pthread_mutex_lock()
-   pthread_mutex_unlock()

------------------------------------------------------------------------

# Dynamic Linking (Shared Libraries)

These functions allow programs to **load shared libraries at runtime**.

-   dlopen()
-   dlsym()
-   dlclose()
-   dlerror()

------------------------------------------------------------------------

# Inter-Process Communication (IPC)

### Pipes and FIFOs

-   pipe()
-   mkfifo()
---

### Shared Memory

-   shmget()
-   shmat()
-   shmdt()
---

### Message Queues

-   msgget()
-   msgsnd()
-   msgrcv()

---

### Signals

-   signal()
-   kill()

------------------------------------------------------------------------

# Compilation

Compile using GCC:

    gcc program.c -o program

Run:

    ./program

For pthread programs:

    gcc program.c -o program -lpthread

------------------------------------------------------------------------

# Requirements

-   Linux OS
-   GCC Compiler
-   makefile
-   kernel headers

------------------------------------------------------------------------

# Learning Objectives

## Linux System Programming

-   Understand the **interaction between user space and kernel space**
    in Linux.
-   Learn how **Linux system calls interface with the kernel**.
-   Implement programs using **file subsystem related system calls**.
-   Understand **process creation and management** using `fork()` and
    `exec()`.
-   Explore **dynamic memory allocation and memory mapping** mechanisms.
-   Implement **inter-process communication (IPC)** using pipes, shared
    memory, and message queues.
-   Work with **POSIX threads (pthreads)** and implement **thread
    synchronization using mutexes**.
-   Use **dynamic linking** to load shared libraries at runtime using
    `dlopen()` and `dlsym()`.

------------------------------------------------------------------------

## Kernel Modules & Device Drivers

-   Understand the **architecture of Linux kernel modules**.
-   Learn how to **write, compile, load, and unload kernel modules**.
-   Understand the **Linux device driver model**.
-   Learn how **device drivers interact with hardware and the Linux
    kernel**.
-   Implement **basic character device drivers**.
-   Understand how **user-space applications communicate with device
    drivers using system calls**.
-   Gain familiarity with **kernel logging, module parameters, and
    device file creation**.

------------------------------------------------------------------------

# Author

**Prem Choudhary**

Linux System Programming | Kernel Modules | Device Drivers | POSIX Threads | IPC | Memory Management