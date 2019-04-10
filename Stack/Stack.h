#ifndef Stack_h
#define Stack_h

#include <stdbool.h>
#include "DualyLinkedList.h"

//////////////////////////////////////////////////
typedef enum STACKOption {
    STACK_OPTION_NONE,
    STACK_OPTION_WITH_ELEMENT
} STACK_OPTION_e;

typedef struct Stack {
    DLL_t *list;
} Stack_t;

//////////////////////////////////////////////////
Stack_t *createStack(void);
bool destroyStack(Stack_t *stack, STACK_OPTION_e option);
bool pushStack(Stack_t *stack, void *element);
void *popStack(Stack_t *stack);
void *peekStack(Stack_t *stack);
bool isEmptyStack(Stack_t *stack);

#endif
