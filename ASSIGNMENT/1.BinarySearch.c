#include <stdio.h>

int binarySearch(int a[], int n, int key, int *temp)
{
    // i represents low and j represents high
    int i = 0, j = n - 1;
    int mid;

    *temp = 0;

    while (i <= j)
    {
        mid = i + (j - i) / 2;
        (*temp)++;

        if (a[mid] == key)
            return mid;

        if (key < a[mid])
            j = mid - 1;
        else
            i = mid + 1;
    }

    return -1;
}

int main()
{
    int a[100];
    int n, key, position, temp;
    int k, valid = 1;

    printf("Number of employees: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Number of employees is invalid.\n");
        return 0;
    }

    printf("Enter the IDs of the employees in ascending order:\n");

    for (k = 0; k < n; k++)
    {
        scanf("%d", &a[k]);

        if (k > 0 && a[k] <= a[k - 1])
            valid = 0;
    }

    if (valid == 0)
    {
        printf("Invalid: Employee IDs must be in ascending order.\n");
        return 0;
    }

    printf("Enter ID to search: ");
    scanf("%d", &key);

    position = binarySearch(a, n, key, &temp);

    if (position == -1)
    {
        printf("\nID %d is not found.\n", key);
    }
    else
    {
        printf("\nID %d is found at position %d.\n", key, position + 1);
    }

    printf("Number of comparisons = %d\n", temp);

    return 0;
}



