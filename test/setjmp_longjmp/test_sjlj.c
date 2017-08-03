#include <stdlib.h>
#include <stdio.h>
#include "context.h"
#include "context_impl.h"

static void fn(struct ctx_t *c);

int main(void)
{
    struct ctx_t ctx;

    uintptr_t p;

    if ((p = (uintptr_t)jmp_ctx(&ctx, NULL, NULL)) == 0) {
        puts("Trying fn");
        fn(&ctx);
    } else {
        printf("Caught exception: %lu\n", p);
    }
}

void fn(struct ctx_t *c)
{
    uintptr_t exception = 42;

    printf("Throwing exception %lu\n", exception);
    jmp_ctx(NULL, c, (void *)exception);
    puts("This line shouldn't be reached.");
}
