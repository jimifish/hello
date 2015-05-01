#include <stdarg.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#define MAX_LOG 200
#define LOG_TIMESTAMP_SIZE 25

typedef enum
{
	LOG_ERR,
	LOG_INFO,
	LOG_DEBUG,
}LOG_LEVEL;

void jimmy_debug(LOG_LEVEL lvl, char *fmt, ...)
{
    va_list args;
    char buf[MAX_LOG];
	char* szLevel;
	char stamp[LOG_TIMESTAMP_SIZE] = {};
    char* pos;
    int sz; 
    time_t t;
   
	switch(lvl)
	{
		case LOG_ERR:
			szLevel = "ERROR";
		break;
		case LOG_INFO:
			szLevel = "INFO";
		break;
		case LOG_DEBUG:
			szLevel = "DEBUG";
		break;
	}

    /* timestamp */
    t = time(NULL);
    pos = ctime(&t);
    sz = strlen(pos);
    pos[sz-1] = ' ';
   
	snprintf(stamp, LOG_TIMESTAMP_SIZE, "%s", pos);   	

    FILE *fd, *fd1;
    va_start(args, fmt);
    vsnprintf(buf, MAX_LOG, fmt, args);
    va_end(args);
    //fd = fopen("/tmp/jimmy.log", "a+");/*fopen("/dev/console", "a+");*/ /*fopen("/dev/ttyS2","a+");*/
           
	fd = fopen("/dev/tty", "a+");
	fprintf(fd, "[%s] %s %s", szLevel, stamp, buf);
	fclose(fd);

	fd1 = fopen("/tmp/jimmy.log", "a+");
	fprintf(fd1, "[%s] %s", szLevel, buf);
	fclose(fd1);
} 
