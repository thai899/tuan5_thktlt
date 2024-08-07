#include <stdio.h>


int demChuSo(int n) {
    if (n == 0)
        return 0;
    return 1 + demChuSo(n / 10);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap so nguyen duong.\n");
    }
    else {
        printf("So luong chu so cua %d la: %d\n", n, demChuSo(n));
    }

    return 0;
}