# Coding Test

## Instructions to run the test

Simply do make and then run the executable test_scheduler

## Explanation of Output

There are two scheduling algorithms implemented in two classes.
The base class is Scheduler, which implements a first-come first-served scheduler.

An improvement is a greedy algorithm implemented in the SchedulerGreedy derived class.
In this case, the largest jobs that can be run with the current resources are assigned first, which avoids "fragmentation" of resources.

The difference between the two algorithms is shown in the test scenario, using the average waited time as metric.
In the FCFS, the first job requiring 2 resources is assigned, but the second can't be assigned because it requires 3 and needs to wait until they become available.
When the test finishes, there is still one job pending.

In the greedy algorithm, the second job is assigned first because it requires more resources which are available, and at the end all jobs are assigned.

## Assumptions

- No pre-emptive scheduling: when a job is assigned to a node, it runs until completion
- When that when a job is done resources are not automatically available, they must appear in the resource stream.

## Possible Improvements
- Data structures: currently using a list to hold jobs in the FCFS algorithm, which was kept in the greedy algorithm and it is sorted at each time (inefficient). A different data structure should be used in that case (e.g. set).
- Use files to input test cases and automate testing.
- Improve scheduling algorithms: add pre-emptive ones, try Round-Robin and Multi-level queue. Greedy algorithm could cause starvation of small jobs.
- Add other performance metrics: throughput, latency, etc.