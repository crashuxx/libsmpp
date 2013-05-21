# Environment 
MKDIR=mkdir
CXX=g++
CC=gcc
CXXFLAGS=-Iinclude -shared -Wall -Werror -fpic
LFLAGS=-Wl,-soname,libsmpp.so
CXXFILES=src/pdu.cpp src/tlv.cpp src/encoder.cpp src/decoder.cpp \
    src/pdu/bindtransmiter.cpp src/pdu/bindtransmiterresponse.cpp \
    src/pdu/unbind.cpp src/pdu/unbindresponse.cpp \
    src/pdu/genericnack.cpp \
    src/tlv/interfaceversion.cpp

OBJECTS=$(CXXFILES:.cpp=.o)
OUTPUT=bin/libsmpp.so

# build
build: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LFLAGS) $(CXXFILES) -o $(OUTPUT)

# clean
clean: 
	rm $(OBJECTS)

all: 

# build tests
build-tests: 

# run tests
test: test/main.o
	$(CXX) -Iinclude -Wl,-rpath=./ -Wall -Werror -Lbin -lsmpp -o bin/test test/main.cpp

# help
help:
 
