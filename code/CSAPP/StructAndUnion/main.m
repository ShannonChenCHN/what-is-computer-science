//
//  main.m
//  StructAndUnion
//
//  Created by ShannonChen on 2019/1/12.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#import <Foundation/Foundation.h>


struct SCRect {
    long x;
    long y;
    unsigned long width;
    unsigned long height;
    unsigned color;
};

long area(struct SCRect *rp) {
    return rp->width * rp->height;
}


unsigned long double2bits(double d) {
    union {
        double d;
        unsigned long u;
    } temp;
    
    temp.d = d;
    return temp.u;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        struct SCRect r;
        r.x = 0;
        r.y = 0;
        r.width = 100;
        r.height = 100;
        r.color = 0xFF00FF;
        
        struct SCRect r1 = {0, 10, 200, 150, 0xFF00FF};
        
        NSLog(@"%li, %li", area(&r), area(&r1));
        
        double d = 3.0;
        unsigned long u = double2bits(d);
    }
    return 0;
}
