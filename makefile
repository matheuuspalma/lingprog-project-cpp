#Rio de Janeiro - Federal University of Rio de Janeiro

#depedency file to build the current project code.

GPP = g++

#LDFLAGS = -pthread -lpthread -lrt

#ifdef debug
#CFLAGS = -Wall -Werror -std=c11 -D_POSIX_THREAD_SEMANTICS -DDEBUG
#else
#CFLAGS = -Wall -Werror -std=c11 -D_POSIX_THREAD_SEMANTICS
#endif

TARGET = avaliacao01

ALL = $(TARGET)

all: $(TARGET)

$(TARGET): main.cpp
	$(GPP) $(CFLAGS) -o $(TARGET) main.cpp turma.cpp $(LDFLAGS) -Iinclude

clean:
	$(RM) $(TARGET) *.o

