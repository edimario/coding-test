#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <list>
#include "job.h"
#include "node.h"

class Scheduler {
 public:
  void AddJob(int resources, int time);
  void AddNode(int id, int resources);  
  void PrintJobStatus(void) const;
  void PrintNodeStatus(void) const;
  void ScheduleFCFS(void);  // Simple first-come, first-served scheduler  
  
 private:
  std::list<Job> jobs_;  // Using list to add and remove jobs in constant time
  std::vector<Node> nodes_;

  int FindSmallestAvailableNode(int req_resources) const;
};

#endif