#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ssem.c"

void *thread();

int main()
{
    pthread_t tid1, tid2;
	ssem_init(2);
	
    if (pthread_create( &tid1, NULL, thread, (void *) 1) || pthread_create( &tid2, NULL, thread, (void *) 2))
        perror("pthread create error"), 1;


	if (ssem_wait())
       perror("ssem wait error"), 1;
    
	sleep(1);
	puts("thread in the critical section");

    if (ssem_post())
    	perror("ssem post error"), 1;


    if (pthread_join( tid1, NULL) || pthread_join( tid2, NULL))
        perror("pthread join error"), 1;

    return 0;
}

void *thread() {
    if (ssem_wait())
        perror( "ssem wait error" ), 1;

	sleep(1);
	puts("thread in the critical section");

    if (ssem_post())
        perror("ssem post error"), 1;

    return NULL;
}