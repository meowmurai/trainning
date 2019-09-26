#include<stdio.h>

int main(){
    int d,m,y;
    printf("Nhap vao ngay: ");
    scanf("%d",&d);
    printf("Nhap vao thang: ");
    scanf("%d",&m);
    printf("Nhap vao nam: ");
    scanf("%d",&y);

    printf("Ket qua: %02d/%02d/%02d",d,m,y);
    getchar();
    getchar();
    return 0;
}

