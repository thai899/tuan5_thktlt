#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void menu()
{
    printf("\n1.Tong phan tu chan cua mang a");
    printf("\n2.Tim kiem x theo a");
    printf("\n3.Tim max chan trong a");
    printf("\n4.Tong le trong a");
    printf("\n5.Xuat cac so le");
}
void nhapMangNgauNhien(int a[], int n) {
    srand(time(NULL)); 
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100; 
    }
}

void xuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int tongChan(int a[], int n) {
    if (n == 0)
        return 0;
    if (a[n - 1] % 2 == 0)
        return a[n - 1] + tongChan(a, n - 1);
    return tongChan(a, n - 1);
}
int main() {
    int lc;
    do {
        menu();
        printf("\nMoi ban chon ");
        scanf_s("%d", &lc);
        switch (lc)
        {
        case 1 :
        {
            int n;
            printf("Nhap so luong phan tu cua mang: ");
            scanf_s("%d", &n);
            int a[50];
            nhapMangNgauNhien(a, n);
            printf("Mang ngau nhien: ");
            xuatMang(a, n);
            printf("Tong cac phan tu chan: %d\n", tongChan(a, n));
        }break;
        }
    } while (lc <= 5);
}