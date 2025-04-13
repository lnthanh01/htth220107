#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Khai b�o bi?n Stack
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Kh?i t?o stack
void init(Stack *s) {
    s->top = -1;
}

// Ki?m tra stack r?ng
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Ki?m tra stack d?y
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Th�m ph?n t? v�o stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack d?y! Kh�ng th? th�m ph?n t?.\n");
        return;
    }
    s->data[++s->top] = value;
    printf("�� th�m %d v�o stack.\n", value);
}

// L?y ph?n t? kh?i stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack r?ng! Kh�ng th? l?y ph?n t?.\n");
        return -1;
    }
    return s->data[s->top--];
}

// Xem ph?n t? tr�n d?nh stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack r?ng!\n");
        return -1;
    }
    return s->data[s->top];
}

// Hi?n th? Stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack r?ng!\n");
        return;
    }
    printf("C�c ph?n t? trong stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// T�nh t?ng c�c ph?n t? trong stack
int sum(Stack *s) {
    int total = 0;
    for (int i = 0; i <= s->top; i++) {
        total += s->data[i];
    }
    return total;
}

// T�m v? tr� c?a gi� tr? trong stack
int findPosition(Stack *s, int value) {
    for (int i = 0; i <= s->top; i++) {
        if (s->data[i] == value) {
            return i + 1; // V? tr� b?t d?u t? 1 (thay v� 0)
        }
    }
    return -1; // N?u kh�ng t�m th?y
}

int main() {
    Stack s;
    init(&s);

    int choice, value;
    do {
        printf("\n--- Menu Stack ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Hi?n th?\n5. T�nh t?ng c�c ph?n t?\n6. T�m v? tr� c?a gi� tr?\n0. Tho�t\n");
        printf("Ch?n thao t�c: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nh?p gi� tr? c?n th�m: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1)
                    printf("�� l?y ra: %d\n", value);
                break;
            case 3:
                value = peek(&s);
                if (value != -1)
                    printf("Ph?n t? tr�n c�ng l�: %d\n", value);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                printf("T?ng c�c ph?n t? trong stack: %d\n", sum(&s));
                break;
            case 6:
                printf("Nh?p gi� tr? c?n t�m: ");
                scanf("%d", &value);
                int position = findPosition(&s, value);
                if (position != -1)
                    printf("Gi� tr? %d ? v? tr� %d trong stack.\n", value, position);
                else
                    printf("Gi� tr? %d kh�ng t?n t?i trong stack.\n", value);
                break;
            case 0:
                printf("Tho�t chuong tr�nh.\n");
                break;
            default:
                printf("L?a ch?n kh�ng h?p l?!\n");
        }
    } while (choice != 0);

    return 0;
}

