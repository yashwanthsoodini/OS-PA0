/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include "lab0.h"

extern int trace_sys_calls;

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{
extern	struct	sentry	semaph[];
	if (trace_sys_calls == 1) {
		syscalltrace_start(10);
	}

	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
		if (trace_sys_calls == 1) {
			syscalltrace_end(10);
		}
		return(SYSERR);
	if (trace_sys_calls == 1) {
		syscalltrace_end(10);
	}
	return(semaph[sem].semcnt);
}
