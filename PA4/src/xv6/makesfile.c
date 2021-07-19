/* test program that creates small file in small file directory, also write to and read from the small file */


#define SIZE (20)
#include "types.h"
#include "user.h"
#include "fcntl.h"



int
main(void){
    int fd;

    char buf[40] = "Pretium lorem cursus adsfh glorem cursus";



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

    printf(1, "content in sfile1 is: %s\n", readbuf);
    
 

    close(fd);

       
   
    exit();
     


}
