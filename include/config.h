#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <malloc.h>
#define FILECONFIG "/etc/LoggerD.conf"

#define CONFIG_TIMER "TIMER=\n"
#define CONFIG_FILEOUT "FILE_OUTPUT=\n"

#define CONFIG_LENGTH 128

#define FALSE 0
#define TRUE 1

static char* path;
static int timer;

int findIndexSubstring(char* str, int length, char* substr, int lengthSub);

int findSymbol(char* str, int length, int offset, char symbol);

char* findArg(char* buffer, int bufferLenght, char* searchStr, int lenght);

int readConfig();

int writeConfig();