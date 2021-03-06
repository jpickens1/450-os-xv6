/* 	CS450 Fall 2019
	Programming Assignment 3
	Jingwen Pickens (A20349887)
	Anthony Pollizi (A20413465)

  sys_getsharedpage() calls sharedmempage() that is defined in vm.c
  sys_freesharedpage() calls freesharepage() that is designed in vm.c 
*/

#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_getsharedpage(void){
 int key;
 int numPages;
 if( argint(0,&key) < 0 || argint(1,&numPages) < 0 ){
 	return -1;
 }
  
   return (int)sharedmempage(key, numPages, myproc());
}

int sys_freesharedpage(void){
  int key;
  if(argint(0,&key) < 0){
  	return -1;
  }
  freesharedpage(key, myproc());
 return 0;
}
