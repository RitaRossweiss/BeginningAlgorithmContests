#include<stdio.h>
#include<math.h>
int main(){
    double n = 0;
    const double PI = acos(-1.0);
    scanf("%lf",&n);
    printf("%lf %lf",sin(n/180*PI),cos(n/180*PI));
    return 0;
}
//注意！这道题三角函数使用的是弧度而非角度！