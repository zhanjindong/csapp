/*
 * p658
 *
 * 创建一个对等线程
 *
 */


#include <pthread.h>
void *thread(void *vargp);

int main(int argc, char **argv)
{
    pthread_t tid;
    pthread_create(&tid,NULL,thread,NULL);
    pthread_join(tid,NULL);
    exit(0);
}

void *thread(void *vargp)
{
    printf("Hello,world!\n");
    return NULL;
}

