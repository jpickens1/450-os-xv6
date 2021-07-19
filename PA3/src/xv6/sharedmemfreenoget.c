/* 	CS450 Fall 2019
	Programming Assignment 3
	Jingwen Pickens (A20349887)
	Anthony Pollizi (A20413465)

	This test is designed to ensure that using the Freesharedpage system call on a key which the calling process is not associated with has no effect and is acknowledged by an error printout in the kernel’s execution of the system call.

*/
#include "types.h"
#include "user.h"
#include "memlayout.h"

	
int
main(void)
{


	freesharedpage(0);
	
	
	exit();
}
