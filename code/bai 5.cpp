#include <stdio.h>


void hoanDoi(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


void hoanVi(int a[], int left, int right) {
    if (left == right) {
        for (int i = 0; i <= right; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    else {
        for (int i = left; i <= right; i++) {
            hoanDoi(&a[left], &a[i]); 
            hoanVi(a, left + 1, right);
            hoanDoi(&a[left], &a[i]); 
        }
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua day: ");
    scanf_s("%d", &n);

    int a[50];
    printf("Nhap cac phan tu cua day: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }

    printf("Cac hoan vi cua day la:\n");
    hoanVi(a, 0, n - 1);

    return 0;
}