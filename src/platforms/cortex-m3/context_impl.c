/**
 * @file context_impl.c
 * @desc Implementation details for ARM Cortex-M3/Cortex-M4 (without FPU)
 *
 * @author James-Adam Renquinha Henri
 *
 * @copyright see LICENSE
 */
#include "context.h"
#include "platforms/cortex-m3/context_impl.h"
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
"   cmp   r0,  #0           \n"
"   beq   jmp_ctx_load      \n"
"   stmia r0!, {r4-r11, lr} \n"
"   str   sp,  [r0]         \n"

"jmp_ctx_load:              \n"
"   mov   r0,  r2           \n"
"   cmp   r1,  #0           \n"
"   bne   jmp_ctx_do_load   \n"
"   bx    lr                \n"
"jmp_ctx_do_load:           \n"
"   ldr   sp,  [r1, #36]    \n"
"   ldmia r1,  {r4-r11, pc} \n"
);
