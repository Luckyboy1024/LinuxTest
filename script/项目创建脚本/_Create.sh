#!/bin/bash 
date=\test-20-$(date +%m)\-$(date +%d)

fill_makefile()
{    
echo "SRC=\$(wildcard *.c)  
OBJ=\$(patsubst %.c, %.o, \$(SRC))
BIN=out 

CFLAGS=-g

.PHONY:\$(BIN)
%:%.o 
	gcc $^ -o \$@    

%.o:%.c     
#   gcc -c $< -o \$@                     
	gcc -c \$(CFLAGS) $< -o \$@           

.PHONY:clean 
clean:  
	rm \$(BIN) \$(OBJ)                
    
" > $1

}
fill_makeFile()                                        
{
echo "SRC=\$(wildcard *.c)                     # 把当前文件夹下所有的.c文件都写在变量 SRC 中，以空格分隔
OBJ=\$(patsubst %.c, %.o, \$(SRC))        # 将src中所有的.c文件名称中的.c以.o的名称形式写在对象 OBJ 中，以空格分隔，并没有生成任何.o文件
BIN=out                                 #

CFLAGS=-g

.PHONY:\$(BIN)
\$(BIN):\$(OBJ)                           # 目标对象:依赖对象
	gcc $^ -o \$@    

%.o:%.c                                 # 目标对象:依赖对象
	gcc -c \$(CFLAGS) $< -o \$@           
#   gcc -c $< -o \$@                     

.PHONY:clean                            # 伪目标
clean:                                  # make clean
	rm \$(BIN) \$(OBJ)                

###################################################################################################################
" > $1
}

fill_head()
{
	echo "
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
	" > $1
}
fill_ch()
{
    echo "
#include \"main.h\"

int main()
{

    return 0;
}
" > $1
}

fill_c()
{
    echo "
#include <stdio.h>

int main()
{

    return 0;
}

" > $1
}

############### 开始创建工程 ################
PWD=`pwd`
`mkdir $date`
PWD=$PWD/$date
echo "$PWD"
# `mkdir $PWD/build`
# `touch $PWD/CMakeLists.txt`
# `mkdir $PWD/srcs`
# `touch $PWD/srcs/CMakeLists.txt`
# `mkdir $PWD/objs`
# `mkdir $PWD/libs`
# `mkdir $PWD/test`
# `mkdir $PWD/include`
# `mkdir $PWD/bin`
`mkdir $PWD/file`
`touch $PWD/Makefile`
`touch $PWD/test.c`
`touch $PWD/file/main.c`
`touch $PWD/file/main.h`
`touch $PWD/file/Makefile`
#fill_makefile $PWD/Makefile $1
fill_makefile $PWD/Makefile $1
fill_makeFile $PWD/file/Makefile $1
fill_head $PWD/file/main.h $1
fill_ch $PWD/file/main.c $1
fill_c $PWD/test.c $1


