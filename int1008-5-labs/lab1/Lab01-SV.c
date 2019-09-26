#include<stdio.h>
#include<algorithm>
#include<string.h>

int main(){
    int d1,d2,m1,m2,y1,y2;
    char name1[100],name2[100];

    //using getchar to avoid \n character
    printf("nhap vao ho va ten: "); scanf("%100[^\n]s",&name1);
    getchar();
    printf("Nhap vao ngay, thang, nam dd-mm-yy: "); scanf("%d-%d-%d",&d1,&m1,&y1);
    getchar();
    printf("nhap vao ho va ten: "); scanf("%100[^\n]s",&name2);
    getchar();
    printf("Nhap vao ngay, thang, nam dd-mm-yy: "); scanf("%d-%d-%d",&d2,&m2,&y2);
    
    //calculate space between columns
    int m = std::max(strlen(name1),strlen(name2));
    if(m < strlen("Ho ten"))
        m = strlen("Ho ten");
    m+= 10;

    //%*s format to repeat a certain time of space
    printf("%d \n",m);
    printf("Ket qua:\n");
    printf("Ho ten%*sNgay sinh\n", m-strlen("Ho ten"), "");
    printf("%s%*s%02d/%02d/%d\n",  name1, m-strlen(name1), "", d1,m1,y1);
    printf("%s%*s%02d/%02d/%d\n",  name2, m-strlen(name2), "", d2,m2,y2);
    getchar();
    return 0;
}
