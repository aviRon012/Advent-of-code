#include <stdio.h>
#include <stdbool.h>

int main(){
    char c;
    long long cal=0;
    long long sum=0;
    long long max=0;
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
                if(sum > max){
                    max = sum;
                }
                sum = 0;
            }
            prev_digit = false;
        }
    }
    printf("%d", max);
}