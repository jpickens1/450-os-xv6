/* 	CS450 Fall 2019
	Programming Assignment 3
	Jingwen Pickens (A20349887)
	Anthony Pollizi (A20413465)

	This test is designed to ensure that using the Freesharedpage system call on a key which corresponds to a shared page with a value in it makes that value inaccessible to the process which has freed that key.
*/


#include "types.h"
#include "user.h"
#include "memlayout.h"

	
int
main(void)
{


	int* addr =(int*) getsharedpage(0,1);
	*addr = 6;	
	printf(1, "addr = %x\ncontent = %d\n", addr, *addr);
	*addr =6;	
	freesharedpage(0);
	printf(1, "addr = %x\ncontent = %d\n", addr, *addr);
	exit();
}
