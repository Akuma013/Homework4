#include <stdio.h>

int sum_of_array(int arr[], unsigned int size_of_arr);

int main(){
    
    int arr[] = {11,-1,7,5,3};    
    unsigned int size_arr = sizeof(arr) / sizeof(arr[0]);
    int sum;
    
    sum = sum_of_array(arr, size_arr);
    
    // printf("%d\n", *p);
    printf("Sum of the array: %d\n", sum);
    printf("AVG of the array: %.2f\n", (float)sum/size_arr);



    return 0;
}

int sum_of_array(int *arr, unsigned int size_of_arr){
    int sum = 0;
    int i;

    for (i = 0; i < size_of_arr; i++)
        sum += *(arr+i);

    return sum;
}