#ifndef MYSHELL_H
#define MYSHELL_H
#include "handl.h"
#include "ls.h"
#include "execut.h"
#include "builtin.h"
#include "mkdir.h"
#include "cat.h"
#include "touch.h"
#include "history.h"
#include "signals.h"
#include "print_prompt.h"



int spilt(char *line, char *args[],int max_args);
#endif