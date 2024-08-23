TARGET = pickomino.out
MAIN = main

HEADERS := $(wildcard *.h)
SRC := $(wildcard *.cpp)
OBJ := $(strip $(patsubst %.cpp, %.o, $(wildcard *.cpp)))

CFLAGS=-std=c++11 -Wall -I.
LDFLAGS =
CXX=g++ $(CFLAGS) -c
LD=g++ -o
RM=rm -f

all: $(TARGET)

$(TARGET): $(OBJ)
	$(LD) $@ $(LDFLAGS) $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -o $@ $<

.PHONY: clean cleanall

clean:
	$(RM) *.o *.*~

cleanall:
	$(RM) *.o *.*~ $(TARGET)
