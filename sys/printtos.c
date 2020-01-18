#include <stdio.h>
static unsigned long *esp;
static unsigned long *ebp;

void printtos(){
  asm("movl %ebp, ebp");
  asm("movl %esp, esp");
  printf("\nvoid printtos()");
  printf("\nBefore[0x%08x]:0x%08x",ebp+2,*(ebp+2));
	printf("\nAfter [0x%08x]:0x%08x",ebp, *ebp);
  int i=1;
  while (i<=4 && ebp>=esp+i) {
    printf("\n\t");
    printf("element[0x%08x]: 0x%08x",esp+i,*(esp+i));
    i++;
  }
}
