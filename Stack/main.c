#include <unistd.h>
//#define checkMemoryLeak

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include "Stack.h"

//////////////////////////////////////////////////
typedef struct Element {
    int value;
} Element_t;

//////////////////////////////////////////////////
void test(void);
Element_t *createElement(int value);
bool destroyElement(Element_t *element);

//////////////////////////////////////////////////
int main(int argc, const char * argv[]) {

#ifdef checkMemoryLeak
    while (true) {
        test();
        sleep(1);
    }
#else
    test();
#endif
    
    return EXIT_SUCCESS;
}

void test() {
    int numOfValues = 15;
    int count = 0;
    
    Stack_t *stack = createStack();
    
    printf("*** push [%s] ***\n", __func__);
    count = 0;
    for (int i=0; i<numOfValues; i++) {
        count++;
        Element_t *element = createElement(i);
        bool check = pushStack(stack, element);
        if (check) {
            printf("push #%4d : %10d\n", count, i);
        }
        else {
            printf("error [%s] : could not push value %d.\n", __func__, i);
            destroyElement(element);
        }
    }

    printf("*** peek [%s] ***\n", __func__);
    {
        Element_t *element = peekStack(stack);
        if (element != NULL) {
            printf("peek : %10d\n", element->value);
        }
        else {
            printf("error [%s] : could not peek value.\n", __func__);
        }
    }

    printf("*** pop [%s] ***\n", __func__);
    count = 0;
    while (!isEmptyStack(stack)) {
        count++;
        Element_t *element = popStack(stack);
        if (element != NULL) {
            printf("pop #%4d : %10d\n", count, element->value);
            destroyElement(element);
        }
        else {
            printf("error [%s] : could not pop value.\n", __func__);
        }
    }
    
    destroyStack(stack, STACK_OPTION_WITH_ELEMENT);
}

Element_t *createElement(int value) {
    Element_t *element = malloc(sizeof(Element_t));
    if (element == NULL) return NULL;
    element->value = value;
    return element;
}

bool destroyElement(Element_t *element) {
    // Block illegal parameters.
    if (element == NULL) return false;
    free(element);
    return true;
}

