
/* 	CS450 Fall 2019
	Programming Assignment 3
	Jingwen Pickens (A20349887)
	Anthony Pollizi (A20413465)

	This test is designed to ensure that if a process has requested the same shared page with the same key twice and writes a value into one reference to that shared page, that both references to that page share the same contents. 

*/
#include "types.h"
#include "user.h"
#include "memlayout.h"

	
int
main(void)
{


	int* addr =(int*) getsharedpage(2,1);
		
	int * addr2 = (int*)  getsharedpage(2,1);
	*addr2 = 12;
	*addr = 6;
	printf(1, "addr = %d\naddr2 = %d\n", *addr, *addr2);
	//freesharedpage(2);
	freesharedpage(2);
	exit();	

}	
