/*************************************************************************
 > File Name: time.c
 > Author: Leafxu
 > Created Time: Wed Oct 24 14:58:31 2018
 ************************************************************************/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>


unsigned long cpu_nsec()
{
    unsigned long currTime;
    struct timespec spec;

    //clock_gettime(CLOCK_MONOTONIC_RAW, &spec);// 435356ns 
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &spec); // 239980ns better
    //clock_gettime(CLOCK_THREAD_CPUTIME_ID, &spec); // 239980ns better
    currTime = (unsigned long)spec.tv_sec*1000000000 + spec.tv_nsec;
	return currTime;
}

unsigned long cpu_usec()
{
    unsigned long currTime;
    struct timespec spec;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &spec); // 239980ns better
    currTime = (unsigned long)spec.tv_sec*1000000 + spec.tv_nsec/1000;
	return currTime;
}

unsigned long cpu_msec()
{
    unsigned long currTime;
    struct timespec spec;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &spec); // 239980ns better
    currTime = (unsigned long)spec.tv_sec*1000 + spec.tv_nsec/1000000;
	return currTime;
}

unsigned long time_usec()
{
	unsigned long currTime;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	currTime = tv.tv_sec * 1000000 + tv.tv_usec;
	return currTime;
}

unsigned long time_msec()
{
	unsigned long currTime;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	currTime = tv.tv_sec*1000 + tv.tv_usec/1000;
	return currTime;
}

// time_t may be long int or int accroding to different platformat.
time_t sys_uptime()
{
    struct sysinfo info;
    sysinfo(&info);
    return info.uptime; // second
}

time_t sys_boottime()
{
	return time(NULL) - sys_uptime(); // second
}

char* seconds_to_date(char* const date, int len, const char* format, time_t sec)
{
	struct tm t;
	if(date==NULL || format==NULL || len<strlen(format)+sizeof(struct tm)+1)
		return NULL;
	localtime_r(&sec, &t);
	strftime(date, len, format, &t);
	return date;
}

time_t date_to_seconds(char* const date, const char* format)
{
	struct tm t;
	if(date==NULL || format==NULL)
		return -1;
	strptime(date, format, &t);
	return mktime(&t);
}

int test(int argc, char** argv){
    
    printf("\n获取系统运行时间\n");
    struct sysinfo info;
    sysinfo(&info);
    //printf("系统运行时间: %ds\n", info.uptime);
    unsigned int seconds = info.uptime;
    int day = seconds/86400;
    seconds %= 86400;
    int hour = seconds/3600;
    seconds %= 3600;
    int minute = seconds/60;
    int second = seconds%60;
    printf("系统运行时间: %d days %02d:%02d:%02d\n", day, hour, minute, second);
    //printf("系统运行时间ctime: %s", ctime((time_t)info.uptime));

    printf("\n获取系统启动时间\n");
    time_t boot_time = time(NULL) - info.uptime;
    struct tm *p = localtime(&boot_time);       // 静态变量无需释放,线程不安全
    printf("%d-%d-%d %d:%d:%d\n", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday,
        p->tm_hour, p->tm_min, p->tm_sec); 

    //int64_t currTime;
    //在linux下获取高精度单调递增的时间
    //syscall(SYS_clock_gettime, CLOCK_MONOTONIC_RAW, &spec);
	return 0;
}



