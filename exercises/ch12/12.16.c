/*
 *Exercises 12.16
 *
 *jdzhan
 *
 */

#include "../../common/csapp.h"
#include <pthread.h>

void *thread(void *vargp);
int main(int argc, char **argv)
{
    if(argc!=2)
    {
        fprintf(stderr,"usage: %s <thread count> \n",argv[0]);
        exit(0);
    }

    int tc = atoi(argv[1]);

    pthread_t tids[tc];
    int i,*ptr;
    for(i=0; i<tc; i++)
    {
        ptr = malloc(sizeof(int));
        *ptr = i;
        pthread_create(&tids[i],NULL,thread,ptr);
    }

    for(i=0; i<tc; i++)
        pthread_join(tids[i],NULL);

    exit(0);
}

void *thread(void *vargp)
{
    int id = *((int *)vargp);
    free(vargp);
    printf("Hello,world! %d\n",id);
    return NULL;
}

