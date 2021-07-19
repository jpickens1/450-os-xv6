
#include "types.h"
#include "user.h"
#include "fcntl.h"
#define SIZE (20) 
int t_overflow(void);
int t_regfiles(void);
int t_sfiles(void);
int t_dirs(void);
int t_unlink(void);



int t_overflow(){

    int fd;
    //long string that would overflow 
    char buf[100] = "Pretium lorem cursus ad lacinia leo inceptos et.Pretium lorem cursus ad lacinia leo inceptos et.";


    //create a new small file directory
    mkSFdir("sdir");  
    printf(1, "Made small file directory 'sdir'\n");
    //create a new small file inside the small file directory we just made 
    fd = open("sdir/sfile", O_CREATE | O_RDWR);
   
    if(fd>=0 ){
        printf(1,"successfully created the small file sfile\n");

    }else{
        printf(1,"failed to create small file sfile\n");
        return 0;
    }

    //write content inside the small file
    int size = sizeof(buf);
    if(write(fd, &buf, size) != size){
        printf(1, "error: write to sfile1 failed\n");
        return 1;
    }
    else{
      printf(1, "successfully write to sfile1 with size %d\n", size);
      close(fd);
    }  

    //read content inside the small file we just wrote into

    char readbuf[size];
    fd = open("sdir/sfile", O_RDONLY);
    if(fd>=0 ){
        printf(1,"successfully opened the small file sfile\n");

    }else{
        printf(1,"failed to read small file sfile\n");
        return 0;
    }
    if(read(fd, &readbuf, size) != size){
        printf(1, "error: read from sfile failed\n");
        return 0;
    }
    printf(1, "successfully read from sfile\n");

    printf(1, "content in sfile is: %s, size of readbuf is%d\n", readbuf, sizeof(readbuf));
    
    return 1; 
}

int t_regfiles(){

    int fd;
    char buf[100] = "Pretium lorem cursus ad lacinia leo inceptos et.Pretium lorem cursus ad lacinia leo inceptos et. ";


    //create a regular file directory
    mkdir("regulardir");
    
    //create a regular file inside the regular file directory we just created 
    fd = open("regulardir/regularfile", O_CREATE | O_RDWR);
    
    if(fd>=0 ){
        printf(1,"successfully created the regular file 'regularfile'\n");

    }else{
        printf(1,"failed to create regular file 'regularfile'\n");
        return 0;
    }

    //write content inside the regular file
    int size = sizeof(buf);
    if(write(fd, &buf, size) != size){
        printf(1, "error: write to sfile1 failed\n");
        return 0;
    }
 
    printf(1, "successfully write to 'regularfile'\n");
    close(fd);
  

    //read content inside the regular file we just wrote into

    char readbuf[size];
    fd = open("regulardir/regularfile", O_RDONLY);
    if(fd>=0 ){
        printf(1,"successfully read the regular file 'regularfile'\n");

    }else{
        printf(1,"failed to read regular file 'regularfile'\n");
        return 0;
    }
    if(read(fd, &readbuf, size) != size){
        printf(1, "error: read from 'regularfile' failed\n");
        return 0;
    }
    printf(1, "successfully read from 'regularfile'\n");

    printf(1, "content in regularfile is: %s\n", readbuf);
    
    return 1;

}

int t_sfiles(){


    int fd;

    char buf[40] = "Pretium lorem cursus ad lorem cursus.";



    //create a new small file directory
    mkSFdir("sfiledirtest");  

    
    //create a new small file inside the small file directory we just made 
    fd = open("sfiledirtest/sfile1", O_CREATE | O_RDWR);

    if(fd>=0 ){
        printf(1,"successfully created 'sfile1'\n");

    }else{
        printf(1,"failed to create 'sfile1'\n");
        return 0;
    }

    //write content inside the small file

    int size = sizeof(buf);
    if(write(fd, &buf, size) != size){
        printf(1, "error: write to 'sfile1' failed\n");
        return 0;
    }
 
    printf(1, "successfully write to 'sfile1' with size %d\n", size);

    close(fd);
  

    //read content inside the small file we just wrote into


    char readbuf[size];

    fd = open("sfiledirtest/sfile1", O_RDONLY);
    if(fd>=0 ){
        printf(1,"successfully read from 'sfile1'\n");

    }else{
        printf(1,"failed to read from 'sfile1'\n");
        return 0;
    }

    if(read(fd, &readbuf, size) != size){
  	    return 0;
    }

    printf(1, "content in 'sfile1' is: %s\n", readbuf);
    return 1;
}


