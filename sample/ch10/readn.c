#include "../../common/csapp.h"

int main(int argc, char **argv)
{
    int fd = open("/usr/local/csapp/res/foo.txt",O_RDONLY,0);
    char buff[1024];
    int ret = rio_readn(fd,buff,1024);
    printf("ret = %d,cont = %s",ret,buff);
    exit(0);
}
