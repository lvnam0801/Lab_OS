CC 		= gcc 
CFLAGS 	= -std=c11 -Wall
SRCS 	= $(wildcard *.c)
HDRS 	= $(wildcard *.h)
OBJS 	= $(SRCS:.c=.o)
PRGA 	= ex1

$(PRGA)	: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -s

ex1.o	: ex1.c $(HDRS)
	$(CC) $(CFLAGS) $< -o $@ -c

%*.o	: %*.c %*.h
	$(CC) $(CFLAGS) $< -o $@ -c

.PHONY	: all build debug clean

all 	: $(PRGA)

build	: CFLAGS += -O2
build 	: all 

debug	: CFLAGS += -g
debug	: all

clean	: 
	echo "Clean up"
	@rm -f *.o