#include "node.h"

Node::Node(int id, int resources) : id_(id), resources_(resources),
                                    occupied_resources_(0), time_left_(0) {
}

void Node::AssignJob(const Job &job) {
  occupied_resources_ = job.resources();
  time_left_ = job.time_left();  
}
