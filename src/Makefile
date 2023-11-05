# 컴파일러 지정
CXX = g++

# 컴파일 옵션 및 플래그
CXXFLAGS = -I/usr/local/include/mongocxx/v_noabi -I/usr/local/include/bsoncxx/v_noabi -I/usr/include/blocksci/external
LDFLAGS = -L/usr/local/lib -L/usr/lib/x86_64-linux-gnu -lmongocxx -lbsoncxx -lblocksci -lboost_system -lcrypto -lssl -lcpprest

# 소스 파일 및 목적 파일
SRCS = $(wildcard *.cpp) 
OBJS = $(SRCS:.cpp=.o)

# 실행 파일 이름
TARGET = info-server

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)
