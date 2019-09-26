#include<stdio.h>

int main(){
    int d,m,y;
    printf("Nhap vao ngay, thang, nam dd-mm-yy: "); 
    scanf("%02d-%02d-%d",&d,&m,&y);
    printf("Ket qua: %02d/%02d/%d",d,m,y);
    
    getchar();
    getchar();
    return 0;
}
