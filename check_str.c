#include <stdio.h>
#include <string.h>

int getStr(char * in, char s[1000]);
int comp(char s[1000], int l);

int main(void)
{
    char s[1000];
    int l = getStr("Nhap chuoi: ", s);
    printf("%s\n", s);
    printf(comp(s, l) ? "co doi xung\n" : "KHONG doi xung\n");
}

int getStr(char * in, char s[1000])
{
    printf("%s", in); scanf("%s", s);
    return strlen(s);
}

int comp(char s[1000], int l)
{
    int mid = l / 2;
    for (int i = 0; i < mid; i++)
    {
        if ((int)s[i] != (int)s[l - 1 -i]) return 0;
    }
    return 1;
}