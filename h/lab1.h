// Constants that represent the two scheduling policy
#define RANDOMSCHED 1
#define LINUXSCHED 2

// Declare getter and setter for the current scheduling policy
void setschedclass(int sched_class);
int getschedclass();
extern int schedClass;