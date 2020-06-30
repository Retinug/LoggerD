#include "config.h"

int findSymbol(char* str, int length, int offset, char symbol)
{
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] == symbol)
			return i;
	}
	return -1;
}

int readConfig()
{
	char buff[CONFIG_LENGTH];
	int file = open(FILECONFIG, O_RDONLY);
	int size = read(file, buff, CONFIG_LENGTH);

	close(file);

	return 0;
}

int writeConfig()
{
	int file;
	file = open(FILECONFIG, O_CREAT | O_WRONLY);

	write(file, CONFIG_TIMER, sizeof(CONFIG_TIMER) - 1);
	write(file, CONFIG_FILEOUT, sizeof(CONFIG_FILEOUT) - 1);

	close(file);
	return 0;
}