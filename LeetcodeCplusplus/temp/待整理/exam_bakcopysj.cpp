#include <stdio.h>
#include <string.h>
#define LMOVE(m, n) ((m) << (n))
#define RMOVE(m, n) ((m) >> (n))
int main()
{
    int j;
    int a[4] = {0}, b[4] = {0}, c[4] = {0};
    int k;
    scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
    scanf("%d.%d.%d.%d", &b[0], &b[1], &b[2], &b[3]);
    scanf("%d", &k);

    unsigned int addr;
    addr = LMOVE(0xffffffff, 32 - k);
    c[0] = RMOVE(addr, 24);
    c[1] = RMOVE(addr, 16) & 0xff;
    c[2] = RMOVE(addr, 8) & 0xff;
    c[3] = addr & 0xff;
    int d[4] = {0}, e[4] = {0};
    int flag = 0;
    for (int i = 0; i < 4; i++)
    {
        d[i] = a[i] & b[i];
        e[i] = a[i] & c[i];
    }
    if (flag == 0)
    {
        if (0 == memcmp(d, e, 4))
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }
    return 0;
}