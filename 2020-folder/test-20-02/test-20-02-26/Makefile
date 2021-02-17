SRC=$(wildcard *.c)
OBJ=$(patsubst %.c, %.o, $(SRC))
BIN=out

CFLAGS=-g

$(BIN):$(OBJ)
	gcc $^ -o $@

%.o:%.c
	gcc -c $(CFLAGS) $^ -o $@

.PHONY:clean
clean:
	rm $(BIN) $(OBJ)
	

