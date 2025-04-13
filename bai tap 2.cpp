#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[100];
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Khoi tao hang doi
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Kiem tra hang doi rong
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Kiem tra hang doi day
int isFull(Queue* q) {
    return 0; // vi cap phat dong, hang doi khong bao gio "day"
}

// Them phan tu cuoi hang doi
void enqueue(Queue* q, const char* tenSP) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        return;
    }

    strcpy(newNode->name, tenSP);
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Da them '%s' vao hang doi.\n", tenSP);
}

// Xoa phan tu dau tien
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong! Khong the xoa.\n");
        return;
    }

    Node* temp = q->front;
    printf("Da xoa '%s' khoi hang doi.\n", temp->name);
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Hien thi phan tu
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong.\n");
        return;
    }

    printf("Danh sach san pham trong hang doi:\n");
    Node* temp = q->front;
    while (temp != NULL) {
        printf("- %s\n", temp->name);
        temp = temp->next;
    }
}

// --- Main ---
int main() {
    Queue q;
    initQueue(&q);

    int chon;
    char ten[100];

    do {
        printf("\n--- MENU QUEUE (Danh sach lien ket) ---\n");
        printf("1. Them san pham (enqueue)\n");
        printf("2. Xoa san pham (dequeue)\n");
        printf("3. Hien thi hang doi\n");
        printf("4. Kiem tra rong\n");
        printf("5. Kiem tra day\n");
        printf("6. Thoat\n");
        printf("Chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                printf("Nhap ten san pham: ");
                scanf(" %[^\n]", ten);
                enqueue(&q, ten);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf(isEmpty(&q) ? "Hang doi dang rong.\n" : "Hang doi khong rong.\n");
                break;
            case 5:
                printf(isFull(&q) ? "Hang doi day.\n" : "Hang doi chua day (cap phat dong).\n");
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (chon != 6);

    return 0;
}


