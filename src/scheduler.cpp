#include "scheduler.h"
#include <cstdio>

using std::vector;

void Scheduler::AddJob(int resources, int time) {
  jobs_.emplace_back(resources, time);
}

void Scheduler::PrintJobStatus(void) const {
  printf("Pending jobs: ");
  for (const auto &job : jobs_) {
    printf("(%d %d %d)", job.resources(), job.time_left(), job.waited());
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

void Scheduler::AddResources(int id, int resources) {
  resources_[id] += resources;
}

void Scheduler::PrintResourcesStatus(void) const {
  printf("Available Resources: ");
  for (const auto &resource : resources_) {
    printf("(%d %d)", resource.first, resource.second);
  }
  printf("\n");
}

// Simple first-come, first-served scheduler
void Scheduler::ScheduleFCFS(void) {
  for (auto it = jobs_.begin(); it != jobs_.end();) {
    int job_resources = it->resources();
    int assigned_node = FindSmallestAvailableNode(job_resources);
    if (assigned_node != -1) {
      printf("Assigning job to node %d\n", assigned_node);
      resources_[assigned_node] -= job_resources;
      assigned_++;            // Increase number of assigned jobs
      it = jobs_.erase(it);  // Iterator advanced after the erase operation
    } else {
      ++it;  // Job could not be assigned, move to next job
    }
  }
}

// Find smallest available node with at least the number
// of required resources
int Scheduler::FindSmallestAvailableNode(int req_resources) const {
  int best_node_id = -1;
  int best_node_resources = -1;

  for (const auto &resource : resources_) {
    int id = resource.first;
    int available_resources = resource.second;
    if (available_resources >= req_resources) {
      if (best_node_id == -1 || available_resources < best_node_resources) {
        best_node_id = id;
        best_node_resources = available_resources;
      }
    }
  }
  return best_node_id;
}

void Scheduler::Step(void) {
  ScheduleFCFS();
  for (auto &job : jobs_) job.IncreaseWaited();
  waited_ += jobs_.size();
}

double Scheduler::GetAvgWaitTime(void) const {
  int total_jobs = assigned_ + jobs_.size();  // Jobs still in queue + assigned
  return static_cast<double>(waited_) / static_cast<double>(total_jobs);
}