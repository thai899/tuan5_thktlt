#include <stdio.h>


int demChuSoChan(int n) {
    if (n == 0)
        return 0;
    int digit = n % 10; 
    if (digit % 2 == 0)
        return 1 + demChuSoChan(n / 10); 
    return demChuSoChan(n / 10); 
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap so nguyen duong.\n");
    }
    else {
        printf("So luong chu so chan cua %d la: %d\n", n, demChuSoChan(n));
    }

    return 0;
}