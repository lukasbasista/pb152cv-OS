#include <pthread.h>
#include <stdio.h>

int proceed = 0;

int ssem_init( int x ) {
	proceed = x;
	return 0;
}

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int ssem_wait() {
	while (proceed <=0){}

	if ( pthread_mutex_lock( &mutex ) )
		perror( "mutex lock error" ), 1;
	
	--proceed;

	if ( pthread_mutex_unlock( &mutex ) )
		perror( "mutex unlock error" ), 1;
	
	return 0;
}

int ssem_post() {
	if ( pthread_mutex_lock( &mutex ) )
		perror( "mutex lock error" ), 1;
	
	++proceed;

	if ( pthread_mutex_unlock( &mutex ) )
		perror( "mutex unlock error" ), 1;
	return 0;
}