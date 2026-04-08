#include <stdio.h>
#include <cpuid.h>
int main() {
   unsigned int eax, ebx, ecx, edx;
   // 调用 cpuid，EAX=7, ECX=0 获取扩展特性
   __cpuid_count(7, 0, eax, ebx, ecx, edx);
   if ( ( ( (unsigned long long)edx >> 24 ) & 1 ) ) {
       printf("CPU 支持 AMX-BF16\n");
   }
   if ( ( ( (unsigned long long)edx >> 25 ) & 1 ) ) {
       printf("CPU 支持 AMX-TILE\n");
   }
   if ( ( ( (unsigned long long)edx >> 26 ) & 1 ) ) {
       printf("CPU 支持 AMX-INT8\n");
   }
   return 0;
}