int t_dirs(){
    int fd1, fd2, fd3, fd4;
    mkSFdir("sdir");
    printf(1, "Made sdir\n");
    mkSFdir("sdir/isdir");
  
    printf(1, "Made sdir/isdir\n");
    mkdir("sdir/idir");
   
    printf(1, "Made sdir/idir\n");
    mkdir("dir");
   
    printf(1, "Made dir\n");
    mkSFdir("dir/sdir");
   
    printf(1, "Made dir/sdir\n");
   
    if(!( (fd1 = open("sdir", O_RDWR)) &&
	  (fd2 = open("sdir/isdir", O_RDWR)) &&
	  (fd3 = open("dir", O_RDWR)) &&
	  (fd4 = open("dir/sdir", O_RDWR)))){
    	printf(1, "A directory failed to open\n");
	return 0;
    }
    return 1;
}

int t_unlink(){

    int fd;

    fd = open("sdir/sfiletodelete", O_CREATE | O_RDWR);

    if(fd>=0 ){
        printf(1,"successfully created the small file 'smallfiletodelete' in sdir\n");
    }else{
        printf(1,"failed to create the small file 'smallfiletodelete' in sdir\n");
    }


	if(!unlink("sdir/sfiletodelete")){
		printf(1, "successfully deleted the small file 'smallfiletodelete' in sdir\n");
		return 1;
	}
	printf(1, "failed to delete small file\n");
	return 0;
}

int main (int argc, char* argv[])
{
/*	if (!argv[1]){
		printf(1, "No test selected, please enter 'tests 0' for all tests or 'tests X' where X is the test number\n");
		exit();
	}*/

	switch ((int)argv[1]){
	  case '1':
		if(!t_overflow())
			printf(1, "Test overflow (1) failed\n");
		else printf(1, "Test overflow (1) passed\n\n");	
		break;
	  
	  case '2':
		if(!t_regfiles())
			printf(1, "Test regfiles (2) failed\n");
		else printf(1, "Test regfiles (2) passed\n\n");	
		break;
		
	  case '3':
		if(!t_sfiles())
			printf(1, "Test sfiles (3) failed\n");
		else printf(1, "Test sfiles (3) passed\n\n");	
		break;
	  case '4':
		if(!t_dirs())
			printf(1, "Test dirs (4) failed\n");
		else printf(1, "Test dirs (4) passed\n\n");	
		break;
	
	  case '5':
		if(!t_unlink())
			printf(1, "Test unlink (5) failed\n");
		else printf(1, "Test unlink (5) passed\n\n");	
		break;
 	  default:
	
		if(!t_overflow())
			printf(1, "Test overflow (1) failed\n");
		else printf(1, "Test overflow (1) passed\n\n");	
	

		if(!t_regfiles())
			printf(1, "Test regfiles (2) failed\n");
		else printf(1, "Test regfiles (2) passed\n\n");	
	

		if(!t_sfiles())
			printf(1, "Test sfiles (3) failed\n");
		else printf(1, "Test sfiles (3) passed\n\n");	
	

		if(!t_dirs())
			printf(1, "Test dirs (4) failed\n");
		else printf(1, "Test dirs (4) passed\n\n");	

		if(!t_unlink())
			printf(1, "Test unlink (5) failed\n");
		else printf(1, "Test unlink (5) passed\n\n");	
		
		break;
	}
	exit();
	
}
