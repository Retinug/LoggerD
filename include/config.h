#pragma once

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define FILECONFIG "/etc/LoggerD.conf"

#define CONFIG_TIMER "TIMER=\n"
#define CONFIG_FILEOUT "FILE_OUTPUT=\n"

int readConfig();

int writeConfig();