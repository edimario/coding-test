#ifndef JOB_H
#define JOB_H

class Job {
 public:
  Job(int resources, int time);
  int resources(void) const {return resources_;}
  int time_left(void) const {return time_left_;}  
 private:
  int resources_;
  int time_left_;
};

#endif
