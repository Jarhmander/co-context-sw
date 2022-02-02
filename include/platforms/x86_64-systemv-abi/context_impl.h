/**
 * @file context_impl.h
 * @desc Implementation details for x86_64
 *
 * @author James-Adam Renquinha Henri
 *
 * @copyright see LICENSE
 */
#ifndef CONTEXT_IMPL_H
#define CONTEXT_IMPL_H
//--------------------------------------------------------------------------------------------------
#include <stdint.h>

struct ctx_t
{
    uint64_t rbp, rbx;
    uint64_t r12, r13, r14, r15;
    uint64_t mxcsr;
    void (*pc)(void *);
    void *sp;
};

//--------------------------------------------------------------------------------------------------
#endif // CONTEXT_IMPL_H
