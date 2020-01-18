/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include "lab0.h"

extern int trace_sys_calls;
/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	if (trace_sys_calls == 1) {
	  syscalltrace_start(2);
	}
	if (trace_sys_calls == 1) {
	  syscalltrace_end(2);
	}
	return(currpid);
}
