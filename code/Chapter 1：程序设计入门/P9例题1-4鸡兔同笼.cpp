//有两个地方有些同学可能不明白，在这里做下注释。

#include<stdio.h>
int main(){
    int a,b,n,m;
    scanf("%d%d",&n,&m);
    a = (4*n-m)/2; //这里是二元一次方程,通过消元得来的计算公式，这里能得出a的公式有很多种，有手就行，不用特意深究。
    b = n-a;
    if (m%2==1 || a<0 || b<0)//这里的m是指：鸡和兔所有腿的总数。鸡2条腿，兔子4条腿，所以无论有多少鸡或者兔子，m必定为偶数。
    {
        printf("没有正确答案\n");
    }else{
        printf("%d %d\n",a,b);
    }
    return 0;
}
