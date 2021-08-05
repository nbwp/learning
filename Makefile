#指定编译器

ARCH := 
ifeq ($(ARCH), arm)
CC := arm-none-linux-gnueabi-g++
else
CC := g++ 
endif
#gcc
#arm-none-linux-gnueabi-gcc

#工程路径指定
TOPDIR := $(shell pwd)
OBJDIR := $(TOPDIR)/obj
BINDIR := $(TOPDIR)/bin
#BIN := $(notdir $(TOPDIR))
HEADDIR := $(TOPDIR)/incl
LIBDIR := $(TOPDIR)/lib
#源文件目录
SUBDIR:= $(TOPDIR)/src

#搜索源文件下面子目录
SRCDIRS := $(shell find $(SUBDIR) -type d)

#迭代搜索c文件
#CXXSRCS := $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp))
CCSRCS := $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp))

#.o文件
#CXXOBJS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(CXXSRCS)))
CCOBJS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(CCSRCS)))
#一个test一个bin
BIN := $(patsubst %.cpp,$(BINDIR)/%,$(notdir $(CCSRCS)))
#依赖文件.d  .d文件里面存放的是 .o文件的依赖 包含.c文件 .h文件$(CXXOBJS) 
DEPS := $(patsubst %.o,%.d,$(CCOBJS))

#增加编译器搜索路径
VPATH = $(SRCDIRS):$(TOPDIR)
#编译选项
CFLAGS := -g -rdynamic -Wall $(patsubst %, -I%, $(HEADDIR))


LFLAG := -lpthread -lrt 
#$(CXXOBJS) 
all:CHECKDIR $(LIBS) $(BIN) $(CCOBJS)  PRINT
CHECKDIR:
#	@echo $(CCSRCS)
	@echo $(CCOBJS)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)
	@mkdir -p $(LIBDIR)

-include $(DEPS)
#$<规则中的第一个依赖 &@规则中的目标
#$(CXXOBJS)/%.o:%.cpp
#	@echo"Compiling $< == > $@"
#	$(CXX) $(CFLAGS) -c $< -o $@ -MMD -MF $(OBJDIR)/$*.d 
##################### .c/.cpp 目标




$(BIN):$(CCOBJS)
	$(CC) $< -o $@ $(CFLAGS) -L$(LIBDIR) $(LFLAG)



$(OBJDIR)/%.o:%.cpp
	@echo "Compiling $< ==> $@"
	$(CC) -c $^ -o $@ -MMD -MF $(OBJDIR)/$*.d -MP $(CFLAGS)


#$^规则中的所有依赖*
#$(BINDIR)/$(BIN):$(CXXOBJS)
#	$(CXX) -o &@ $^ $(LFLAG)

PRINT:
	@echo "Complie done"

.PHONY:clean
clean:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)
	rm -rf $(LIBDIR)