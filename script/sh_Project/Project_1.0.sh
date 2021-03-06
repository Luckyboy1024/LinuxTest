#!/bin/bash 
name=./project-name

fill_makefile()
{
echo "#Makefile of project 
SRC_DIR := ./srcs
OBJ_DIR := ./objs
DEBUG_DIR := ./srcs/Debug

# Compilation flags         
CC := gcc 
LD := gcc 
## flags
CFLAGS := -Wall 
LFLAGS :=
# args
RELEASE := 0
BITS :=
## [args] 生成模式，0代表debug模式; 1代表release模式，make RELEASE=1
ifeq (\$(RELEASE),0)
	CFLAGS += -g
else 
	CFLAGS += -static -o3 -DNDEBUG
	LFLAGS += -static 
endif

## [args] 程序位数，32代表32程序，64代表64程序，其他默认，make BITS=32
ifeq (\$(BITS),32)
	CFLAGS += -m32
	LFLAGS += -m32 
else 
	ifeq (\$(BITS),64)
		CFLAGS += -m64
		LFLAGS += -m64 
	else 
	endif 
endif 

# Files to be compiled	
SRCS := \$(wildcard \$(SRC_DIR)/*.c)
OBJS := \$(SRCS:\$(SRC_DIR)/%.c=\$(OBJ_DIR)/%.o)

time := \$(shell date +%H:%M:%S)

DEBUGS := \$(DEBUG_DIR)/out-\$(time)
TARGETS := ./all.out ./all.exe 

.PHONY: all clean

all:\$(TARGETS)

\$(TARGETS): \$(OBJS)
	@echo + LD \$@
	@\$(LD) \$(LFLAGS) -o \$@ $^
	@mkdir -p \$(DEBUG_DIR)
	@\$(LD) \$(LFLAGS) -o \$(DEBUGS) $^ 

\$(OBJ_DIR)/%.o:\$(SRC_DIR)/%.c
	@echo + CC $<
	@mkdir -p \$(OBJ_DIR)
	@\$(CC) \$(CFLAGS) -c -o \$@ $<

clean:
	@rm -f \$(OBJS) \$(TARGETS) \$(addsuffix .exe,\$(TARGETS))

" > $1
}

fill_srcs()
{
echo "
#ifndef __MAIN_H__
#define _MAIN_H__

#include \"a.h\"
//#include \"b.h\"
//#include \"c.h\"

#endif // __MAIN_H__
" > $1/main.h
echo "
#include <stdio.h>
#include \"main.h\"

void test()
{
	// f();
}

int main()
{
	test();
	return 0;
}
" > $1/main.c

echo "
#ifndef __A_H__
#define __A_H__
#include <stdio.h>
#endif // __A_H__
void f();
" > $1/a.h
echo "
#include \"a.h\"
void f()
{
	// just do it;
}
" > $1/a.c
}

#############################################################

PWD=`pwd`
if [ -e $name ]; then
    echo " -> 无法创建目录 \"$name\": 文件已存在"                           
	echo " -> $pwd/$name"
	exit 1
fi 
`mkdir $name`
PWD=$PWD/$name
`mkdir $PWD/srcs`
`mkdir $PWD/srcs/Debug`
`mkdir $PWD/objs`
#`mkdir $PWD/libs`
#`mkdir $PWD/bulid`
`touch $PWD/Makefile`
fill_makefile $PWD/Makefile $1
fill_srcs $PWD/srcs $1



