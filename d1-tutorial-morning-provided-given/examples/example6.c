#include <stdio.h>

int main(void)
{
    int a = 15;
    int b = a / 2;

    printf("%d\n", b);
    printf("%3d\n", b); // Padding with (3 - 'nb_of_digits_of_b') spaces
    printf("%03d\n", b); // Padding with '0's

    float c = 15.3;
    float d = c / 3;

    printf("%.2f\n", d); // 2 characters after point
    printf("%5.2f\n", d); // Padding until 5 characters, 2 characters after point

    return 0;
}
