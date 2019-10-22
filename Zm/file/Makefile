# 编译方式
CC = g++
CXXFLAGS := -Wall -O3
# -w的意思是关闭编译时的警告
# -Wall选项意思是编译后显示所有警告
# -W选项只显示编译器认为会出现错误的警告

# 头文件和lib路径
INC_ROOT = include
INCLUDE_PATH = -I../../Array -I../inc/ -I../
LIB_ROOT = lib

# 目标文件
OBJS = fileOperation.o

# 目标静态库名
LIB = libfileOperation.a

# 目标文文件存放位置
LIB_BIN_DIR = ../libs/
LIB_INC_DIR= ../inc/

# 依赖库名称
#JSON_LIB = -lm

all:$(LIB)

# 生成.o 文件 # $< 依赖文件 # $@ 目标文件
%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INCLUDE_PATH) $(LIB_PATH) $(INC)

#$(LIB) : $(OBJS)
libfileOperation.a : fileOperation.o
	rm -f $@
	ar cr $@ $<
	rm -f $<
	mv $(LIB) $(LIB_BIN_DIR) 
	cp fileOperation.h $(LIB_INC_DIR) 

tags :
	ctags -R *

# 删除中间文件
clean:
	rm -f $(OBJS) $(TARGETS) $(LIB)
