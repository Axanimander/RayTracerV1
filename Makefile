src = $(wildcard *.cpp)
obj = $(src:.cpp .h=.o)
target = Rayt
CC = g++
CXXFLAGS = -g -Wall  -lm -lSDL2 -O3

$(target): $(obj)
	$(CC) -o  $@ $^ $(CXXFLAGS)

.PHONY: clean
