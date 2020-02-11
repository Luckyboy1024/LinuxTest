SRC=$(wildcard *.c)                     # 把当前文件夹下所有的.c文件都写在变量 SRC 中，以空格分隔
OBJ=$(patsubst %.c, %.o, $(SRC))        # 将src中所有的.c文件名称中的.c以.o的名称形式写在对象 OBJ 中，以空格分隔，并没有生成任何.o文件
BIN=out                                 #

CFLAGS=-g

.PHONY:$(BIN)
$(BIN):$(OBJ)                           # 目标对象:依赖对象
    gcc $^ -o $@                        # gcc test.c -o out

%.o:%.c                                 # 目标对象:依赖对象
#	gcc -c $< -o $@                     # gcc -c test.c -o test.o
	gcc -c $(CFLAGS) $< -o $@			# gcc -c -g test.c -o test.o

.PHONY:clean                            # 伪目标
clean:                                  # make clean
	rm $(BIN) $(OBJ)                    # rm out test.o
