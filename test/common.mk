CFLAGS:=-I../../include -I../../include/platforms/x86_64 -Wall -O2

.PHONY: all test clean

all: ${TARGET}

test:
	./${TARGET}

clean:
	rm -rf $(wildcard *.o) ${TARGET}

${TARGET} : ${TARGET}.o context.o

context.o : ../../src/platforms/x86_64/context_impl.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
