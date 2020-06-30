#pragma once

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FILECONFIG "/etc/LoggerD.conf"

#define CONFIG_TIMER "TIMER=\n"
#define CONFIG_FILEOUT "FILE_OUTPUT=\n"

#define CONFIG_LENGTH 128

extern int timer;
extern char* path;

int findSymbol(char* str, int length, int offset, char symbol);

int readConfig();

int writeConfig();