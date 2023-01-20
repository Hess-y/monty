#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define EXIT_FAILURE 1

typedef struct stack {
    int value;
    struct stack *next;
} stack;

stack *head = NULL;

void push(int value) {
    stack *new_node = malloc(sizeof(stack));
    new_node->value = value;
    new_node->next = head;
    head = new_node;
}

void pall() {
    stack *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

int main(int argc, char **argv) {
    if (argc == 2 && strcmp(argv[1], "pall") == 0) {
        pall();
    } else if (argc == 3 && strcmp(argv[1], "push") == 0) {
        int i = 0;
        while (argv[2][i]) {
            if (!isdigit(argv[2][i])) {
                fprintf(stderr, "L%d: usage: push integer\n", __LINE__);
                exit(EXIT_FAILURE);
            }
            i++;
        }
        push(atoi(argv[2]));
    } else {
        fprintf(stderr, "L%d: usage: push integer or pall\n", __LINE__);
        exit(EXIT_FAILURE);
    }
    return 0;
}

