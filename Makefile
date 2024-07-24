.PHONY: clean # 伪目标

# 自定义环境变量
CXX = g++ # 指定C++编译器

CXXFLAGS = -I include # 指定头文件目录
CPPFILES = $(shell find src -name "*.cpp") # 搜索所有的源文件
OBJS = $(CPPFILES:.cpp=.o) # 所有的目标文件
TARGET = main # 最终生成目标

RM = -rm -f # 删除方式

# 项目构建方式
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET)
