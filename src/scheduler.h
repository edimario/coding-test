#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <list>
#include <unordered_map>
#include "job.h"
#include "node.h"

class Scheduler {
 public:
  Scheduler(void) : assigned_(0), waited_(0) {}
  void AddJob(int resources, int time);
  void AddNode(int id, int resources);
  void AddResources(int id, int resources);  
  void PrintJobStatus(void) const;
  void PrintNodeStatus(void) const;
  void PrintResourcesStatus(void) const;
  double GetAvgWaitTime(void) const;
  void ScheduleFCFS(void);  // Simple first-come, first-served scheduler
  void Step(void);
  int assigned(void) const {return assigned_;}
  
 private:
  std::list<Job> jobs_;  // Using list to add and remove jobs in constant time
  std::vector<Node> nodes_;
  std::unordered_map<int, int> resources_; // available resources
  int assigned_;  // number of assigned jobs
  int waited_;  // number of steps that jobs waited

  int FindSmallestAvailableNode(int req_resources) const;
};

#endif