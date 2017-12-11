//__thread是gcc的线程私有变量，每个线程都拥有一个独立实体，且相互不影响，只能存储pod类型变量，存储方式可以是static和extern, 初始化为编译期常量
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

__thread int var = 1;

void* Work1(void* arg)
{
    printf("Work1 var = %d\n", ++var);
}

void* Work2(void* arg)
{
    sleep(2);
    printf("Work2 var = %d\n", ++var);
}

int main()
{
    printf("testing __thread \n");

    pthread_t nPid1, nPid2;
    pthread_create(&nPid1, NULL, Work1, NULL);
    pthread_create(&nPid2, NULL, Work2, NULL);

    pthread_join(nPid1, NULL);
    pthread_join(nPid2, NULL);

    return 0;
}
