#include <stdio.h>

int main()
{
    int a[] = {5, 9, 7, 6, 4, 0, 2, 3, 8, 1};

    int length = 10;

    for (int i = 0; i < length; i++)
    {
        int max = i;
        for (int j = i; j < length; j++){
            if(a[j] < a[max])
            {
                max = j;
            }
        }
        if (a[i] > a[max])
        {
            int temp = a[max];
            a[max] = a[i];
            a[i] = temp;
        }
    }

    for (int i = 0; i < length; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}