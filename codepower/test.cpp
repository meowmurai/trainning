#include<stdio.h>

using namespace std;

int main(){
    char s[20];
    fgets(s,19,stdin);
    printf("%s",s);
    return 0;
}