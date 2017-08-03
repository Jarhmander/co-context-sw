#include "context.h"
#include "context_impl.h"
#include <stdio.h>
#include <stdlib.h>

static void test_fn(void *);

struct ctx_t ctx, my_ctx;

int main(void)
{
    uint64_t buf[1024];

    init_ctx(&ctx, test_fn, buf, sizeof buf);

    uintptr_t p = (uintptr_t)0x1000;

    do {
        printf("main: %p\n", (void *)p);
        p = (uintptr_t)jmp_ctx(&my_ctx, &ctx, (void *)(p + 1));
    } while (p);

    puts("finished without dying!");
}

void test_fn(void *arg)
{
    uintptr_t p = (uintptr_t)arg;

    while (p < 0x1004) {
        printf("test_fn: %p\n", (void *)p);
        p = (uintptr_t)jmp_ctx(&ctx, &my_ctx, (void *)(p + 1));
    }
    jmp_ctx(&ctx, &my_ctx, 0);
}
