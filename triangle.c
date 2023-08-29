#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
    float cb = 0;
    float at = 0;
    float res = 0;
    cb = 4.5;
    at = 10.25;
    res = round(cb * at / 2);

    printf("A área do triangulo é: %.3f", res);
    return 0;                       


}