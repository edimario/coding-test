#include <cstdio>
#include "scheduler.h"

int main(void) {
  printf("Testing job scheduler...\n");
  Scheduler s;

  s.AddNode(2, 3);
  s.AddNode(7, 1);  
  s.PrintNodeStatus();
  
  s.AddJob(3, 4);
  s.AddJob(1, 4);  
  s.PrintJobStatus();
  s.ScheduleFCFS();
  s.PrintJobStatus();
  return 1;
}
