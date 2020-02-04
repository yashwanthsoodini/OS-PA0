#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
#include <lab1.h>
/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
int main()
{
	printf("\n\nHello World, Xinu lives\n\n");
	setschedclass(LINUXSCHED);
	printf("The current scheduling policy is: %d",getschedclass());
	return 0;
}
