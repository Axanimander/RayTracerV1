src = $(wildcard *.cpp)
obj = $(src:.cpp .h=.o)
target = Rayt
CC = g++
CXXFLAGS = -g -Wall  -lm -lSDL2 -D_GLIBCXX_DEBUG -D_LIBCPP_DEBUG -O3

$(target): $(obj)
	$(CC) -o  $@ $^ $(CXXFLAGS)

clean: $(target)
	rm $^
