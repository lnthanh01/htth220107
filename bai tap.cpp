#include <stdio.h>
#define MAX 50

int queue[MAX];
int front = -1, rear = -1;

// Ham kiem tra hang doi rong
int isEmpty() {
    return front == -1;
}

// Ham kiem tra hang doi day
int isFull() {
    return rear == MAX - 1;
}

// Ham them phan tu vao hang doi
void enqueue(int x) {
    if (isFull()) {
        printf("Hang doi day! Khong the them.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = x;
    printf("Da them %d vao hang doi.\n", x);
}

// Ham xoa phan tu trong hang doi
void dequeue() {
    if (isEmpty()) {
        printf("Hang doi rong! Khong the xoa.\n");
        return;
    }
    printf("Da xoa %d khoi hang doi.\n", queue[front]);
    if (front == rear) {
        front = rear = -1; // Hang doi rong sau khi xoa
    } else {
        front++;
    }
}

// Ham hien thi hang doi
void display() {
    if (isEmpty()) {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Cac phan tu trong hang doi: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Ham tinh tong cac phan tu trong hang doi
void tinhTong() {
    if (isEmpty()) {
        printf("Hang doi rong. Tong = 0\n");
        return;
    }
    int sum = 0;
    for (int i = front; i <= rear; i++) {
        sum += queue[i];
    }
    printf("Tong cac phan tu trong hang doi: %d\n", sum);
}

// --- Main ---
int main() {
    int chon, x;

    do {
        printf("\n--- MENU QUEUE ---\n");
        printf("1. Them phan tu (enqueue)\n");
        printf("2. Xoa phan tu (dequeue)\n");
        printf("3. Hien thi hang doi\n");
        printf("4. Tinh tong cac phan tu\n");
        printf("5. Kiem tra rong\n");
        printf("6. Kiem tra day\n");
        printf("7. Thoat\n");
        printf("Chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                printf("Nhap gia tri x: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                tinhTong();
                break;
            case 5:
                if (isEmpty())
                    printf("Hang doi dang rong.\n");
                else
                    printf("Hang doi khong rong.\n");
                break;
            case 6:
                if (isFull())
                    printf("Hang doi da day.\n");
                else
                    printf("Hang doi chua day.\n");
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (chon != 7);

    return 0;
}

