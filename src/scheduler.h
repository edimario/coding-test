#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <list>
#include <unordered_map>
#include "job.h"

// Simple first-come, first-served scheduler

class Scheduler {
 public:
  Scheduler(void) : assigned_(0), waited_(0) {}
  void AddJob(int resources, int time);
  void AddNode(int id, int resources);
  void AddResources(int id, int resources);  
  void PrintJobStatus(void) const;
  void PrintResourcesStatus(void) const;
  double GetAvgWaitTime(void) const;
  void Step(void);
  int assigned(void) const {return assigned_;}
  
 protected:
  std::list<Job> jobs_;  // Using list to add and remove jobs in constant time
  std::unordered_map<int, int> resources_; // available resources
  int assigned_;  // number of assigned jobs
  int waited_;  // number of steps that jobs waited

  virtual void Schedule(void);  // Simple first-come, first-served scheduler  
  int FindSmallestAvailableNode(int req_resources) const;
};

#endif