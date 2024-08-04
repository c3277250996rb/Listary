#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void delay_this(double i){
    usleep(i * 1000000); // 延时 1 秒
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s <TotalSeconds>\n", argv[0]);
        return 1;
    }

    double doubleValue = atof(argv[1]);
    while(doubleValue >= 0){
        delay_this(doubleValue);
        printf("doubleValue: %f\n", doubleValue);
        doubleValue -= 0.5;
    }

}