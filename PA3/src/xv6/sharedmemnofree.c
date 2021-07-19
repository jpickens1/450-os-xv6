/* 	CS450 Fall 2019
	Programming Assignment 3
	Jingwen Pickens (A20349887)
	Anthony Pollizi (A20413465)

	This test is designed to ensure that processes which use Getsharedpage but fail to free it before exiting still decrement the reference count of the shared page and allow it to be freed from physical memory if there are no other processes using that page. 

*/


#include "types.h"
#include "user.h"
#include "memlayout.h"

	
int
main(void)
{


	int* addr =(int*) getsharedpage(0,1);
	
	
	exit();
	printf(1, "%x", addr);
}
