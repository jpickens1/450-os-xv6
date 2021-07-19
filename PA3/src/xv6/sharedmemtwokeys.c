/* 	CS450 Fall 2019
	Programming Assignment 3
	Jingwen Pickens (A20349887)
	Anthony Pollizi (A20413465)

	This test is designed to ensure that multiple shared pages can be used by a single process, and also demonstrates that the system call Getsharedmem also deletes values from the shared pages.

*/

#include "types.h"
#include "user.h"
#include "memlayout.h"

	
int
main(void)
{


	int* addr =(int*) getsharedpage(0,1);
	*addr = 6;	
	int * addr2 = (int*)  getsharedpage(2,1);
	*addr2 = 12;
	printf(1, "addr = %d\naddr2 = %d\n", *addr, *addr2);
	freesharedpage(0);
	freesharedpage(2);
	exit();	

}	
