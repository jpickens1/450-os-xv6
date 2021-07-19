
#include "types.h"
#include "user.h"
#include "fcntl.h"

int
main(void){
    
    mkSFdir("sdir");
    mkSFdir("sdir/isdir");
    mkdir("sdir/idir");
    mkdir("dir");
    mkSFdir("dir/sdir");
    exit(); 
}
