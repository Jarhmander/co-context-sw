/**
 * @file context_impl.c
 * @desc Implementation details for ARM Cortex-M0/Cortex-M0+
 *
 * @author James-Adam Renquinha Henri
 *
 * @copyright see LICENSE
 */
#include "context.h"
#include "platforms/cortex-m0/context_impl.h"
//--------------------------------------------------------------------------------------------------

void init_ctx(struct ctx_t *init, void (*fn)(void *), void *stack_bottom, size_t sz)
{
    init->sp = (uint8_t *)stack_bottom + sz;
    init->lr = fn;
}

// void *jmp_ctx(struct ctx_t *cur, struct ctx_t *next, void *arg)
asm (
"   .globl jmp_ctx          \n"
"jmp_ctx:                   \n"
"   mov   r3,  lr           \n"
"   cmp   r0,  #0           \n"
"   beq   jmp_ctx_load      \n"
"   stmia r0!, {r3-r7}      \n"
"   mov   r3,  r8           \n"
"   mov   r4,  r9           \n"
"   mov   r5,  r10          \n"
"   mov   r6,  r11          \n"
"   mov   r7,  sp           \n"
"   stmia r0!, {r3-r7}      \n"

"jmp_ctx_load:              \n"
"   mov   r0,  r2           \n"
"   movs  r2,  r1           \n"
"   beq   jmp_ctx_ret       \n"
"   add   r2,  r2, #20      \n"
"   ldmia r2!, {r3-r7}      \n"
"   mov   r8,  r3           \n"
"   mov   r9,  r4           \n"
"   mov   r10, r5           \n"
"   mov   r11, r6           \n"
"   mov   sp,  r7           \n"
"   ldmia r1!, {r3-r7}      \n"
"   mov   lr,  r3           \n"

"jmp_ctx_ret:               \n"
"   bx    lr                \n"
);
