#include <stdio.h>

int main()
{

    int a, b, n, result = 0;
    ;
    char c;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {

        scanf("%d%c%d", &a, &c, &b);
        result = a + b;
        arr[i] = result;
        //    printf("%d",result);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}