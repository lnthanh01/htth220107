#include <stdio.h>
#include <stdlib.h>
#define MAX 100
//khai bao bien
typedef struct {
	int data[MAX];	
	int top;
} Stack;

//khoi tao stack
void init(Stack *s) {
	s->top = -1;
}

//kiem tra stack rong
int isEmpty(Stack *s) {
	return s->top == -1;
}
//kiem tra stack day
int isFull(Stack *s) {
	return s->top == MAX -1;
}
//them phan tu vao stack
void push(Stack *s, int value) {
	if (isFull(s)) {
		printf("stack day! Khong the them phan tu.\n");
		return;
	}
	s->data[++s->top] = value;
	printf("Da them %d vao stack.\n");
}
//lay phan tu khoi stack
int pop(Stack *s) {
	if (isEmpty(s)) {
		printf("Stack rong! khong the lay phan tu.\n");
		return -1;
	}
	return s ->data[s->top--];
}

// Xem phan tu tren dinh 
int peek(Stack *s) { 
	if (isEmpty(s)) {
	printf("Stack rong!\n"); return -1; 
	} 
	 
	return s->data[s->top]; 
} 
// Hien thi Stack 
void display (Stack *s) {
	if (isEmpty(s)) {
		printf("Stack rong!\n"); 
		return; 
	}
	printf("Cac phan tu trong stack: "); 
	for (int i = 0; i <= s->top; i++) {
		printf("%d ", s->data[i]); 
	} 
	printf("\n"); 
}
int main() {
	Stack s; 
	init(&s); 
	
	int choice, value; 
	do {
		printf("\n--- Menu Stack ---\n"); 
		printf("1. Push\n2. Pop\n3. Peek\n4. Hien thi\no. Thoat\n"); 
		printf("Chon thao tac: "); 
		scanf("%d", &choice);	
	do { 
		printf("\n--- Menu Stack ---\n"); 
		printf("1. Push\n2. Pop\n3. Peek\n4. Hien thi\no. Thoat\n"); 
		printf("Chon thao tac: "); 
		scanf("%d", &choice);

	}	
		switch (choice) {
			case 1:
				printf("Nhap gia tri can them" );
				scanf("%d", &value);
				push(&s, value);
				break;
			case 2:
				value = pop(&s);
				if (value != -1)
					printf("Da lay ra: %d\n, value");
				break;
			case 3:
				value = peek(&s);
				if (value !=-1)
					printf("Phan tu tren cung la: %d\n, value");
				break;
			case 4:
				display(&s);
				break;
			case 0:
				printf("Thoat chuong trinh.\n");
				break;
			default:
				printf("Lua chon khong hop le!\n");
										
		} 
	} while 0;
	
	return 0;

}

