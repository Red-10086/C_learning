#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 类型标签
typedef enum { TYPE_INT, TYPE_DOUBLE, TYPE_STRING, TYPE_LONG } TypeTag;

// 标签联合
typedef struct {
    TypeTag tag;
    union {
        int i;
        double d;
        char s[64];
        long l;
    } data;
} Variant;

// 类型判断函数（简化版，替代正则）
TypeTag infer_type(const char *str) {
    char *end;
    strtol(str, &end, 10);
    if (*end == '\0') return TYPE_LONG;
    
    strtod(str, &end);
    if (*end == '\0') return TYPE_DOUBLE;
    
    return TYPE_STRING;
}

// 处理函数原型（函数指针数组）
typedef Variant (*HandlerFunc)(Variant);

// 具体处理函数示例
Variant handle_int(Variant v) {
    v.data.i *= 2;  // 示例：整数×2
    return v;
}

Variant handle_double(Variant v) {
    v.data.d += 1.0;  // 示例：浮点+1
    return v;
}

// 分派表
HandlerFunc handlers[] = {
    [TYPE_INT]    = handle_int,
    [TYPE_DOUBLE] = handle_double,
    // TYPE_STRING 和 TYPE_LONG 需补充
};

// 通用接口
Variant process(Variant v) {
    return handlers[v.tag](v);  // 函数指针分派
}

int main(void) {
    const char *inputs[] = {"123", "3.14", "Masaki", "70000"};
    
    for (int i = 0; i < 4; i++) {
        Variant v;
        v.tag = infer_type(inputs[i]);
        
        // 根据类型初始化 union
        if (v.tag == TYPE_LONG) v.data.l = atol(inputs[i]);
        else if (v.tag == TYPE_DOUBLE) v.data.d = atof(inputs[i]);
        else strncpy(v.data.s, inputs[i], 63);
        
        v = process(v);  // 通用接口调用
        
        // 根据标签输出
        if (v.tag == TYPE_LONG) printf("%ld\n", v.data.l);
        else if (v.tag == TYPE_DOUBLE) printf("%f\n", v.data.d);
        else printf("%s\n", v.data.s);
    }
    
    return 0;
}