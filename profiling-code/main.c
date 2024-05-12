/*********************************************************************
 * FILE NAME main.c                                                  *
 *                                                                   *
 * PURPOSE                                                           *
 *                                                                   *
 *********************************************************************/

#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //sleep();
#include <time.h>

/*
    CLOCK_REALTIME - system-wide realtime clock.
    CLOCK_PROCESS_CPUTIME_ID - high-resolution per-process timer from the CPU.
    CLOCK_THREAD_CPUTIME_ID - thread-specific CPU-time clock.

    struct timespec time_start, time_stop;

    clock_gettime( CLOCK_REALTIME, &time_start );

    ...
    code
    ...

    clock_gettime( CLOCK_REALTIME, &time_stop );

    PrintTimeDiff( &time_start, &time_stop );

*/

void PrintTimeDiff( struct timespec *time_start,
                    struct timespec *time_stop )
{
    long diff_in_nanosec = time_stop->tv_nsec - time_start->tv_nsec;

    if ( diff_in_nanosec < 0 )
    {
        printf( "%ld:%09ld\n",
                time_stop->tv_sec - time_start->tv_sec - 1,
                1000000000 + diff_in_nanosec );
    }
    else
    {
        printf( "%ld:%09ld\n",
                time_stop->tv_sec - time_start->tv_sec,
                diff_in_nanosec );
    }

}

int main()
{

    struct timespec time_start, time_stop;

    printf("wait 1 sec\n");

    clock_gettime( CLOCK_REALTIME, &time_start );

    sleep(1);   //1 sec

    clock_gettime( CLOCK_REALTIME, &time_stop );

    PrintTimeDiff( &time_start, &time_stop );

    /************************************************************/

    struct timespec nano_sleep_time;

    //1.2 sec
    nano_sleep_time.tv_sec = 1;
    nano_sleep_time.tv_nsec = 200000000;

    printf("wait 1.2 sec\n");

    clock_gettime( CLOCK_REALTIME, &time_start );

    nanosleep( &nano_sleep_time, NULL );

    clock_gettime( CLOCK_REALTIME, &time_stop );

    PrintTimeDiff( &time_start, &time_stop );

    /************************************************************/

    nano_sleep_time.tv_sec = 0;
    nano_sleep_time.tv_nsec = 0;

    printf("twenty times +0.07 sec (CLOCK_REALTIME)\n");

    for ( int i = 0; i < 20; ++i )
    {
        long tmp = nano_sleep_time.tv_nsec + 70000000;

        if ( tmp >= 1000000000 )
        {
            nano_sleep_time.tv_sec += 1;
            nano_sleep_time.tv_nsec = tmp - 1000000000;
        }
        else
        {
            nano_sleep_time.tv_nsec = tmp;
        }

        clock_gettime( CLOCK_REALTIME, &time_start );

        nanosleep( &nano_sleep_time, NULL );

        clock_gettime( CLOCK_REALTIME, &time_stop );

        PrintTimeDiff( &time_start, &time_stop );
    }

    /************************************************************/

    printf("CLOCK_PROCESS_CPUTIME_ID\n");

    clock_gettime( CLOCK_PROCESS_CPUTIME_ID, &time_start );

    nanosleep( &nano_sleep_time, NULL );

    clock_gettime( CLOCK_PROCESS_CPUTIME_ID, &time_stop );

    PrintTimeDiff( &time_start, &time_stop );


    return 0;
}
