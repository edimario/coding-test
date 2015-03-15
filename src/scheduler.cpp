#include "scheduler.h"
#include <cstdio>

using std::vector;

void Scheduler::AddJob(int resources, int time) {
  jobs_.emplace_back(resources, time);
}

void Scheduler::PrintJobStatus(void) const {
  printf("Pending jobs: ");
  for (const auto &job : jobs_) {
    printf("(%d %d)", job.resources(), job.time_left());
  }
  printf("\n");
}

void Scheduler::AddNode(int id, int resources) {
  nodes_.emplace_back(id, resources);
}

void Scheduler::PrintNodeStatus(void) const {
  printf("Available nodes: ");
  for (const auto &node : nodes_) {
    printf("(%d %d %d %d)", node.id(), node.resources(),
           node.occupied_resources(), node.time_left());
  }
  printf("\n");
}

// Simple first-come, first-served scheduler
void Scheduler::ScheduleFCFS(void) {
  for (auto it = jobs_.begin(); it != jobs_.end();) {
    int assigned_node = FindSmallestAvailableNode(it->resources());
    if (assigned_node != -1) {
      printf("Assigning job to node %d\n", assigned_node);
      nodes_[assigned_node].AssignJob(*it);
      it = jobs_.erase(it);  // Iterator advanced after the erase operation
    } else {
      ++it;  // Job could not be assigned, move to next job
    }
  }
}

// Find smallest available node with at least the number
// of required resources
int Scheduler::FindSmallestAvailableNode(int req_resources) const {
  int best_node_i = -1;
  int best_node_resources = -1;

  for (unsigned int node_i = 0; node_i < nodes_.size(); ++node_i) {
    const Node &node = nodes_[node_i];
    if (node.IsIdle() && node.resources() >= req_resources) {
      if (best_node_i == -1 || node.resources() < best_node_resources) {
        best_node_i = node_i;
        best_node_resources = node.resources();
      }
    }
  }
  return best_node_i;
}