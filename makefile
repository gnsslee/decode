CC = gcc
CFLAGS = -Wall -Werror -I. -Ibdmsgsecurity -Ibdmsgsecurity/bdmsgauth/model -Ibdmsgsecurity/util -Ibdmsgsecurity/smcrypt/cCalculate

# 定义静态库
LIB_NAME = libbdmsgsecurity.a
LIB_SRC_DIR = bdmsgsecurity
LIB_SOURCES := $(shell find $(LIB_SRC_DIR) -name '*.c')
LIB_OBJECTS = $(LIB_SOURCES:.c=.o)

# 定义可执行文件
EXEC_NAME = main
EXEC_SOURCES = MainActivity.c
EXEC_OBJECTS = $(EXEC_SOURCES:.c=.o)

# 查找 MainActivity.c 文件的实际位置
ifeq ($(wildcard MainActivity.c),)
    ifeq ($(wildcard decode/MainActivity.c),)
        EXEC_SOURCES = $(shell find . -name 'MainActivity.c' 2>/dev/null | head -1)
        ifeq ($(EXEC_SOURCES),)
            $(error Could not find MainActivity.c)
        endif
    else
        EXEC_SOURCES = decode/MainActivity.c
    endif
endif

# 构建静态库
$(LIB_NAME): $(LIB_OBJECTS)
	ar rcs $@ $^

# 构建可执行文件
$(EXEC_NAME): $(EXEC_OBJECTS) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $^ -L. -lbdmsgsecurity

# 编译源文件为目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(LIB_OBJECTS) $(EXEC_OBJECTS) $(LIB_NAME) $(EXEC_NAME)

# 默认目标
all: $(EXEC_NAME)