#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>

atomic_int atomic_counter = 0;
int counter = 0;

void *IncrementCounter( void *thread_data )
{

    /* Silence compiler warning for unused parameters: thread_data */

    (void)thread_data;


    for( int j = 0; j < 10000; ++j )
    {
        atomic_fetch_add( &atomic_counter, 1 );
        counter++;
    }

    return NULL;
}

int main()
{
    #define NUM_OF_THREADS 4

    pthread_t threads[ NUM_OF_THREADS ];

    for ( int i = 0; i < NUM_OF_THREADS; ++i )
    {
        pthread_create( &threads[i], NULL, IncrementCounter, NULL );
    }

    for ( int i = 0; i < NUM_OF_THREADS; ++i )
    {
        pthread_join( threads[i], NULL );
    }

    printf("The atomic counter value is: %d\n", atomic_counter );
    printf("The non atomic counter value is: %d\n", counter );

    return 0;
}
