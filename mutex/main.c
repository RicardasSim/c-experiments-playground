#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long int counter;
pthread_mutex_t lock;

#define ITERATION_NUM 10000

void *IncrementCounter( void *thread_data )
{

    /* Silence compiler warning for unused parameters: thread_data */

    (void)thread_data;

    for( int j = 0; j < ITERATION_NUM; ++j )
    {
        counter++;
    }

    return NULL;
}

void *IncrementCounterWithMutex( void *thread_data )
{

    /* Silence compiler warning for unused parameters: thread_data */

    (void)thread_data;

    pthread_mutex_lock( &lock );

    for( int j = 0; j < ITERATION_NUM; ++j )
    {
        counter++;
    }

    pthread_mutex_unlock( &lock );

    return NULL;
}

int main()
{
    #define NUM_OF_THREADS 4

    pthread_t threads[ NUM_OF_THREADS ];

    counter = 0;

    for ( int i = 0; i < NUM_OF_THREADS; ++i )
    {
        pthread_create( &threads[i], NULL, IncrementCounter, NULL );
    }

    for ( int i = 0; i < NUM_OF_THREADS; ++i )
    {
        pthread_join( threads[i], NULL );
    }

    printf("The counter value is: %ld\n", counter );

    /**********************************************************************/

    if ( pthread_mutex_init( &lock, NULL ) != 0 )
    {
        printf("Mutex init failed.\n");
        return 1;
    }

    counter = 0;

    for ( int i = 0; i < NUM_OF_THREADS; ++i )
    {
        pthread_create( &threads[i], NULL, IncrementCounterWithMutex, NULL );
    }

    for ( int i = 0; i < NUM_OF_THREADS; ++i )
    {
        pthread_join( threads[i], NULL );
    }

    printf("The counter value is (with mutex): %ld\n", counter );

    pthread_mutex_destroy( &lock );

    return 0;
}
