#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[])
{
	pid_t process_id = 0, session_id = 0;

	process_id = fork();

	if (process_id < 0)
	{
		exit(1);
	}
	printf("Process %d \n", process_id);

	umask(0);
	
	session_id = setsid();

	if (session_id < 0)
		exit(1);
	
	while (1)
	{
		sleep(100);
	}
	return (0);
}