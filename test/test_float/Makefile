TARGET := test
SRC    := main.c \
		  ../../src/platforms/x86_64/context_impl.c

INC    := $(addprefix -I, ../../include/ ../../include/platforms/x86_64)

all: ${TARGET}

clean:
	rm -f ${TARGET} ${OBJS}

OBJS   := $(notdir $(SRC:%.c=%.o))

${TARGET}: ${OBJS}
	gcc $^ -o $@ -lm

define build
$2 : $1
	gcc -c $$< -o $$@ ${INC} -O3
endef

$(foreach s,${SRC},\
	$(eval $(call build,$s,$(notdir $(s:%.c=%.o)))))
