#include "config.h"

int readConfig()
{
	return 0;
}

int writeConfig()
{
	printf("File created\n");
	int file;
	file = open(FILECONFIG, O_CREAT | O_WRONLY);

	write(file, CONFIG_TIMER, sizeof(CONFIG_TIMER) - 1);
	write(file, CONFIG_FILEOUT, sizeof(CONFIG_FILEOUT) - 1);

	close(file);
	printf("end");
	return 0;
}