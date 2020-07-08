#include "config.h"

int findIndexSubstring(char* str, int length, char* substr, int lengthSub)
{
	int isFind = TRUE;
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] == substr[0])
		{
			size_t j;
			for (j = 0; j < lengthSub; j++)
			{
				if (str[i + j] != substr[j])
				{
					isFind = FALSE;
					break;
				}
			}
			if (isFind)
			{
				return i + j;
			}

			isFind = TRUE;
		}
	}

	return -1;
}

int findSymbol(char* str, int length, int offset, char symbol)
{
	for (size_t i = offset; i < length; i++)
	{
		if (str[i] == symbol)
			return i;
	}
	return -1;
}

char* findArg(char* buffer, int bufferLenght, char* searchStr, int lenght)
{
	int res, end, diff;
	char* argBuff;

	res = findIndexSubstring(buffer, bufferLenght, searchStr, lenght);
	end = findSymbol(buffer, bufferLenght, res, '\n');
	diff = end - res;
	argBuff = (char*)malloc((end - res) * sizeof(char));
	for (size_t i = 0; i < diff; i++)
	{
		argBuff[i] = buffer[res + i];
	}
	return argBuff;
}

int readConfig()
{
	char buff[CONFIG_LENGTH];
	int file = open(FILECONFIG, O_RDONLY);
	int size = read(file, buff, CONFIG_LENGTH);

	close(file);

	char* buffer;

	path = findArg(buff, CONFIG_LENGTH, CONFIG_FILEOUT, sizeof(CONFIG_FILEOUT) - 2);
	buffer = findArg(buff, CONFIG_LENGTH, CONFIG_TIMER, sizeof(CONFIG_TIMER) - 2);
	timer = atoi(buffer);
	free(buffer);

	return 0;
}

int writeConfig()
{
	int file;

	file = open(FILECONFIG, O_WRONLY);
	if (file == -1)
	{
		file = open(FILECONFIG, O_CREAT | O_WRONLY);
		write(file, CONFIG_FILEOUT, sizeof(CONFIG_FILEOUT) - 1);
		write(file, CONFIG_TIMER, sizeof(CONFIG_TIMER) - 1);
	}

	close(file);
	return 0;
}