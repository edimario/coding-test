#ifndef NODE_H
#define NODE_H

#include "job.h"

class Node {
 public:
  Node(int id, int resources);
  int resources(void) const {return resources_;}
  int id(void) const {return id_;}
  int occupied_resources(void) const {return occupied_resources_;}
  int time_left(void) const {return time_left_;}  
  void AssignJob(const Job &job);
  bool IsIdle(void) const {return occupied_resources_==0;}
 private:
  int id_;
  int resources_;
  int occupied_resources_;
  int time_left_;
};

#endif
