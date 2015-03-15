#ifndef SCHEDULER_GREEDY_H
#define SCHEDULER_GREEDY_H

#include "scheduler.h"

// Greedy Scheduler: Look at all pending jobs, assign
// job requiring most resources first.

class SchedulerGreedy : public Scheduler {
 protected:
  virtual void Schedule(void);
};

#endif