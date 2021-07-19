/* 	CS450 Fall 2019
	Programming Assignment 3
	Jingwen Pickens (A20349887)
	Anthony Pollizi (A20413465)

	This test is designed to demonstrate the bizarre functionality of the printf function to delete values stored in shared memory pages.
*/

#include "types.h"
#include "user.h"

int
main(void)
{
	int* addr =(int*) getsharedpage(0,5); //Get 5 pages of shared memory
	*addr = 6; //set a value in that shared memory	
	printf(1, "addr = %x\ncontent = %d\n", addr, *addr); //Print out the value that we just put at that address and the address where we put it
	printf(1, "addr = %x\ncontent = %d\n", addr, *addr); //Now do that exact same thing again. Expect the same output? You should, but you'd be wrong.

	freesharedpage(0); //Free up the sharedpage
	exit();
		
}
