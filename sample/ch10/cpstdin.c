#include "../../common/csapp.h"

int main(int argc, char **argv)
{
    char c;
    while(Read(STDIN_FILENO,&c,1)!=0)
    {
        Write(STDOUT_FILENO,&c,1);
    }
    exit(0);
}
