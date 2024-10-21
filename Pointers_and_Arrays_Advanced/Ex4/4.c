#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_ascending(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int compare_descending(const void *a, const void *b) {
    return strcmp(*(const char **)b, *(const char **)a);
}

void sort_strings(char *arr[], int size_str, int (*compare)(const void *, const void *)) {
    qsort(arr, size_str, sizeof(char *), compare);
}

void print_array(char *arr[], int size_str) {
    for (int i = 0; i < size_str; i++)
        printf("%s\n", arr[i]);
}

int main() {
    char *strings[] = {
        "banana",
        "apple",
        "orange",
        "grape",
        "cherry",
        "ananas"
    };
    int size_str = sizeof(strings) / sizeof(strings[0]);

    printf("Original array:\n");
    print_array(strings, size_str);

    char choice;
    printf("Sort in ascending order (a) or descending order (d)? ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case 'a':
        sort_strings(strings, size_str, compare_ascending);
        printf("\nSorted array (ascending):\n");
        break;
    case 'd':
        sort_strings(strings, size_str, compare_descending);
        printf("\nSorted array (descending):\n");
        break;
    default:
        printf("Invalid choice. Please enter 'a' or 'd'.\n");
        return 1;
    }

    print_array(strings, size_str);
    return 0;
}