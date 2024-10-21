#include <stdio.h>

#define SIZE 50

void copy_from_to(int *from,int from_size, int *to, int *to_size);

int main(){

    int size_arr1;
    int size_arr2;
    int arr1[SIZE];
    int arr2[SIZE];
    int i;

    printf("specify array size(<=50): ");
    scanf("%d", &size_arr1);

    printf("write array elements: \n");
    for (i = 0; i < size_arr1; ++i)
        scanf("%d", arr1+i);


    copy_from_to(arr1, size_arr1, arr2, &size_arr2);
    printf("values of copied array: \n");
    for (i = 0; i < size_arr2; i++)
    {
        printf("%d\n", *(arr2+i));
    }
    




    return 0;

}

void copy_from_to(int *from, int from_size, int *to, int *to_size)
{
    int i;

    for (i = 0; i < from_size; ++i)
    {
        *(to+i) = *(from+i);
    }
    *to_size = i;


    

}
