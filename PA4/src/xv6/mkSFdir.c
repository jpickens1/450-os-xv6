/* 	CS450 Fall 2019
	Programming Assignment 4
	Jingwen Pickens (A20349887)
	Anthony Pollizi (A20413465)

*/


#include "user.h"
#include "types.h"

int 
main(int argc, char* argv[])
{
 if( mkSFdir(argv[1]) ){
   return 1;
 }
  return 0;
}
