
	CROSS?= arm-hisiv100nptl-linux-

	ifeq ($(origin CROSS), undefined)
	export CROSS=
endif


GCC =  $(CROSS)gcc
GPP =  $(CROSS)g++
AR    = $(CROSS)ar

ROOT_DIR              = .
LIB_DIR                 :=  -L$(ROOT_DIR)/../lib
LIB_INC_DIR             :=  -I$(ROOT_DIR)/../include
INC_DIR                 :=  -I$(ROOT_DIR)/include
SRC_DIR                 :=  $(ROOT_DIR)/srcs
OBJ_DIR                  :=  $(ROOT_DIR)/objs
LIB_TAG_DIR             :=  $(ROOT_DIR)/libs
TEST_DIR             :=  $(ROOT_DIR)/test
#***源代码文件*********************
SRCS                 :=  $(shell find $(SRC_DIR) -name '*.c')
SRCS                 :=  $(sort $(SRCS))

TEST                 :=  $(shell find $(TEST_DIR) -name '*.c')
TEST                 :=  $(sort $(TEST))
#***目标文件*********************
OBJS                 :=  $(addprefix $(OBJ_DIR)/,$(notdir $(patsubst %.c,%.o,$(SRCS))))
LIBTARGET             :=  $(LIB_TAG_DIR)/libll.a
LIBTARGET_S             :=  $(LIB_TAG_DIR)/libll.so
TEST_TAG                 :=  $(TEST_DIR)/example
#***库文件*********************
LDFLAGS              := -lcurl
# Compiler flags, -g for debug, -c to make an object file
#
CFLAGS      = -c -g
CFLAGS_T =    -g
# Ar settings to build the library
ARFLAGS = -rcv

COMPILE =  $(GCC)  $(CFLAGS) "$<" -o $@  $(LDFLAGS) $(LIB_DIR) $(INC_DIR) $(LIB_INC_DIR)

all:$(OBJS)
    $(AR) $(ARFLAGS) -o $(LIBTARGET) $(OBJS)
    $(GCC) $(OBJS) -fpic -shared -o $(LIBTARGET_S)
    @echo "COMPILE all ok!"
    $(GCC)  -o $(TEST_TAG) $(TEST) $(INC_DIR) $(LIB_INC_DIR)  -L$(LIB_TAG_DIR) $(LDFLAGS) $(LIB_DIR) $(CFLAGS_T) $(LIBTARGET)
    @chmod 777 * -R

$(OBJS):$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
    @echo "$< = $@"
    $(GCC)  "$<" -o "$@"  $(INC_DIR) $(LIB_INC_DIR) $(CFLAGS)
    

clean:
    @echo "rm -f $(OBJS) $(LIBTARGET) $(LIBTARGET_S) $(TEST_TAG)"
    @rm -f $(OBJS) $(LIBTARGET) $(LIBTARGET) $(TEST_TAG)


