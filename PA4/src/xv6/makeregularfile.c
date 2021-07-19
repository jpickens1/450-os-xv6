/* test program that makes ssure that creating regular files in regular directory still works properly, also write and read to it*/



#include "types.h"
#include "user.h"
#include "fcntl.h"



int
main(void){
    int fd;
    char buf[100] = "Pretium lorem cursus ad lacinia leo inceptos et.Pretium lorem cursus ad lacinia leo inceptos et. ";


    //create a regular file directory
    mkdir("regulardir");
    
    //create a regular file inside the regular file directory we just created 
    fd = open("regulardir/regularfile", O_CREATE | O_RDWR);
    //fd = open("regular/regularfile", O_CREATE | O_RDWR);
    if(fd>=0 ){
        printf(1,"successfully created the regular file 'regularfile'\n");

    }else{
        printf(1,"failed to create regular file 'regularfile'\n");
        exit();
    }

    //write content inside the regular file
    int size = sizeof(buf);
    if(write(fd, &buf, size) != size){
        printf(1, "error: write to sfile1 failed\n");
        exit();
    }
 
    printf(1, "successfully write to 'regularfile'\n");
    close(fd);
  

    //read content inside the regular file we just wrote into

    char readbuf[10];
    fd = open("regulardir/regularfile", O_RDONLY);
    if(fd>=0 ){
        printf(1,"successfully read the regular file 'regularfile'\n");

    }else{
        printf(1,"failed to read regular file 'regularfile'\n");
        exit();
    }
    if(read(fd, &readbuf, 10) != 10){
        printf(1, "error: read from 'regularfile' failed\n");
        exit();
    }
    printf(1, "successfully read from 'regularfile'\n");

    printf(1, "content in sfile1 is: %s\n", readbuf);
    
 

    close(fd);

       
   
    exit();
     


}