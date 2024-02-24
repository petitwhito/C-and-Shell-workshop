#include <stdio.h>
void modif(int i)
{
    i = 0;
}
int main(void)
{
    int i;
    i = 42;

    modif(i);

    if (i == 42)
        puts("Not modified");
    else
        puts("Modified");

    return 0;
}
