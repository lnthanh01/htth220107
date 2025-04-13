#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Khai báo bi?n Stack
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

// Thêm ph?n t? vào stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack d?y! Không th? thêm ph?n t?.\n");
        return;
    }
    s->data[++s->top] = value;
    printf("Ðã thêm %d vào stack.\n", value);
}

// L?y ph?n t? kh?i stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack r?ng! Không th? l?y ph?n t?.\n");
        return -1;
    }
    return s->data[s->top--];
}

// Xem ph?n t? trên d?nh stack
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
    printf("Các ph?n t? trong stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// Tính t?ng các ph?n t? trong stack
int sum(Stack *s) {
    int total = 0;
    for (int i = 0; i <= s->top; i++) {
        total += s->data[i];
    }
    return total;
}

// Tìm v? trí c?a giá tr? trong stack
int findPosition(Stack *s, int value) {
    for (int i = 0; i <= s->top; i++) {
        if (s->data[i] == value) {
            return i + 1; // V? trí b?t d?u t? 1 (thay vì 0)
        }
    }
    return -1; // N?u không tìm th?y
}

int main() {
    Stack s;
    init(&s);

    int choice, value;
    do {
        printf("\n--- Menu Stack ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Hi?n th?\n5. Tính t?ng các ph?n t?\n6. Tìm v? trí c?a giá tr?\n0. Thoát\n");
        printf("Ch?n thao tác: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nh?p giá tr? c?n thêm: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1)
                    printf("Ðã l?y ra: %d\n", value);
                break;
            case 3:
                value = peek(&s);
                if (value != -1)
                    printf("Ph?n t? trên cùng là: %d\n", value);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                printf("T?ng các ph?n t? trong stack: %d\n", sum(&s));
                break;
            case 6:
                printf("Nh?p giá tr? c?n tìm: ");
                scanf("%d", &value);
                int position = findPosition(&s, value);
                if (position != -1)
                    printf("Giá tr? %d ? v? trí %d trong stack.\n", value, position);
                else
                    printf("Giá tr? %d không t?n t?i trong stack.\n", value);
                break;
            case 0:
                printf("Thoát chuong trình.\n");
                break;
            default:
                printf("L?a ch?n không h?p l?!\n");
        }
    } while (choice != 0);

    return 0;
}

