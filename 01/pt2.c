#include <stdio.h>
#include <stdbool.h>

void maximize(long long *max, long long num){
    if(num > max[2]){
        max[2] = num;
    }
    if(max[2] > max[1]){
        num = max[1];
        max[1] = max[2];
        max[2] = num;
    }
    if(max[1] > max[0]){
        num = max[0];
        max[0] = max[1];
        max[1] = num;
    }
}

int main(){
    char c;
    long long cal=0;
    long long sum=0;
    long long max[3]={0,0,0};
    bool prev_digit = true;
    while((c = getc(stdin)) != EOF){
        c -= '0';
        if(0 <= c && c <= 9){
            cal *= 10;
            cal += c;
            prev_digit = true;
        }else{
            if(prev_digit){
                sum += cal;
                cal = 0;
            }else{
                maximize(max, sum);
                sum = 0;
            }
            prev_digit = false;
        }
    }
    printf("%d", max[1] + max[2] + max[0]);
}