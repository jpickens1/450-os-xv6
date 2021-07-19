/* 	CS450 Fall 2019
	Programming Assignment 3
	Jingwen Pickens (A20349887)
	Anthony Pollizi (A20413465)

	This test is designed to execute to completion if and only if a value can be communicated between a forked child process and the parent process. 
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
	//freesharedpage(0);

	if(fork()==0){
		int* addr2 = (int*)getsharedpage(0,1);
		for(;;){
			if(*addr2 == 6){
				printf(1, "breaking from child loop\n");
				break;
			}
		}
		*addr2 = 7;
		freesharedpage(0);
		exit();
	}	
	*addr = 6;
	//wait();
	for(;;){
		if(*addr == 7){
			printf(1, "breaking from parent loop\n");
			break;
		}
	} 
	//wait();
	freesharedpage(0);
	exit();
	
	printf(1, "addr = %x\ncontent = %d\n", addr, *addr);
	return 0;
}
