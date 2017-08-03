/**
 * @file context.h
 * @desc Basic cooperative context switch
 *
 * @author James-Adam Renquinha Henri
 * 
 * @copyright see LICENSE
 */
#ifndef CONTEXT_H
#define CONTEXT_H
//--------------------------------------------------------------------------------------------------
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Context structure.
 */
struct ctx_t;

/**
 * @brief Initialize a context.
 *
 * @param init          context to initialize
 * @param fn            function to run in the context
 * @param stack_bottom  bottom of the stack to be used by the context
 * @param sz            size of the allocated stack
 *
 * @note Do not pass any NULL arguments.
 *
 * @note It is necessary to call this function to set up a context to run a function.
 *
 * @note The function `fn` must not return.
 */
void init_ctx(struct ctx_t *init, void (*fn)(void *), void *stack_bottom, size_t sz);

/**
 * @brief Jump into a context.
 *
 * First, save the current context (if `cur` is not NULL), then restore the `next` context (if
 * `next` is not NULL). `next` is either a previously saved context, or a newly initialized context
 * created with `init_ctx`.
 *
 * @param cur   current context, can be NULL
 * @param next  next context, can be NULL
 * @param arg   argument to pass to the context
 *
 * @return argument passed to the `jmp_ctx` call that resume control to the current `jmp_ctx` call.
 *
 * @note If `next` is NULL, act like `setjmp`. If `cur` is NULL, act like `longjmp`. If both are
 * NULL, only return `arg` (pretty useless).
 */
void *jmp_ctx(struct ctx_t *cur, struct ctx_t *next, void *arg);

#ifdef __cplusplus
}
#endif

//--------------------------------------------------------------------------------------------------
#endif // CONTEXT_H
