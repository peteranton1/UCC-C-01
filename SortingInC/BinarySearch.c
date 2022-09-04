#include <stdio.h>

int binary_search(int a[], int e, int l, int r);

int main()
{
    int sorted[]   = {1,2,3,4,5,6,7,8,9,10,11,12,13};

    int elements[] = {12,3,14};
    int elements_length = 3;

    for (int i = 0; i < elements_length; i++) 
    {
        int e = elements[i];
        int index = binary_search(sorted, e, 0, 12);
        printf("The index of %d: %d\n", e, index);
    }

    return 0;
}

int binary_search(int a[], int e, int l, int r)
{
    int mid = l + (r - l) / 2 ;

    if (l > r) return EOF;

    if (a[mid] == e)
    {
        return mid;
    }
    else if (a[mid] > e)
    {
        return binary_search(a, e, l, mid - 1);
    }
    else
    {
        return binary_search(a, e, mid + 1, r);
    }

    return 0;
}