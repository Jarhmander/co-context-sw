TARGET := test_float
SRC    := main.c \
		  ../../src/platforms/x86_64-systemv-abi/context_impl.c

INC    := $(addprefix -I, ../../include/ ../../include/platforms/x86_64-systemv-abi)

all: ${TARGET}

test: ${TARGET}
	./${TARGET}

clean:
	rm -f ${TARGET} ${OBJS}

OBJS   := $(notdir $(SRC:%.c=%.o))

${TARGET}: ${OBJS}
	gcc $^ -o $@ -lm

define build
$2 : $1
	gcc -c $$< -o $$@ ${INC} -O3
endef

.PHONY: all clean test

$(foreach s,${SRC},\
	$(eval $(call build,$s,$(notdir $(s:%.c=%.o)))))
