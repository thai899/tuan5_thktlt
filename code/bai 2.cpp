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
int timKiemNhiPhan(int a[], int x, int left, int right) {
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (a[mid] == x)
        return mid;
    if (a[mid] > x)
        return timKiemNhiPhan(a, x, left, mid - 1);
    return timKiemNhiPhan(a, x, mid + 1, right);
}
int maxChan(int a[], int n) {
    if (n == 0)
        return INT_MIN;
    int max = maxChan(a, n - 1);
    if (a[n - 1] % 2 == 0 && a[n - 1] > max)
        return a[n - 1];
    return max;
}
int tongLe(int a[], int n) {
    if (n == 0)
        return 0;
    if (a[n - 1] % 2 != 0)
        return a[n - 1] + tongLe(a, n - 1);
    return tongLe(a, n - 1);
}
void xuatViTriLe(int a[], int n, int index) {
    if (index >= n)
        return;
    if (index % 2 != 0)
        printf("%d ", a[index]);
    xuatViTriLe(a, n, index + 1);
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
        case 2:
        {
            int n;
            printf("Nhap so luong phan tu cua mang: ");
            scanf_s("%d", &n);
            int a[50];
            nhapMangNgauNhien(a, n);
            printf("Mang ngau nhien: ");
            xuatMang(a, n);
            int x;
            printf("Nhap gia tri can tim: ");
            scanf_s("%d", &x);
            int index = timKiemNhiPhan(a, x, 0, n - 1);
            if (index != -1)
                printf("Tim thay %d o vi tri %d\n", x, index);
            else
                printf("Khong tim thay %d\n", x);
        }break;
        case 3 :
        {
            int n;
            printf("Nhap so luong phan tu cua mang: ");
            scanf_s("%d", &n);
            int a[50];
            nhapMangNgauNhien(a, n);
            printf("Mang ngau nhien: ");
            xuatMang(a, n);
            int max = maxChan(a, n);
            if (max != INT_MIN)
                printf("Gia tri chan lon nhat: %d\n", max);
            else
                printf("Khong co gia tri chan nao\n");
        }break;
        case 4 :
        {
            int n;
            printf("Nhap so luong phan tu cua mang: ");
            scanf_s("%d", &n);
            int a[50];
            nhapMangNgauNhien(a, n);
            printf("Mang ngau nhien: ");
            xuatMang(a, n);
            printf("Tong cac phan tu le: %d\n", tongLe(a, n));
        }break;
        case 5:
        {
            int n;
            printf("Nhap so luong phan tu cua mang: ");
            scanf_s("%d", &n);
            int a[50];
            nhapMangNgauNhien(a, n);
            printf("Mang ngau nhien: ");
            xuatMang(a, n);
            printf("Cac so o vi tri le: ");
            xuatViTriLe(a, n, 0);
            printf("\n");
        }break;
        }
    } while (lc <= 5);
    return 0;
}