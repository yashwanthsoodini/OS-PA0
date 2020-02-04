#include<stdio.h>
#include<kernel.h>
#include<proc.h>

extern int trace_sys_calls;
unsigned long ctr1000;
char syscall_names[27][20]={"freemem","chprio","getpid","getprio","gettime","kill","receive","recvclr","recvtim","resume","scount","sdelete","send","setdev","setnok","screate","signal","signaln","sleep","sleep10","sleep100","sleep1000","sreset","stacktrace","suspend","unsleep","wait"};

void syscalltrace_start(int syscall_index){
  struct pentry *process = &proctab[currpid];
  process->sys_call_freq[syscall_index] = process->sys_call_freq[syscall_index]+1;
  process->sys_call_start_time[syscall_index] += ctr1000;
}
void syscalltrace_end(int syscall_index){
  struct pentry *process = &proctab[currpid];
  process->sys_call_end_time[syscall_index] += ctr1000;
}

void syscallsummary_start(){
  trace_sys_calls=1;
  int i=0;
  int j=0;
  for(i=0;i<NPROC;i++){
    struct pentry *process = &proctab[i];
    for (j=0;j<27;j++) {
      process->sys_call_freq[j]=0;
      process->sys_call_start_time[j]=0;
      process->sys_call_end_time[j]=0;
    }
  }
}

void syscallsummary_stop(){
	trace_sys_calls=0;
}

void printsyscallsummary(){
	int i = 0;
  int j = 0;
	printf("\n\nvoid printsyscallsummary()");
	for (i = 0; i < NPROC; i++) {
    struct pentry *process = &proctab[i];
    printf("\nProcess [pid:%d]",i);
    for (j = 0; j < 27; j++) {
      if(process->sys_call_freq[j] > 0){
        long start_time_sum = process->sys_call_start_time[j];
        long end_time_sum = process->sys_call_end_time[j];
        long freq = process->sys_call_freq[j];
  			long average_exectime = 0;
        if (start_time_sum < end_time_sum) {
          average_exectime = (end_time_sum - start_time_sum)/freq;
        }
  			printf("\n\tSyscall: sys_%s , count: %d, average execution time: %d (ms)",syscall_names[j], freq, average_exectime);
			}
    }
  }
}
