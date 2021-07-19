/* test program that test for write overflow in small file inside small file directory when call write() with a size larger than the size limit of small file, which is 52 bytes*/



#include "types.h"
#include "user.h"
#include "fcntl.h"



int
main(void){
    int fd;
    //long string that would overflow 
    char buf[100] = "Pretium lorem cursus ad lacinia leo inceptos et.Pretium lorem cursus ad lacinia leo inceptos et.";


    //create a new small file directory
    mkSFdir("sfiledir");  
    
    //create a new small file inside the small file directory we just made 
    fd = open("sfiledir/sfile1", O_CREATE | O_RDWR);
   
    if(fd>=0 ){
        printf(1,"successfully created the small file sfile1\n");

    }else{
        printf(1,"failed to create small file sfile1\n");
        exit();
    }

    //write content inside the small file
    int size = sizeof(buf);
    if(write(fd, &buf, size) != size){
        printf(1, "error: write to sfile1 failed\n");
        exit();
    }
 
    printf(1, "successfully write to sfile1 with size %d\n", size);
    close(fd);
  

    //read content inside the small file we just wrote into

    char readbuf[size];
    fd = open("sfiledir/sfile1", O_RDONLY);
    if(fd>=0 ){
        printf(1,"successfully read the small file sfile1\n");

    }else{
        printf(1,"failed to read small file sfile1\n");
        exit();
    }
    if(read(fd, &readbuf, size) != size){
        printf(1, "error: read from sfile1 failed\n");
        exit();
    }
    printf(1, "successfully read from sfile1\n");

    printf(1, "content in sfile1 is: %s, size of readbuf is%d\n", readbuf, sizeof(readbuf));
    
 

    close(fd);

       
   
    exit();
     


}