#Makefile of project 
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
ifeq ($(RELEASE),0)
	CFLAGS += -g
else 
	CFLAGS += -static -o3 -DNDEBUG
	LFLAGS += -static 
endif

## [args] 程序位数，32代表32程序，64代表64程序，其他默认，make BITS=32
ifeq ($(BITS),32)
	CFLAGS += -m32
	LFLAGS += -m32 
else 
	ifeq ($(BITS),64)
		CFLAGS += -m64
		LFLAGS += -m64 
	else 
	endif 
endif 

# Files to be compiled	
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)                        

time := $(shell date +%H:%M:%S) 

DEBUGS := $(DEBUG_DIR)/out-$(time)
TARGETS := ./all.out ./all.exe  

.PHONY: all clean

all:$(TARGETS)

$(TARGETS): $(OBJS)
	@echo + LD $@
	@$(LD) $(LFLAGS) -o $@ $^
	@mkdir -p $(DEBUG_DIR)
	@$(LD) $(LFLAGS) -o $(DEBUGS) $^
# $(OBJS): $(OBJ_DIR)/%.o

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@echo + CC $<
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS) $(TARGETS) $(addsuffix .exe,$(TARGETS))

