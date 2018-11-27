//
//  main.cpp
//  CSAPP
//
//  Created by ShannonChen on 2018/11/26.
//  Copyright © 2018年 ShannonChen. All rights reserved.
//

#include <iostream>
#include <stdint.h>

typedef unsigned char *byte_pointer;


/**
 打印十六进制形式的字节表示

 @param start 该变量的起始地址
 @param len 该数据类型的字节大小
 */
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    
    printf("\n");
}


/**
 打印 int 类型变量的字节表示

 @param x <#x description#>
 */
void show_int(int x) {
    show_bytes((byte_pointer)&x, sizeof(int));
}



/**
 打印 float 类型变量的字节表示

 @param x <#x description#>
 */
void show_float(float x) {
    show_bytes((byte_pointer)&x, sizeof(float));
}

/**
 打印 指针 类型变量的字节表示
 
 @param x <#x description#>
 */
void show_pointer(void *x) {
    show_bytes((byte_pointer)&x, sizeof(void *));
}


/**
 打印 字符串 类型变量的字节表示

 @param str 字符串
 @param len <#len description#>
 */
void show_string(char *str, size_t len) {
    show_bytes((byte_pointer)str, len);
}

/**
 测试用例

 @param val <#val description#>
 */
void test_show_bytes(int val) {
    int ival = val;
    float fval = (float)ival; // 强转成 float
    int *pval = &ival; // 获取变量地址
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void show_negative_short(short x) {

    short mx = -x;
    
    show_bytes((byte_pointer)&x, sizeof(short));
    show_bytes((byte_pointer)&mx, sizeof(short));
}

void test_type_cast() {
    short int v = -12345;
    unsigned short uv = (unsigned short)v;
    printf("v = %d, uv = %u\n", v, uv);
    
    show_bytes((byte_pointer)&v, sizeof(short int));
    show_bytes((byte_pointer)&uv, sizeof(unsigned short));
}

void test_bit_extension() {
    short sx = -12345;
    unsigned short usx = sx;
    int x = sx;
    unsigned ux = usx;
    
    printf("sx = %d:\t", sx);
    show_bytes((byte_pointer)&sx, sizeof(short));
    printf("usx = %u:\t", usx);
    show_bytes((byte_pointer)&usx, sizeof(unsigned short));
    printf("x = %d:\t", x);
    show_bytes((byte_pointer)&x, sizeof(int));
    printf("ux = %u:\t", ux);
    show_bytes((byte_pointer)&ux, sizeof(unsigned));
}

int main(int argc, const char * argv[]) {
    

    std::cout << "Hello, World!\n";
    
    test_show_bytes(12345);
//
//    char str[] = "12345";
//    show_string(str, 6);
//
//
//    short x = 12345;
//    show_negative_short(x);
//
//    test_type_cast();
    
//    test_bit_extension();
    
//    unsigned int a = 0;
//    printf("%u\n", (a - 1));
//    if (a - 1 > 0) {
//        printf("a is bigger than 1.\n");
//    }
    
    
    return 0;
}
