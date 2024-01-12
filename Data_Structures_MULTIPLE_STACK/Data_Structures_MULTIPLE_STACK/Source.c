//a program to keep multiple stacks using an array of stack ptr
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELM 10


//structure of nodes in each stack
struct stackNode {
	int data;
	struct stackNode* next;
};


//structure of stack arr
typedef struct {
	struct stackNode* top;
}STACK;


STACK *stackArray[MAX_ELM];


//function to push a certain stack
void pushStack(STACK* stack, int data) {
    struct stackNode* newNode = (struct stackNode*)malloc(sizeof(struct stackNode));

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
   
}

//function that determines the location for the push operation, with the help of the stack index.
void pushToSpecificStack(int index, int data) {
    if (index < 0 || index >= MAX_ELM) {
        printf("invalid index!\n");
        return;
    }

    STACK* targetStack = stackArray[index];
    pushStack(targetStack, data);
}

//function to pop
void pop(STACK* targetStack) {
    if (targetStack == NULL || targetStack->top==NULL) printf("stack is already null");
    
    struct stackNode* temp =targetStack->top;
    targetStack->top = temp->next;
    free(temp);
    
}


//function that determines the location for the pop operation, with the help of the stack index.
void remoFromSpecificStack(int index) {
    if (index<0 || index>MAX_ELM) {
        printf("invalid index! \n\n");
    }

    STACK* targetStack = stackArray[index];
    pop(targetStack);
}


void printStacks() {
    for (int i = 0; i < MAX_ELM; ++i) {
        printf("Stack %d: ", i);
        struct stackNode* current = stackArray[i]->top;

        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }

    printf("\n\n\n\n");
}

int main() {

    //initialize the stack array 
    for (int i = 0; i < MAX_ELM; ++i) {
        stackArray[i] = (STACK*)malloc(sizeof(STACK));
        stackArray[i]->top = NULL;
    }

    pushToSpecificStack(0, 34);
    pushToSpecificStack(0, 54);
    pushToSpecificStack(0, 3);
    pushToSpecificStack(0, 6);
    pushToSpecificStack(1, 56);
    pushToSpecificStack(1, 13);
    pushToSpecificStack(6, 99);
    pushToSpecificStack(9, 67);

    printStacks();
    remoFromSpecificStack(0);
    printStacks();
}