#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include "Stack.h"

//////////////////////////////////////////////////
Stack_t *createStack(void) {
    Stack_t *stack = malloc(sizeof(Stack_t));
    if (stack == NULL) return NULL;
    stack->list = createDLList();
    if (stack->list == NULL) {
        free(stack);
        return NULL;
    }
    
    return stack;
}

bool destroyStack(Stack_t *stack, STACK_OPTION_e option) {
    // Block illegal parameters.
    if (stack == NULL) return false;
    
    if (option == STACK_OPTION_WITH_ELEMENT) {
        destroyDLList(stack->list, DLL_OPTION_WITH_ELEMENT);
    }
    else {
        destroyDLList(stack->list, DLL_OPTION_NONE);
    }
    free(stack);
    
    return true;
}

bool pushStack(Stack_t *stack, void *element) {
    // Block illegal parameters.
    if (stack == NULL) return false;
    if (element == NULL) return false;
    
    return insertAtHeadOnDLList(stack->list, element);
}

void *popStack(Stack_t *stack) {
    // Block illegal parameters.
    if (stack == NULL) return NULL;
    
    return pullHeadOnDLList(stack->list);
}

void *peekStack(Stack_t *stack) {
    // Block illegal parameters.
    if (stack == NULL) return NULL;
    if (stack->list == NULL) return NULL;
    if (stack->list->head == NULL) return NULL;
    
    return stack->list->head->element;
}

bool isEmptyStack(Stack_t *stack) {
    if (stack == NULL) return true;
    return isEmptyDLList(stack->list);
}
