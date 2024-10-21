#include <stdio.h>

void double_value(int *s);

int main (){

    int a = 10;
    int *p;
    p = &a;

    printf("%d\n", *p);
    double_value(p);
    printf("%d\n", *p);


    return 0;
}

void double_value(int *s){
    *s *= 2;

}