#include <windows.h>
#include <stdio.h>
void TextColor(int x)//X là mă màu
{
     HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
int main() {
    
    for (int i=1;i<=10;i++){
        for (int j=2;j<=10;j++){
            TextColor(j);
            printf("%d *%2.d =%2.d  ",j,i,i*j);
        }
        printf("\n");
    }
    TextColor(15);    
    return 0;
}