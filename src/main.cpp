#include <cstdio>
#include "scheduler.h"

int main(void) {
  printf("Testing job scheduler...\n");
  Scheduler s;

  s.AddResources(2, 3);
  s.AddResources(7, 1); 

  s.AddJob(4, 4);  
  s.AddJob(3, 4);
  s.AddJob(1, 4);
  s.PrintJobStatus();
  s.PrintResourcesStatus();

  for (int step = 0; step < 10; ++step) {
    s.Step();
    s.PrintJobStatus();
    s.PrintResourcesStatus();
  }

  s.AddResources(4, 4);

  for (int step = 0; step < 10; ++step) {
    s.Step();   
    s.PrintJobStatus();
    s.PrintResourcesStatus();
  }

  printf("Testing finished: assigned %d jobs, avg wait time %.2f steps\n",
         s.assigned(), s.GetAvgWaitTime());
  return 1;
}
