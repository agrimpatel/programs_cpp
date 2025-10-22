#include <stdio.h>

int absolute(int a)
{
    if (a < 0)
    {
        return -a;
    }
    else
    {
        return a;
    }
}

int main()
{
    int p;
    scanf("%d", &p);

    int a[p], b[p];

    for (int i = 0; i < p; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }

    int result = 0;

    for (int i = 0; i < p; i++)
    {
        for (int j = i + 1; j < p; j++)
        {
            result += absolute(a[j] - a[i]) + absolute(b[j] - b[i]);
        }
    }

    printf("%d\n", result);
    return 0;
}
