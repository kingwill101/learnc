#pragma once
#include <stdio.h>


#define LOG_ERROR 1
#define LOG_DEBUG 2

#define log(msg) _log(stdout, __FILE__, __LINE__, msg, LOG_DEBUG)

#define error(msg) _log(stderr, __FILE__, __LINE__, msg, LOG_ERROR)

void _log(FILE *fd, char *file, int line, char *msg, int level) {
	if(level == LOG_ERROR){
				fprintf(fd, "%s:%d [ERROR] \033[31;31m %s \033[m\n", file, line, msg);
	}else{
		fprintf(fd, "%s:%d %s", file, line, msg);
	}
}
