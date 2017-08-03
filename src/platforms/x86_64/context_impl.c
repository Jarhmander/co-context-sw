/**
 * @file context_impl.c
 * @desc Implementation details for x86_64
 *
 * @author James-Adam Renquinha Henri
 *
 * @copyright see LICENSE
 */
#include "context.h"
#include "platforms/x86_64/context_impl.h"
//--------------------------------------------------------------------------------------------------

void init_ctx(struct ctx_t *init, void (*fn)(void *), void *stack_bottom, size_t sz)
{
    init->sp = (uint8_t *)stack_bottom + sz - sizeof fn;
    init->pc = fn;
    init->mxcsr = 0x1F80;
}

// void *jmp_ctx(struct ctx_t *cur, struct ctx_t *next, void *arg)
asm (
"   .globl jmp_ctx              \n"
"jmp_ctx:                       \n"
"   movq    0(%rsp),  %r11      \n"
"   test    %rdi,     %rdi      \n"
"   jz      jmp_ctx_load        \n"
"   movq    %rbp,     0(%rdi)   \n"
"   movq    %rbx,     8(%rdi)   \n"
"   movq    %r12,     16(%rdi)  \n"
"   movq    %r13,     24(%rdi)  \n"
"   movq    %r14,     32(%rdi)  \n"
"   movq    %r15,     40(%rdi)  \n"
"   stmxcsr 48(%rdi)            \n"
"   movq    %r11,     56(%rdi)  \n"
"   movq    %rsp,     64(%rdi)  \n"

"jmp_ctx_load:                  \n"
"   test    %rsi,     %rsi      \n"
"   jz      jmp_ctx_ret         \n"
"   movq    0(%rsi),  %rbp      \n"
"   movq    8(%rsi),  %rbx      \n"
"   movq    16(%rsi), %r12      \n"
"   movq    24(%rsi), %r13      \n"
"   movq    32(%rsi), %r14      \n"
"   movq    40(%rsi), %r15      \n"
"   ldmxcsr 48(%rsi)            \n"
"   movq    56(%rsi), %r11      \n"
"   movq    64(%rsi), %rsp      \n"
"   movq    %r11,     0(%rsp)   \n"

"jmp_ctx_ret:                   \n"
"   movq    %rdx,     %rax      \n"
"   movq    %rdx,     %rdi      \n"

"   retq                        \n"
);
