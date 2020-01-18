#include<stdio.h>
#include<kernel.h>
#include<proc.h>

static unsigned long *esp;

void printprocstks(int priority) {
  printf("\n\nvoid printprocstks(int priority)");
  int n = NPROC;
  int i;
  for (i=0; i < n; i++) {
    struct pentry *process = &proctab[i];
    if(process->pprio > priority){
      printf("\nProcess [%s]",process->pname);
			printf("\n\tpid: %d",i);
			printf("\n\tpriority: %d",process->pprio);
			printf("\n\tbase: 0x%08x",process->pbase);
			printf("\n\tlimit: 0x%08x",process->plimit);
			printf("\n\tlen: %d",process->pstklen);
			if(currpid==i){
				asm("movl %esp,esp");
				printf("\n\tpointer: 0x %08x",esp);
			}
			else{
				printf("\n\tpointer: 0x %08x",process->pesp);
			}
    }
  }
}
