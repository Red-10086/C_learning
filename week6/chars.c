#include <stdio.h>


int main() {


    char strings[5][100];


    int i;


    printf("请输入5个字符串，每个字符串不超过99个字符：\n");


    for(i = 0; i < 5; i++) {


        printf("字符串 %d: ", i + 1);
        

        scanf("%99s", &strings[i]);
    }


    printf("你输入的字符串是：\n");


    for(i = 0; i < 5; i++) {


        printf("字符串 %d: %s\n", i + 1, strings[i]);


    }


    return 0;


}