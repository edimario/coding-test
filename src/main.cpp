#include <cstdio>
#include "scheduler.h"
#include "scheduler_greedy.h"

void TestScheduler (Scheduler *scheduler) {
  scheduler->AddResources(2, 3);
  scheduler->AddResources(7, 1); 
 
  scheduler->AddJob(2, 4);
  scheduler->AddJob(3, 4);
  scheduler->AddJob(3, 4);  
  scheduler->PrintJobStatus();
  scheduler->PrintResourcesStatus();

  for (int step = 0; step < 10; ++step) {
    scheduler->Step();
    scheduler->PrintJobStatus();
    scheduler->PrintResourcesStatus();
  }

  scheduler->AddResources(3, 3);
  scheduler->AddResources(7, 1);  

  for (int step = 0; step < 10; ++step) {
    scheduler->Step();   
    scheduler->PrintJobStatus();
    scheduler->PrintResourcesStatus();
  }

  printf("Testing finished: assigned %d jobs, avg wait time %.2f steps\n",
         scheduler->assigned(), scheduler->GetAvgWaitTime());  
}

int main(void) {

  printf("\nTesting FCFS job scheduler...\n");
  Scheduler scheduler_FCFS;
  TestScheduler(&scheduler_FCFS);
  
  printf("\nTesting Greedy job scheduler...\n");  
  SchedulerGreedy scheduler_greedy;
  TestScheduler(&scheduler_greedy);
}
