/*************************************************************************
 > File Name: time.h
 > Author: Leafxu
 > Created Time: Wed Oct 24 15:04:41 2018
 ************************************************************************/
#ifndef _TIMING_H_
#define _TIMING_H_
#ifdef __cplusplus
#include <time.h>
extern "C" {
#endif
	unsigned long cpu_nsec();
    unsigned long cpu_usec();
    unsigned long cpu_msec();
    unsigned long time_usec();
    unsigned long time_msec();
    time_t sys_uptime();
    time_t sys_boottime();
	char* seconds_to_date(char* const date, int len, const char* format, time_t sec);
	time_t date_to_seconds(char* const date, const char* format);
#ifdef __cplusplus
}
#endif
#endif
