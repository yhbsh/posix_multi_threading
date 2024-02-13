# Multi-threading Exercises in C using pthreads

This document lists various exercises to practice multi-threading concepts in C using the pthread library. Check off each exercise as you complete them.

- [ ] **Producer-Consumer Problem**
  - Implement a scenario where multiple producers are producing items and multiple consumers are consuming them. Use mutexes and condition variables to synchronize access to a shared buffer.

- [ ] **Parallel Array Sum**
  - Create a program to calculate the sum of a large array. Divide the array into chunks and use multiple threads to calculate the sum of each chunk. Finally, aggregate these sums in the main thread.

- [ ] **Matrix Multiplication**
  - Implement matrix multiplication using multiple threads. Each thread could be responsible for calculating one row of the resulting matrix.

- [ ] **Sorting Algorithm (e.g., Merge Sort)**
  - Implement a multi-threaded version of a sorting algorithm like merge sort. Use threads to divide and conquer different parts of the array.

- [ ] **Monte Carlo Simulation**
  - Use multi-threading for a Monte Carlo simulation such as estimating the value of Pi. Each thread can perform a number of trials and share the results for final computation.

- [ ] **Web Server Simulation**
  - Create a simple simulation of a multi-threaded web server. Each request should be handled by a separate thread.

- [ ] **Thread Pool Implementation**
  - Implement a thread pool where a fixed number of threads are created to execute tasks. This includes understanding thread management and task scheduling.

- [ ] **Custom Exercise**
  - Think of a unique problem that can be solved efficiently with multi-threading and implement a solution for it.

