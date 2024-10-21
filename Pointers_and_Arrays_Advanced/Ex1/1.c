#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 100
#define NAME_LENGTH 50

int main(){
    char **names = malloc(MAX_NAMES * sizeof(char *));
    for (int i = 0; i < MAX_NAMES; i++)
        names[i] = malloc(NAME_LENGTH * sizeof(char));


    int count = 0;

    printf("Enter names (type 'end' to finish):\n");

    while (count < MAX_NAMES){
        printf("Name %d: ", count + 1);
        fgets(names[count], NAME_LENGTH, stdin);
        names[count][strcspn(names[count], "\n")] = '\0';

        if (strcmp(names[count], "end") == 0)
            break;

        count++;
    }

    printf("\nDuplicate names:\n");
    int foundDuplicate = 0;
    int printed[MAX_NAMES] = {0};

    for (int i = 0; i < count; i++){
        if (printed[i])
            continue;

        int isDuplicate = 0;
        for (int j = i + 1; j < count; j++){
            if (strcmp(names[i], names[j]) == 0){
                isDuplicate = 1;
                printed[j] = 1;
            }
        }
        if (isDuplicate){
            printf("%s\n", names[i]);
            foundDuplicate = 1;
        }
    }

    if (!foundDuplicate)
        printf("No duplicate names found.\n");

    for (int i = 0; i < MAX_NAMES; i++)
        free(names[i]);
    free(names);

    return 0;
}
