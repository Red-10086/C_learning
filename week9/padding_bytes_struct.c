#include <stdio.h>

struct Unaligned {
    char c_1;
    int i_1;
    char c_2;
    double d_1;
    char c_3;
    int i_2;
    int i_3;
    double d_2;
    double d_3;
    char c_4;
    char c_5;
    char c_6;
    int i_4;
    int i_5;
    int i_6;
    double d_4;
    double d_5;
    double d_6;
    char c_7;
    char c_8;
    char c_9;
    char c_10;
    int i_7;
    int i_8;
    int i_9;
    int i_10;
    double d_7;
    double d_8;
    double d_9;
    double d_10;
};

int main(void) 
{
    struct Unaligned u;
    printf("&c_1 = %p\n", &u.c_1);
    printf("&i_1 = %p\n", &u.i_1);
    printf("&d_1 = %p\n\n", &u.d_1);

    printf("&c_2 = %p\n", &u.c_2);
    printf("&c_3 = %p\n", &u.c_3);
    printf("&i_2 = %p\n", &u.i_2);
    printf("&i_3 = %p\n", &u.i_3);
    printf("&d_2 = %p\n", &u.d_2);
    printf("&d_3 = %p\n\n", &u.d_3);

    printf("&c_4 = %p\n", &u.c_4);
    printf("&c_5 = %p\n", &u.c_5);
    printf("&c_6 = %p\n", &u.c_6);
    printf("&i_4 = %p\n", &u.i_4);
    printf("&i_5 = %p\n", &u.i_5);
    printf("&i_6 = %p\n", &u.i_6);
    printf("&d_4 = %p\n", &u.d_4);
    printf("&d_5 = %p\n", &u.d_5);
    printf("&d_6 = %p\n\n", &u.d_6);
    
    printf("&c_7 = %p\n", &u.c_7);
    printf("&c_8 = %p\n", &u.c_8);
    printf("&c_9 = %p\n", &u.c_9);
    printf("&c_10 = %p\n", &u.c_10);
    printf("&i_7 = %p\n", &u.i_7);
    printf("&i_8 = %p\n", &u.i_8);
    printf("&i_9 = %p\n", &u.i_9);
    printf("&i_10 = %p\n", &u.i_10);
    printf("&d_7 = %p\n", &u.d_7);
    printf("&d_8 = %p\n", &u.d_8);
    printf("&d_9 = %p\n", &u.d_9);
    printf("&d_10 = %p\n\n", &u.d_10);
    
    return 0;
}