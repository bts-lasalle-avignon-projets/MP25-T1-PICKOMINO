TARGET = pickomino.out
MAIN = main

DOSSIER_INCLUDE = ./src
DOSSIER_SRC = ./src
DOSSIER_TESTS = ./tests

HEADERS := $(wildcard $(DOSSIER_INCLUDE)/*.h)
SRC := $(wildcard $(DOSSIER_SRC)/*.cpp)
OBJ := $(strip $(patsubst %.cpp, %.o, $(SRC)))

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
	$(RM) $(DOSSIER_SRC)/*.o $(DOSSIER_SRC)/*.*~

cleanall:
	$(RM) $(DOSSIER_SRC)/*.o $(DOSSIER_SRC)/*.*~ $(TARGET)
