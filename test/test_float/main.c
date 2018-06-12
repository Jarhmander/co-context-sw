#include "context.h"
#include "context_impl.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ctx_t c1, c2;

void fn(void *);


double piap(int k)
{
    return (4./(8.*k+1) - 2./(8.*k+4) - 1./(8.*k+5) - 1./(8.*k+6))/pow(16,k);
}

int main(void)
{
    double res;
    double *ires;
    unsigned stack[1024];

    init_ctx(&c2, fn, stack, sizeof stack);

    ires = jmp_ctx(&c1, &c2, &res);
    printf("res=%g\n", *ires);
    *ires += piap(2);
    jmp_ctx(&c1, &c2, ires);
    printf("res=%g\n", res);
    return 0;
}

void bar(double *d)
{
    double f = piap(1);
    jmp_ctx(&c2, &c1, &f);
    *d += f + piap(2);
    jmp_ctx(&c2, &c1, NULL);
}

void fn(void *data)
{
    double *d = data;
    *d = 0;
    *d += piap(0);
    bar(d);
}

