
/* 	CS450 Fall 2019
	Programming Assignment 3
	Jingwen Pickens (A20349887)
	Anthony Pollizi (A20413465)

	This test is designed to ensure that processes which try to free a page which they were once associated with but have already freed receive the appropriate error message informing it that that page has already been freed and that the calling process is no longer associated with that key. 

*/


#include "types.h"
#include "user.h"
#include "memlayout.h"

	
int
main(void)
{


	int* addr =(int*) getsharedpage(0,1);
	freesharedpage(0);
	freesharedpage(0);
	printf(1, "addr %x has contents %d\n", addr, *addr);	
	exit();
}
