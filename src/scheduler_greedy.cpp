#include "scheduler_greedy.h"
#include <cstdio>
#include <algorithm>

// Function object to compare jobs by resource size
struct CompareJobs{
  bool operator() (const Job &job1, const Job &job2) {
  return (job1.resources() > job2.resources());
 }
};   

// Greedy Scheduler: Look at all pending jobs, assign
// job requiring most resources first.

void SchedulerGreedy::Schedule(void) {
  // printf("Greedy scheduler");
  jobs_.sort(CompareJobs());  
  
  Scheduler::Schedule();
}
