#include <stdarg.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

void jimmy_debug(char *fmt, ...)
{
    const int MAX_LOG = 200;
    va_list args;
    char buf[MAX_LOG];
    char* pos;
    int sz;
    time_t t;
   
    /* timestamp */
    t = time(NULL);
    pos = ctime(&t);
    sz = strlen(pos);
    pos[sz-1] = ' ';
   
    snprintf(buf, MAX_LOG, "%s ", pos);
   
    /*find the end and attach the rest of the msg*/
    for(pos = buf; *pos != '\0'; pos++);
    sz = pos - buf;
   
    FILE *fd, *fd1;
    va_start(args, fmt);
    vsnprintf(pos, MAX_LOG - sz, fmt, args);
    va_end(args);
    //fd = fopen("/tmp/jimmy.log", "a+");/*fopen("/dev/console", "a+");*/ /*fopen("/dev/ttyS2","a+");*/
    //fprintf(fd, "%s", buf);       
    //fclose(fd);
	
	fd = fopen("/dev/tty", "a+");
	fprintf(fd, "%s", buf);
	fclose(fd);
}


