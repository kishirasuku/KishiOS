#pragma once
#include "common.h"
#include "libs/syscall.h"

__attribute__((noreturn)) void exit(void);
void putchar(char ch);
int getchar(void);
void getSbiVersion(void);