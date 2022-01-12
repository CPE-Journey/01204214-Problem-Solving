#include <stdio.h>

void main()
{
    int a, n, i, count_t = 0, count_a = 0, count = 0;
    scanf("%i\n", &a);
    int arr0[a], arr1[a], arr2[a];
    //creat arr0
    for (i = 0; i < a; i++)
    {
        scanf("%i", &n);
        arr0[i] = n;
    }
    // printf("arr0\n");
    // for (i = 0; i < a; i++)
    // {
    //     printf("%i ", arr0[i]);
    // }
    // printf("\n");
    //creat arr1
    for (i = 0; i < a; i++)
    {
        if (arr0[i] == i+1)
        {
            arr1[arr0[i]-1] = -1;
            count_a++;
        }
        else
        {
            arr1[arr0[i]-1] = i+1;
        }
    }
    // printf("arr1\n");
    // for (i = 0; i < a; i++)
    // {
    //     printf("%i ", arr1[i]);
    // }
    // printf("\n");
    count_t++;
    // printf("fst ct = %i\n", count_t);
    while (count_a != a || count != 2000)
    {
        for (i = 0; i < a; i++)
        {
            if (arr1[i] == i+1)
            {
                arr2[i] = -1;
                count_a++;
                if (count_a == a)
                {
                    break;
                }
            }
            else
            {
                arr2[arr0[i]-1] = arr1[i];
            } 
        }
        // printf("arr2\n");
        // for (i = 0; i < a; i++)
        // {
        //     printf("%i ", arr2[i]);
        // }
        // printf("\n");
        count_t++;
        // printf("scn ct = %i\n", count_t);
        if (count_a == a || count == 2000)
        {
            break;
        }
        for (i = 0; i < a; i++)
        {
            if (arr2[i] == i+1)
            {
                arr1[i] = -1;
                count_a++;
                if (count_a == a)
                {
                    break;
                }
            }
            else
            {
                arr1[arr0[i]-1] = arr2[i];
            } 
        }
        count_t++;
        // printf("arr1\n");
        // for (i = 0; i < a; i++)
        // {
        //     printf("%i ", arr1[i]);
        // }
        // printf("\n");
        if (count_a == a)
        {
            break;
        }
        // printf("ca = %i\n", count_a);
        // printf("thi ct = %i\n", count_t);
    }
    printf("%i\n", count_t-1);
}