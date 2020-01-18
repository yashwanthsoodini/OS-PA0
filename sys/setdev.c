/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include "lab0.h"

extern int trace_sys_calls;

/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	if (trace_sys_calls == 1) {
	  syscalltrace_start(13);
	}
	short	*nxtdev;

	if (isbadpid(pid))
		return(SYSERR);
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
	if (trace_sys_calls == 1) {
	  syscalltrace_end(13);
	}
	return(OK);
}
