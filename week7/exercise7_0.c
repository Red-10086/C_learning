#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// 通用函数：打印指定位数的二进制（带前缀说明）
void print_bits(int num, int bits, const char* label) {
    printf("%-10s: ", label);
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf(" (%d位)\n", bits);
}

// 三码对比演示（8位示例，可扩展到32位）
void show_three_codes(int num) {
    int bits = 8; // 8位演示（实际C中int为32/64位，但8位足够看原理）
    
    // 1. 原码：符号位+绝对值二进制
    int abs_num = abs(num);
    int sign_bit = (num < 0) ? 1 : 0;
    int original = (sign_bit << (bits-1)) | abs_num;
    
    // 2. 反码：原码符号位不变，其余取反（负数）
    int complement = original;
    if (num < 0) {
        complement = (sign_bit << (bits-1)) | (~abs_num & ((1 << (bits-1)) - 1));
    }
    
    // 3. 补码：反码+1（负数）或原码（正数）
    int two_complement = complement;
    if (num < 0) {
        two_complement = complement + 1;
    }
    
    // 打印三码
    print_bits(original, bits, "原码");
    print_bits(complement, bits, "反码");
    print_bits(two_complement, bits, "补码");
    
    // 验证：补码 = 计算机实际存储
    printf("计算机存储（补码）: %d\n", num);
}

int main() {
    int a = 2;    // 正数
    int b = -2;   // 负数
    
    printf("正数 2 的三码:\n");
    show_three_codes(a);
    
    printf("\n负数 -2 的三码:\n");
    show_three_codes(b);
    
    return 0;
}