#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LINES 10
#define MAX_LINES 1000

int main(int argc, char *argv[]){
    int n = DEFAULT_LINES;
    char *lines[MAX_LINES];
    int count = 0;
    char buffer[1024];

    if (argc > 1 && argv[1][0] == '-'){
        n = atoi(argv[1] + 1);
        if (n <= 0){
            printf("Error: Invalid number of lines\n");
            return 1;
        }
    }

    while (fgets(buffer, sizeof(buffer), stdin)){
        if (count < MAX_LINES){
            lines[count] = strdup(buffer);
            count++;
        }
        else
        {
            free(lines[0]);
            for (int i = 1; i < MAX_LINES; i++)
                lines[i - 1] = lines[i];

            lines[MAX_LINES - 1] = strdup(buffer);
        }
    }

    int start = count < n ? 0 : count - n;
    for (int i = start; i < count; i++){
        printf("%s", lines[i]);
        free(lines[i]);
    }

    return 0;
}
