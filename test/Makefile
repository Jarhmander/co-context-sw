DIRS:=coroutine setjmp_longjmp test_float
CLEANDIRS:=$(addsuffix .clean,${DIRS})

.PHONY: all clean ${DIRS}

all: ${DIRS}

${DIRS}:
	${MAKE} -C $@ all test

clean : ${CLEANDIRS}

%.clean :
	${MAKE} -C $* clean
