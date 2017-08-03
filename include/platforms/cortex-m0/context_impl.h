/**
 * @file context_impl.h
 * @desc Implementation details for ARM Cortex-M0/Cortex-M0+
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
    void (*lr)(void *);
    uint32_t r4, r5, r6, r7;
    uint32_t r8, r9, r10, r11;
    void *sp;
};

//--------------------------------------------------------------------------------------------------
#endif // CONTEXT_IMPL_H
